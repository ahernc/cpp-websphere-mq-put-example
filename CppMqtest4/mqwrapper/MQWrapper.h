#pragma once

namespace MQWrapper
{

	class MQWrapper
	{
	public:
		MQWrapper();
		~MQWrapper();
		__declspec(dllexport) int openConnection(const char*, const  char*, const  char*);
		__declspec(dllexport) int putMessage(char*);
		__declspec(dllexport) int disconnect();
		__declspec(dllexport) int getInteger();

	private:

	};



}