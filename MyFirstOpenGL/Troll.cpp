#include "Troll.h"
#include "GLManager.h"

Troll::Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model,
    std::string vertexShader, std::string geometryShader, std::string fragmentShader, GLuint texture, const char* texturePath)
	: GameObject(_position, _rotation, _scale)
{

    InitShader(vertexShader, geometryShader, fragmentShader);
    InitTexture(texture, texturePath);

    //Almaceno la cantidad de vertices que habra
    this->numVertexs = model.vertexs.size() / 3;

    //Generamos VAO/VBO
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->uvVBO);

    //Defino el VAO creado como activo
    glBindVertexArray(this->VAO);

    //Defino el VBO de las posiciones como activo, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, model.vertexs.size() * sizeof(float), model.vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //Defino el VBO de las cordenadas de, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->uvVBO);
    glBufferData(GL_ARRAY_BUFFER, model.uvs.size() * sizeof(float), model.uvs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    //Activamos el atributo 0 (posiciones por defecto)
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //Desvinculamos VAO y VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);
    translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
    rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.x);     
}

void Troll::Render(int index)
{
    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    InitProgramValues(index);

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);
}

void Troll::InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader)
{
    ShaderProgram shaderProgramCube;

    shaderProgramCube.LoadVertexShader(vertexShader);
    shaderProgramCube.LoadGeometryShader(geometryShader);
    shaderProgramCube.LoadFragmentShader(fragmentShader);

    shaderProgram = shaderProgramCube.CreateProgram(shaderProgramCube);
}

void Troll::InitProgramValues(int index)
{
    glUseProgram(shaderProgram);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
    glUniform1i(glGetUniformLocation(shaderProgram, "textureSampler"), 0);

    glUniform2f(glGetUniformLocation(shaderProgram, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
