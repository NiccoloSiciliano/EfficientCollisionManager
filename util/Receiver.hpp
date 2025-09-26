#pragma once

#include <cstddef>
class Receiver
{
	protected:
		char* buff;
		int index;
		bool read;
	public:
		Receiver();
		void receive(int index, char* buff);
		char* read_buff();
		int read_index();
		bool is_read();

};