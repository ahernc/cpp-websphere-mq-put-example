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


	cout << "Connecting to Queue Manager\n";

	int result = mq.connect(queueManager, channelDefinition);

	cout << "Opening Queue\n";

	mq.open(queueName);


	cout << "You are now connected to MQ! :-) Type the message and hit Enter to push it to the Queue \nEnter no text to close and disconnect from MQ\n";


	/////////////////////////////////////////////////////////////////////////////////
	// Read lines from the console and put them to the message queue
	// Loop until end of input, or there is a failure
	while (true) {

		// File read approach:
		// std::ifstream file("c:\\dev2\\FRA_835821D.XML");
		std::ifstream file("C:\\dev2\\sample_files\\5 exotic trades.xml");
		//std::ifstream file("c:\\dev2\\shortfile.txt");
		std::string str;
		std::string file_contents;
		while (std::getline(file, str))
		{
			file_contents += str;
			//file_contents.push_back('\n');
		}
		const char *data = file_contents.c_str();
		mq.put(data);

		//cout << "Finished!  Press any key to enter thee XML again... ";
		//getchar();
	
		break;

		//////////cout << "Enter a message:  ";
		//////////int      buflen;					
		//////////char     buffer[256];		
	
		//////////if (fgets(buffer, sizeof(buffer), stdin)) {
		//////////	/* console read successful    */
		//////////	buflen = (int)strlen(buffer); /* length without null        */
		//////////	if (buffer[buflen - 1] == '\n') { /* last char is a new-line  */
		//////////		buffer[buflen - 1] = '\0';      /* replace new-line with null */
		//////////		--buflen;                     /* reduce buffer length       */
		//////////	}
		//////////}
		//////////else {
		//////////	buflen = 0;           /* treat EOF same as null line          */
		//////////}

		//////////// Put each buffer to the message queue
		//////////if (buflen > 0) {
		//////////	mq.putMessage(buffer, buflen);
		//////////}
		//////////else {
		//////////	/* quit loop when empty line is read */
		//////////	break;
		//////////}
	




		/*string s;
		getline(std::cin >> std::ws, s);

		int len = s.length();
		if (len == 0)
			break;

		const char* input = s.c_str();
		if (mq.putMessage(input) == 0) {
			cout << "Message added to queue. Horray.\n";
		}		*/

	}
	/////////////////////////////////////////////////////////////////////////////////

	cout << "Close the Queue\n";

	int closeResult = mq.close();

	cout << "Disconnect from the Queue Manager\n";

	int discResult = mq.disconnect();

	cout << "Call Destructor...\n";

	mq.~MQWrapper();

	cout << "Deconstructor called\n";

	cout << "Press any key...\n";

	getchar();

	cout << "Exiting\n";

	//return(0);
	exit((int)0);
}
