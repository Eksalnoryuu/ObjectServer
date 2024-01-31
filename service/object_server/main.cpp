#include "libs/object_server/src/object_server_service.h"
const std::string subAddress = "tcp://127.0.0.1:9090";
const std::string pubAddress = "tcp://127.0.0.1:9091";

int main()
{
	std::thread mainThread;
	ObjectServer server;
	server.Init(subAddress, pubAddress);
	server.Connect();
	mainThread = std::thread([&] { server.Start(); });
	mainThread.join();
}