#include <vector>
#include <zmq.hpp>

#include "libs/object_server/src/providers/object_provider.h"
#include "system_types.h"
#include "nlohmann/json.hpp"
class ObjectController
{
public:
	ObjectController() {}
	~ObjectController() {}
	void onNewMsg(const std::vector<zmq::message_t>& msg);
	void objectProvider(std::shared_ptr<ObjectProvider> value) { mObjectProvider = value; }
	void publisherSocket(std::shared_ptr<zmq::socket_t> value) { mPubSocket = value; }

private:
	void onNewFile(const zmq::message_t& fileName, const zmq::message_t& fileData);
	void onAllNames();
	void onRequestFile(const zmq::message_t& file_name);
	std::vector<zmq::message_t> recv_msgs;
	std::shared_ptr<zmq::socket_t> mPubSocket;
	std::shared_ptr<ObjectProvider> mObjectProvider;
};