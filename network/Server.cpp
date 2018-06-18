//
// Created by elvis on 16/06/18.
//

#include "Server.h"
#include <thread>
#include <vector>
#include <zmqpp/zmqpp.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

void PublishThread(Server* server)
{
    zmqpp::context context;
    zmqpp::socket_type type = zmqpp::socket_type::publish;
    zmqpp::socket socket(context, type);

    socket.bind("tcp://*:4242");

    while(true) {
        zmqpp::message msg;
        socket.receive(msg);
    }
}

void SubscribeThread(Server* server, std::vector<Node> peers)
{
    zmqpp::context context;
    zmqpp::socket_type type = zmqpp::socket_type::subscribe;
    zmqpp::socket socket(context, type);

    for(auto iter=peers.begin();iter!=peers.end();iter++) {
        std::string endpoint = "tcp://";
        endpoint += iter->ip;
        endpoint += ":";
        endpoint += iter->port;

        socket.connect(endpoint);
    }
}

Server::Server(State state, Log log, std::vector<Node> peers)
{
    boost::uuids::random_generator gen;
    this->id = gen();
    this->state = state;
    this->log = log;
    this->peers = peers;

    this->publish_thread = std::thread{PublishThread, this};
    this->subscribe_thread = std::thread{SubscribeThread, this, this->peers};
    
    this->publish_thread.join();
    this->subscribe_thread.join();
}