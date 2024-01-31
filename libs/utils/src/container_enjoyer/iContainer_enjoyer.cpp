#include "iContainer_enjoyer.h"

#include <iostream>

void IContainerEnjoyer::setFromContainerEnjoyer(IContainerEnjoyer* val)
{
	this->mDatabase = val->mDatabase;
}
void IContainerEnjoyer::createContainer(const std::string path)
{
	try
	{
		auto folder = std::filesystem::path(path).remove_filename();
		if (!folder.empty())
		{
			std::filesystem::create_directories(folder);
		}
		this->mDatabase =
			std::make_shared<SQLite::Database>(std::filesystem::path(path), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
	}
	catch (...)
	{
		spdlog::info("Database could't be created!");
	}
}