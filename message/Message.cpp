//
// Created by elvis on 16/06/18.
//

#include "Message.h"

Message::Message(int sender, int receiver, std::string data, int term, MsgType msg_type)
{
    this->sender = sender;
    this->receiver = receiver;
    this->data = data;
    this->term = term;
    this->msg_type = msg_type;
}