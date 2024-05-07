#pragma once
#include <gtc/type_ptr.hpp>
#include <vector>

#include "Transform.h"
#include "GLManager.h"

class GameObject
{
protected: 

	bool isActive;

	Transform transform;
	float velocity; 
	float angularVelocity;
	float scaleVelocity;

	std::vector<GLfloat> vertexs;
	unsigned int numVertexs;
	GLuint VAO;
	GLuint VBO;

public:

	GameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
		: transform(Transform(_position, _rotation, _scale)), velocity(1.f), angularVelocity(100.f), scaleVelocity(100.f), isActive(true) 
	{};
	~GameObject();

	virtual void InitProgramValues() = 0;

	virtual void Update(float _dt) = 0;
	virtual void Render() = 0;

	// GETTERS AND SETTERS
	inline bool GetIsActive() const { return isActive; }
	inline void SetIsActive(const bool _value) { isActive = _value; }

	inline std::vector<GLfloat> GetVertexs() const { return vertexs; }

	inline Transform GetTransform() const { return transform; }

	inline float GetVelocity() const { return velocity; }
	inline void AddVelocity(const float _value) { velocity += _value; }

	inline float GetAngularVelocity() const { return angularVelocity; }
	inline void SetAngularVelocity(const float _value) { angularVelocity += _value; }

	inline float GetScaleVelocity() const { return scaleVelocity; }
	inline void SetScaleVelocity(const float _value) { scaleVelocity += _value; }
};