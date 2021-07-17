#include "CSGOAI.h"

CSGOAi::CSGOAi()
{
}

bool CSGOAi::init()
{
	if (!Offsets::load_offsets_from_file("offsets.json"))
	{
		std::cout << "Offsets couldn't be read, make sure you have a valid offsets file" << std::endl;
		return false;
	}

	ConfigData data;
	if (!ConfigReader::read_in_config_data(data)) 
	{
		std::cout << "Config couldn't be read, make sure you have a valid config" << std::endl;
		return false;
	}

	this->gameInfoHandler = std::make_unique<GameInformationhandler>();
	if (!this->gameInfoHandler->init(data)) 
	{
		std::cout << "Error getting dll address " << std::endl;
		return false;
	}

	return true;
}

void CSGOAi::run()
{
	while (true) 
	{
		gameInfoHandler->update_game_information();
		GameInformation game_info = gameInfoHandler->get_game_information();


	}
}
