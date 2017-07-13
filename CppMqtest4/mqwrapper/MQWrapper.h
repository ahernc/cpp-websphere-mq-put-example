#pragma once

namespace MQWrapper
{

	class MQWrapper
	{
	public:
		MQWrapper();
		~MQWrapper();
		__declspec(dllexport) int openConnection(const char*, const  char*, const  char*);
		__declspec(dllexport) int putMessage(const char*);
		__declspec(dllexport) int disconnect();
		__declspec(dllexport) int getInteger();

	private:

	};



}