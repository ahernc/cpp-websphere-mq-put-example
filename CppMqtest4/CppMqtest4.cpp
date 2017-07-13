/*@(#) MQMBID sn=p750-002-131001_DE su=_FswqMCqGEeOZ3ui-rZDONA pn=samples/cpp/imqsput.cpp*/
// Library:       WebSphere MQ
// Component:     C++ sample Programs
// Part:          filname here .cpp
//
// Description:   Sample C++ program that puts messages to a named
//                queue using the MQWrapperClassLib project. 
//
//                IMQSPUT has 3 parameters:
//                - the name of a queue (required)
//                - the name of a queue manager (optional)
//                - the definition of a channel (optional)
//
//                If no queue manager name is given, the queue manager
//                defaults to the default local queue manager. If a
//                channel is defined, it should have the same format
//                as the MQSERVER environment variable.

// #include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "MQWrapper.h"

using namespace std;


int main(int argc, char * * argv) {

	MQWrapper::MQWrapper mq;

	//// Q1 QM_TEST CHANNEL1/TCP/localhost(1414)
	const char * queueName = "Q1";
	const char * queueManager = "QM_TEST";
	const char * channelDefinition = "CHANNEL1/TCP/localhost(1414)";


	cout << "Opening Connection\n";
	int result = mq.openConnection(queueName, queueManager, channelDefinition);

	cout << "You are now connected to MQ! :-) Starting firing in some messages... \n Enter a new line with no text to close and disconnect from MQ\n";



	/////////////////////////////////////////////////////////////////////////////////
	// Read lines from the console and put them to the message queue
	// Loop until end of input, or there is a failure
	while (true) {
		cout << "Enter a message:  ";
		//int      buflen;					
		//char     buffer[256];				
		//if (fgets(buffer, sizeof(buffer), stdin)) {
		//	/* console read successful    */
		//	buflen = (int)strlen(buffer); /* length without null        */
		//	if (buffer[buflen - 1] == '\n') { /* last char is a new-line  */
		//		buffer[buflen - 1] = '\0';      /* replace new-line with null */
		//		--buflen;                     /* reduce buffer length       */
		//	}
		//}
		//else {
		//	buflen = 0;           /* treat EOF same as null line          */
		//}

		//// Put each buffer to the message queue
		//if (buflen > 0) {

		//	
		//}
		//else {
		//	/* quit loop when empty line is read */
		//	break;
		//}
		
		/*char input[256];
		cin.getline(input, sizeof(input));
		int lengthOfInput = (int)strlen(input);
		if (lengthOfInput == 0)
			break;*/




		/*string s;
		getline(std::cin >> std::ws, s);

		int len = s.length();
		if (len == 0)
			break;

		const char* input = s.c_str();
		if (mq.putMessage(input) == 0) {
			cout << "Message added to queue. Horray.\n";
		}		*/


		std::ifstream file("c:\\dev2\\_testFile.html");
		std::string str;
		std::string file_contents;
		while (std::getline(file, str))
		{
			file_contents += str;
			file_contents.push_back('\n');
		}
		const char *data = file_contents.c_str();
		mq.putMessage(data);

	}
	/////////////////////////////////////////////////////////////////////////////////


	cout << "Disconnecting\n";

	int disc = mq.disconnect();

	cout << "Disconnected\n";

	mq.~MQWrapper();

	cout << "Deconstructor called\n";

	cout << "Press any key...\n";

	getchar();

	cout << "Exiting\n";

	//return(0);
	exit((int)0);
}