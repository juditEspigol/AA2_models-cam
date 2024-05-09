#include "GameObject.h"

GameObject::GameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model,
	std::string vertexShader, std::string geometryShader, std::string fragmentShader, GLuint texture, const char* texturePath, bool hasTexture)
    : transform(Transform(_position, _rotation, _scale)), velocity(1.f), angularVelocity(100.f), scaleVelocity(100.f), isActive(true) {
    
    this->hasTexture = hasTexture;

    InitShader(vertexShader, geometryShader, fragmentShader);

    if (hasTexture)
    {
        CreateModel(texture, texturePath, model);
    }
    else
    {
        CreatePrimitive();
    }
}

GameObject::~GameObject()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void GameObject::CreateModel(GLuint texture, const char* texturePath, Model model)
{
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
}

void GameObject::CreatePrimitive()
{
    vertexs = {
        -0.2f, +0.2f, -0.2f, // 3
        +0.2f, +0.2f, -0.2f, // 2
        -0.2f, -0.2f, -0.2f, // 6
        +0.2f, -0.2f, -0.2f, // 7
        +0.2f, -0.2f, +0.2f, // 4
        +0.2f, +0.2f, -0.2f, // 2
        +0.2f, +0.2f, +0.2f, // 0
        -0.2f, +0.2f, -0.2f, // 3
        -0.2f, +0.2f, +0.2f, // 1
        -0.2f, -0.2f, -0.2f, // 6
        -0.2f, -0.2f, +0.2f, // 5
        +0.2f, -0.2f, +0.2f, // 4
        -0.2f, +0.2f, +0.2f, // 1
        +0.2f, +0.2f, +0.2f  // 0
    };

    numVertexs = vertexs.size() / 3;

    // Generate VAO/VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Define active VAO
    glBindVertexArray(VAO);

    // Define positions VBO as active
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // Active the attribute 0
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void GameObject::InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader)
{
    ShaderProgram shaderProgramCube;

    shaderProgramCube.LoadVertexShader(vertexShader);
    shaderProgramCube.LoadGeometryShader(geometryShader);
    shaderProgramCube.LoadFragmentShader(fragmentShader);

    shaderProgram = shaderProgramCube.CreateProgram(shaderProgramCube);
}

void GameObject::InitTexture(GLuint texture, const char* texturePath)
{
	textureInfo = stbi_load(texturePath, &width, &heigth, &nrChannels, 4);

	// Defnimos el canal de textura abierto
	glActiveTexture(texture);

	glGenTextures(1, &textureId);

	// Vinculo la textura con el canal de textura
	glBindTexture(GL_TEXTURE_2D, textureId);

	// Configurar textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Cargar textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureInfo);

	// Generar mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);

	// liberamos recursos
	stbi_image_free(textureInfo);
}

void GameObject::InitProgramValues()
{
    glUseProgram(shaderProgram);

    scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);
    translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
    rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.x);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));

    if(hasTexture)
        glUniform1i(glGetUniformLocation(shaderProgram, "textureSampler"), 0);

    glUniform2f(glGetUniformLocation(shaderProgram, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}

void GameObject::Render()
{
    //Vinculo su VAO para ser usado
    glBindVertexArray(this->VAO);

    InitProgramValues();

    // Dibujamos
    glDrawArrays(GL_TRIANGLES, 0, this->numVertexs);

    //Desvinculamos VAO
    glBindVertexArray(0);
}
