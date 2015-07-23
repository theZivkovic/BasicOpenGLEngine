#ifndef __CONFIGURATION_HPP__
#define __CONFIGURATION_HPP__


class Configuration
{
private:
	Configuration(){}
public:
	const static int window_width;
	const static int window_height;
	const static char* program_name;
	~Configuration(){}
};
#endif