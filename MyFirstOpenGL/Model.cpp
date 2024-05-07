#include "Model.h"

Model::Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals)
{
	this->vertexs = vertexs;
	this->uvs = uvs;
	this->normals = normals;
}
