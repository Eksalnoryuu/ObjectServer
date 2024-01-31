#include "libs/object_server/src/models/object_model/object_model.h"

ObjectModel::ObjectModel()
{
}

void ObjectModel::init()
{
	if (!this->mDatabase)
	{
		spdlog::error("Storage in <ObjectModel> wasn't added!");
	}

	createTable();
}

void ObjectModel::createTable()
{
	try
	{
		this->mDatabase->exec(
			"CREATE TABLE IF NOT EXISTS " + mTableName +
			" (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
			"file_name TEXT NOT NULL,"
			"file_content BLOB NOT NULL, "
			"update_at TEXT NOT NULL);"
		);
	}
	catch (const std::exception e)
	{
		spdlog::info(e.what());
	}
}

void ObjectModel::setTableName(std::string tableName)
{
	mTableName = tableName;
}

void ObjectModel::create(const FileObject& object)
{
	spdlog::info("[ObjectModel] create record of {}", object.fileName);
	try
	{
        SQLite::Statement query(*mDatabase.get(), " INSERT INTO " + mTableName + 
        " (file_name, " +
        "file_content, " +
		"update_at) " +
        "VALUES (?,?,datetime('now','localtime'))");
		query.bind(1, object.fileName);
		query.bind(2, std::move(object.fileContent));
		query.exec();
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
}
std::optional<FileObject> ObjectModel::read(const FileObject& object)
{
	spdlog::info("[ObjectModel] Read record of {}", object.fileName);
	try
	{
		std::optional<FileObject> result;
		SQLite::Statement query(*mDatabase.get(), " SELECT * FROM " + mTableName + " WHERE file_name = ?;");
		query.bind(1, object.fileName);
		if (query.executeStep())
		{
			FileObject object;
			object.fileName = query.getColumn(1).getString();
			object.fileContent = std::move(query.getColumn(2).getString());
			result.emplace(object);
		}
		return result;
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
}
void ObjectModel::remove(const FileObject& object)
{
	//may need it
	return;
}
void ObjectModel::update(const FileObject& object)
{
	return;
}
std::optional<std::vector<FileObject>> ObjectModel::readAll()
{
	std::optional<std::vector<FileObject>> placeHolder;
	return placeHolder;
}

std::optional<std::vector<std::string>> ObjectModel::getAllNames()
{
	spdlog::info("[ObjectModel] Read all names");
	try
	{
		std::optional<std::vector<std::string>> result;
		SQLite::Statement query(*mDatabase.get(), " SELECT file_name FROM " + mTableName);
		std::vector<std::string> values;
		while (query.executeStep())
		{
			std::string object;
			values.push_back(query.getColumn(0).getString());
		}
		result.emplace(values);
		return result;
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
}