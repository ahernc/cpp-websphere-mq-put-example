#pragma once

namespace MQWrapper
{

	class MQWrapper
	{
	public:
		MQWrapper();
		~MQWrapper();
		__declspec(dllexport) int connect(const  char*, const  char*);
		__declspec(dllexport) int open(const char*);
		__declspec(dllexport) int put(const char*);

		__declspec(dllexport) int close();
		__declspec(dllexport) int disconnect();
		__declspec(dllexport) int setAttributes();

	private:

	};



}