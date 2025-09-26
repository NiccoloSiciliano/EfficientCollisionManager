#include "../../Sender.hpp"


void Sender::set_receiver(Receiver* receiver)
{
	this->receiver = receiver;
}

void Sender::send(int index, char* buff)
{
	receiver->receive(index, buff);
}
