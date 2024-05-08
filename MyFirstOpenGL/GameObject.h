#pragma once
#include <GL/glew.h>
#include <gtc/type_ptr.hpp>
#include <vector>
#include <stb_image.h>
#include "GLManager.h"

#include "Transform.h"
#include "MatrixUtilities.h"
#include "TimeManager.h"
#include "ShaderProgram.h"
#include "Model.h"

class GameObject
{
protected: 

	Transform transform;

	float velocity; 
	float angularVelocity;
	float scaleVelocity;

	bool isActive;

	unsigned int numVertexs;

	std::vector<GLfloat> vertexs;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	GLuint shaderProgram;

	GLuint VAO;
	GLuint VBO;
	GLuint uvVBO;

	GLuint textureId;
	int width, heigth, nrChannels;
	unsigned char* textureInfo;

	bool hasTexture;

public:

	GameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model,
		std::string vertexShader, std::string geometryShader, std::string fragmentShader, GLuint texture, const char* texturePath, bool hasTexture);

	~GameObject();

	virtual void CreateModel(GLuint texture, const char* texturePath, Model model);
	virtual void CreatePrimitive();

	virtual void InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader);
	virtual void InitTexture(GLuint texture, const char* texturePath);
	virtual void InitProgramValues();
	
	virtual void Render();

	inline std::vector<GLfloat> GetVertexs() const { return vertexs; }

	inline Transform GetTransform() const { return transform; }

	inline float GetVelocity() const { return velocity; }
	inline void AddVelocity(const float _value) { velocity += _value; }

	inline float GetAngularVelocity() const { return angularVelocity; }
	inline void SetAngularVelocity(const float _value) { angularVelocity += _value; }

	inline float GetScaleVelocity() const { return scaleVelocity; }
	inline void SetScaleVelocity(const float _value) { scaleVelocity += _value; }

	inline bool GetIsActive() const { return isActive; }
	inline void SetIsActive(const bool _value) { isActive = _value; }


};