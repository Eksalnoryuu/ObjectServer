#include "object_controller.h"
#include <iostream>

void ObjectController::onNewMsg(const std::vector<zmq::message_t>& msg)
{
	auto topic = msg[0].to_string();
	if (topic == mTopicToStringMap.at(Topic::ADD_NEW_FILE))
	{
		onNewFile(msg.at(1), msg.at(2));
	}
	if (topic == mTopicToStringMap.at(Topic::REQUEST_ALL_NAMES))
	{
		onAllNames();
	}
	if (topic == mTopicToStringMap.at(Topic::REQUEST_FILE))
	{
		spdlog::info("[SERVER] Handling REQUEST_FILE");
		onRequestFile(msg.at(1));
	}
}

void ObjectController::onNewFile(const zmq::message_t& fileName, const zmq::message_t& fileData)
{
	mObjectProvider->insertFile(fileName.to_string().c_str(), fileData.to_string());
}

void ObjectController::onAllNames()
{
	auto names = mObjectProvider->getAllNames();
	zmq::message_t topic(mTopicToStringMap.at(Topic::RESPONSE_ALL_NAMES));
	mPubSocket->send(topic, zmq::send_flags::sndmore);

	spdlog::info("[SERVER] Sending All Names!");
	nlohmann::json json;
	json["content"] = names;
	zmq::message_t content(json.dump());
	mPubSocket->send(content);
}

void ObjectController::onRequestFile(const zmq::message_t& file_name)
{
	auto file = std::move(mObjectProvider->getFile(file_name.to_string().c_str()));
	if (!file.has_value())
	{
		spdlog::warn("No file with name {} was found", file_name.to_string());
		return;
	}
	spdlog::info("[SERVER] Sending file {}!", file->fileName);
	zmq::message_t topic(mTopicToStringMap.at(Topic::RESPONSE_FILE));

	mPubSocket->send(topic, zmq::send_flags::sndmore);
	zmq::message_t fileName(file->fileName);
	mPubSocket->send(fileName, zmq::send_flags::sndmore);
	zmq::message_t fileContent(std::move(file->fileContent));
	mPubSocket->send(fileContent);
}