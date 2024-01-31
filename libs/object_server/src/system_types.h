#pragma once
#include <map>
#include <string>
enum class Topic
{
	ADD_NEW_FILE = 0,
	REQUEST_FILE = 1,
	REQUEST_ALL_NAMES = 2,
	RESPONSE_ALL_NAMES = 3,
	RESPONSE_FILE = 4,
};

const std::map<Topic, std::string> mTopicToStringMap = {
	{Topic::ADD_NEW_FILE, "ADD_NEW_FILE"},
	{Topic::REQUEST_FILE, "REQUEST_FILE"},
	{Topic::REQUEST_ALL_NAMES, "REQUEST_ALL_NAMES"},
	{Topic::RESPONSE_ALL_NAMES, "RESPONSE_ALL_NAMES"},
	{Topic::RESPONSE_FILE, "RESPONSE_FILE"},
};