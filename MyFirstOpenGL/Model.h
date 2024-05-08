#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <GL/glew.h>

class Model {
public:
    std::vector<float> vertexs; 
    std::vector<float> uvs; 
    std::vector<float> normals;

    Model() = default;
    Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals);
};

#endif
