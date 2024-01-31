#pragma once
#include <SQLiteCpp/SQLiteCpp.h>

#include <memory>
#include <optional>
#include <vector>
template<class T> class ISqliteEnjoyer
{
public:
	ISqliteEnjoyer() {}
	~ISqliteEnjoyer() {}

	virtual void create(const T& object) = 0;
	virtual std::optional<T> read(const T& object) = 0;
	virtual void remove(const T& object) = 0;
	virtual void update(const T& object) = 0;
	virtual std::optional<std::vector<T>> readAll() = 0;

protected:
};