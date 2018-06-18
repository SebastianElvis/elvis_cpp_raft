//
// Created by elvis on 16/06/18.
//

#include "state/State.h"
#include "message/Message.h"
#include "log/Log.h"
#include <vector>
#include <thread>
#include <string>
#include <boost/uuid/uuid.hpp>

struct Node {
    boost::uuids::uuid id;
    std::string ip;
    int port;
};

class Server {
private:
    boost::uuids::uuid id;
    State state;
    Log log;
    std::vector<Node> peers;
    std::thread publish_thread;
    std::thread subscribe_thread;

public:
    Server(State state, Log log, std::vector<Node> peers);
    void add_peer(Node peer);
    void send_message(Message msg, Node peer);
    void broadcast_message(Message msg);
    void on_message(Message msg);
};


