#include "object_server_service.h"

void ObjectServer::Init(const std::string subAddress, const std::string pubAddress)
{
	mContext = std::make_unique<zmq::context_t>(1);
	mPubSocket = std::make_shared<zmq::socket_t>(*mContext, zmq::socket_type::pub);
	mSubSocket = std::make_shared<zmq::socket_t>(*mContext, 2);
	mObjectController = std::make_shared<ObjectController>();
	mObjectProvider = std::make_shared<ObjectProvider>();
	mPubAddress = pubAddress;
	mSubAddress = subAddress;

	mObjectProvider->init();
	mObjectController->objectProvider(mObjectProvider);
	mObjectController->publisherSocket(mPubSocket);
}

void ObjectServer::Connect()
{
	mPubSocket->bind(mPubAddress);
	mSubSocket->bind(mSubAddress);
	mSubSocket->set(zmq::sockopt::subscribe,"");
}

void ObjectServer::Start()
{
	spdlog::info("[SERVER] System Started!");
	while (true)
	{
		std::vector<zmq::message_t> recv_msgs;
		zmq::recv_result_t result = zmq::recv_multipart(*mSubSocket, std::back_inserter(recv_msgs));
		if (result.has_value())
		{
			spdlog::info("[SERVER] Received [{}]", recv_msgs[0].to_string());
			mObjectController->onNewMsg(recv_msgs);
		}
	}
}