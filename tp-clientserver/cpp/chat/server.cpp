#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    Net net;

    hv::WebSocketService ws;
    ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        channel->send("Quel est votre nom ?");
        net.add(channel);
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
        if channel.
        auto sendInput = [&msg](const WebSocketChannelPtr & channel) {
            channel->send(msg);
        };
        net.map(sendInput);
    };
    ws.onclose = [&net](const WebSocketChannelPtr& channel) {
        net.del(channel);
        std::cout << "client disconnected" << std::endl;
    };

    hv::WebSocketServer server;
    server.registerWebSocketService(&ws);
    server.setPort(9000);
    std::cout << "waiting for clients..." << std::endl;
    server.run();

    return 0;
}

