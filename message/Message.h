//
// Created by elvis on 16/06/18.
//

#ifndef ELVIS_CPP_RAFT_MESSAGE_H
#define ELVIS_CPP_RAFT_MESSAGE_H

#include <ctime>
#include <string>

enum class MsgType {AppendEntriesMessgae = 0, RequestVoteMessage = 1, RequestVoteResponseMessage = 2, ResponseMessage = 3 };

class Message {
public:
    std::time_t timestamp = std::time(nullptr);
    int sender;
    int receiver;
    std::string data;
    int term;
    MsgType msg_type;

    Message(int sender, int receiver, std::string data, int term, MsgType msg_type);
};


#endif //ELVIS_CPP_RAFT_MESSAGE_H
