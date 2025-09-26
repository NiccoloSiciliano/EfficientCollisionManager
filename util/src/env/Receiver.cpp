#include "../../Receiver.hpp"

Receiver::Receiver()
{
	this->index = 0;
	this->buff = NULL;
}
void Receiver::receive(int index, char* buff)
{
	read = 0;
	this->index = index;
	this->buff = buff;
}

char* Receiver::read_buff()
{
	read = 1;
	return buff;
}

int Receiver::read_index()
{
	read = 1;	
	return index;
}

bool Receiver::is_read()
{
	return read;
}