#include "Rock.h"
#include "GLManager.h"

Rock::Rock(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model) 
	: GameObject(_position, _rotation, _scale){
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

    if (transform.position != glm::vec3(0.f, 0.f, 0.f))
        translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);

    if (transform.rotation.y != 0)
        rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.y);

    if (transform.rotation.x != 0)
        rotationMatrixX = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.x);
}

void Rock::Render(int index)
{
    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    InitProgramValues(index);

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);
}

void Rock::InitProgramValues(int index)
{
    glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[4]);

    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "rotationMatrixX"), 1, GL_FALSE, glm::value_ptr(rotationMatrixX));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
    glUniform1i(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "textureSampler"), 0);

    glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[4], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
