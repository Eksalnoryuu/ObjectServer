#include "object_provider.h"
const std::string mTableName = "files";
void ObjectProvider::init()
{
	this->createContainer(mStoragePath);
	mObjectModel = std::make_shared<ObjectModel>();
	mObjectModel->setFromContainerEnjoyer(this);
	mObjectModel->setTableName(mTableName);
	mObjectModel->init();
}
void ObjectProvider::insertFile(std::string fileName, std::string&& fileContent)
{
	FileObject value;
	value.fileName = fileName;
	value.fileContent = std::move(fileContent);
	mObjectModel->create(std::move(value));
}
std::optional<FileObject> ObjectProvider::getFile(std::string name)
{
	FileObject object;
	object.fileName = name;
	auto result = std::move(mObjectModel->read(object));
	spdlog::info("Result: {}", result->fileName);
	if (!result.has_value())
	{
		FileObject mockObject;
		mockObject.fileName = "mock";
		mockObject.fileContent = "mock";
		std::optional<FileObject> mock;
		mock.emplace(mockObject);
		return mock;
	}
	return std::move(result);
}
std::vector<std::string> ObjectProvider::getAllNames()
{
	auto names = mObjectModel->getAllNames();
	if (names.has_value())
	{
		return names.value();
	}
	else
	{
		std::vector<std::string> vector;
		vector.push_back("Empty!");
		return std::vector<std::string>(vector);
	}
}