#ifndef SHADER_H
#define SHADER_H

class Shader {
public:
    unsigned int id;

    Shader(unsigned int id);
    ~Shader();

    void use();
}

//extern Shader* load_shader();

#endif