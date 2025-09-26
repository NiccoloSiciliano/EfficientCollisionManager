#pragma once
#include "Receiver.hpp"

class Sender
{
	protected:
		Receiver *receiver;
	public:
		void set_receiver(Receiver* receiver);
		void send(int index, char* buff);

};