#include "program.hpp"

Program::Program(const char *vertFile, const char *fragFile)
{
    Shader vertexShader(GL_VERTEX_SHADER);
    Shader fragmentShader(GL_FRAGMENT_SHADER);

    if (vertexShader.compileFrom(vertFile) < 0) {
        std::cerr << "Error: compiling vertex shader:" << std::endl;
        vertexShader.print_log();
        exit(EXIT_FAILURE);
    }

    std::cout << "Log: Vertex shader compiled succesfully." << std::endl;

    if (fragmentShader.compileFrom(fragFile) < 0) {
        std::cerr << "Error: compiling fragment shader:" << std::endl;
        fragmentShader.print_log();
        exit(EXIT_FAILURE);
    }

    std::cout << "Log: Fragment shader compiled succesfully." << std::endl;

    _ID = glCreateProgram();
    glAttachShader(_ID, vertexShader.getID());
    glAttachShader(_ID, fragmentShader.getID());

    glLinkProgram(_ID);

    GLint linkStatus = GL_FALSE;

    glGetProgramiv(_ID, GL_LINK_STATUS, &linkStatus);

    if (linkStatus == GL_FALSE) {
        std::cerr << "Error: linking program: " << std::endl;
        print_log();
    }

    std::cout << "Log: Program linked succesfully." << std::endl;
}

GLuint Program::getID()
{
    return _ID;
}

void Program::print_log()
{
    GLint log_length = 0;

    glGetProgramiv(_ID, GL_INFO_LOG_LENGTH, &log_length);

    char *log = (char *) malloc(log_length);

    glGetProgramInfoLog(_ID, log_length, NULL, log);

    std::cerr << log << std::endl;

    free(log);
}

void Program::addVariable(const char *name, VariableType type)
{
    Variable v(name, type, _ID);

    if (!v.isValid()) {
        std::cerr << "Error: Variable " << name <<
            " can't be bound with shader program!" << std::endl;
        exit(EXIT_FAILURE);
    }

    _variables[name] = v.getID();

    std::cout << "Log: " << v.getType() << " " << name <<
        " added to the program." << std::endl;
}

GLuint Program::getVariableID(const char *name)
{
    assert(_variables.find(name) != _variables.end()
           && "Can't get variable" && name);

    return _variables[name];
}
