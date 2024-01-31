#pragma once
#include "libs/object_server/src/models/object_model/object_model.h"
#include "libs/object_server/src/models/types.h"
#include "libs/utils/src/container_enjoyer/iContainer_enjoyer.h"
#include "libs/utils/src/sqllite_enjoyer/iSqlite_enjoyer.h"

const std::string mStoragePath = "/storage/storage.db3";
class ObjectProvider : public IContainerEnjoyer
{
public:
	ObjectProvider() {}
	~ObjectProvider() {}
	void init();
	void insertFile(std::string fileName, std::string&& fileContent);
	std::optional<FileObject> getFile(std::string name);
	std::vector<std::string> getAllNames();

private:
	std::shared_ptr<ObjectModel> mObjectModel;
};