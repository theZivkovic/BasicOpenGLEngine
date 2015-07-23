#include "shader.hpp"

Shader::Shader(GLuint type)
{
    _type = type;
}

int Shader::compileFrom(const char *filename)
{
    _ID = glCreateShader(_type);

    const char *code = readFromFile(filename);

    glShaderSource(_ID, 1, &code, NULL);
    glCompileShader(_ID);

    GLint compileStatus = GL_FALSE;
    glGetShaderiv(_ID, GL_COMPILE_STATUS, &compileStatus);

    if (compileStatus == GL_FALSE)
        return -1;

    return 0;
}

GLuint Shader::getID()
{
    return _ID;
}

char *Shader::readFromFile(const char *fn)
{
    FILE *fp;
    char *content = NULL;

    int count = 0;

    if (fn != NULL) {
        fp = fopen(fn, "rt");

        if (fp != NULL) {

            fseek(fp, 0, SEEK_END);
            count = ftell(fp);
            rewind(fp);

            if (count > 0) {
                content = (char *) malloc(sizeof(char) * (count + 1));
                count = fread(content, sizeof(char), count, fp);
                content[count] = '\0';
            }
            fclose(fp);
        }
    }
    return content;
}

void Shader::print_log()
{
    GLint log_length = 0;

    glGetShaderiv(_ID, GL_INFO_LOG_LENGTH, &log_length);

    char *log = (char *) malloc(log_length);

    glGetShaderInfoLog(_ID, log_length, NULL, log);

    std::cerr << log << std::endl;

    free(log);
}

Shader::~Shader()
{

}
