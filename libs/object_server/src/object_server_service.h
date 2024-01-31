#include "zmq.h"
#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "spdlog/spdlog.h"
#include <iostream>
#include "object_controller.h"
class ObjectServer
{
public:
	ObjectServer(){};
	~ObjectServer(){};
    void Init(const std::string subAddress, const std::string pubAddress);
    void Connect();
    void Start();
private:
	std::unique_ptr<zmq::context_t> mContext;
    std::shared_ptr<zmq::socket_t> mPubSocket;
    std::shared_ptr<zmq::socket_t> mSubSocket;
    std::shared_ptr<ObjectController> mObjectController;
    std::shared_ptr<ObjectProvider> mObjectProvider;
    std::string mSubAddress;
    std::string mPubAddress;
};