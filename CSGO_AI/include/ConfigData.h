#pragma once
#include <string>
#include <wtypes.h>

struct ConfigData 
{
	std::string client_dll_name;
	std::string engine_dll_name;
	std::string  windowname;
	int delay = 0;
	DWORD trigger_button = 0;
};