#include "Troll.h"
#include "GLManager.h"

Troll::Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, unsigned int _indexProgram, Model _model) 
	: GameObject(_position, _rotation, _scale, _indexProgram)
{
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

    scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);

    if (transform.position != glm::vec3(0.f, 0.f, 0.f))
        translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
        
    if (transform.rotation.y != 0)
        rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.y);

    if (transform.rotation.x != 0)
        rotationMatrixX = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.x);
      
}
void Troll::InitProgramValues()
{
    glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[0]);

    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[0], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[0], "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[0], "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
    glUniform1i(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "textureSampler"), 0);

    glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[0], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Troll::Update(float _dt)
{

}
void Troll::Render()
{
    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    InitProgramValues();

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);
}