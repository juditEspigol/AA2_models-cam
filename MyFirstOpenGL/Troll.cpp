#include "Troll.h"
#include "GLManager.h"

Troll::Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, unsigned int _indexProgram, Model _model) 
	: GameObject(_position, _rotation, _scale, _indexProgram)
{
    //// SHADER PROGRAM
    CreateShaderProgram(); 

    //// GAME OBJECT THINGS

    //Almaceno la cantidad de vertices que habra
    this->numVertexs = _model.vertexs.size() / 3;

    //Generamos VAO/VBO
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->uvVBO);

    //Defino el VAO creado como activo
    glBindVertexArray(this->VAO);

    //Defino el VBO de las posiciones como activo, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, _model.vertexs.size() * sizeof(float), _model.vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //Defino el VBO de las cordenadas de, le paso los datos y lo configuro
    glBindBuffer(GL_ARRAY_BUFFER, this->uvVBO);
    glBufferData(GL_ARRAY_BUFFER, _model.uvs.size() * sizeof(float), _model.uvs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    //Activamos el atributo 0 (posiciones por defecto)
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //Desvinculamos VAO y VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
 
}
void Troll::InitProgramValues()
{
    glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram]);

    scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);
    translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
    rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.y);

    glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);

    glUniform1i(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "textureSampler"), 0);

    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
}

void Troll::Update(float _dt)
{
}
void Troll::Render()
{
    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);
}

void Troll::CreateShaderProgram()
{
    ShaderProgram shaderProgramGreyTroll;

    shaderProgramGreyTroll.LoadVertexShader("VS_Camera.glsl");
    shaderProgramGreyTroll.LoadGeometryShader("GS_Camera.glsl");
    shaderProgramGreyTroll.LoadFragmentShader("TrollFragmentShaderGrey.glsl");
    SHADERPROGRAM_MANAGER.compiledPrograms.push_back(shaderProgramGreyTroll.CreateProgram(shaderProgramGreyTroll));

}
