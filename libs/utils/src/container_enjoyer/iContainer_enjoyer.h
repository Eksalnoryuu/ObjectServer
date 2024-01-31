#pragma once
#include <SQLiteCpp/SQLiteCpp.h>
#include <spdlog/spdlog.h>
class IContainerEnjoyer
{
public:
	IContainerEnjoyer() {}
	~IContainerEnjoyer() {}
    void setFromContainerEnjoyer(IContainerEnjoyer* val);
    void createContainer(const std::string path);
protected:
	std::shared_ptr<SQLite::Database> mDatabase;
};