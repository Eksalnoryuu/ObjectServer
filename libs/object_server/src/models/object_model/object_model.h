#include "libs/object_server/src/models/types.h"
#include "libs/utils/src/container_enjoyer/iContainer_enjoyer.h"
#include "libs/utils/src/sqllite_enjoyer/iSqlite_enjoyer.h"
#include "spdlog/spdlog.h"
class ObjectModel : public ISqliteEnjoyer<FileObject>, public IContainerEnjoyer
{
public:
	ObjectModel();
	~ObjectModel() {}
	void init();
	void create(const FileObject& object) override;
	std::optional<FileObject> read(const FileObject& object) override;
	void remove(const FileObject& object) override;
	void update(const FileObject& object) override;
	std::optional<std::vector<FileObject>> readAll() override;
    void setTableName(std::string tableName);
	std::optional<std::vector<std::string>> getAllNames();
private:
    void createTable();
    std::string mTableName;
};