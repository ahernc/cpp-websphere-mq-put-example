/*@(#) MQMBID sn=p750-002-131001_DE su=_FswqMCqGEeOZ3ui-rZDONA pn=samples/cpp/imqsput.cpp*/
// Library:       WebSphere MQ
// Component:     C++ sample Programs
// Part:          IMQSPUT.CPP
//
// Description:   Sample C++ program that puts messages to a named
//                queue.
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
//    <copyright 
//    notice="lm-source-program" 
//    pids="5724-H72," 
//    years="1994,2012" 
//    crc="2119159944" > 
//   Licensed Materials - Property of IBM  
//    
//   5724-H72, 
//    
//   (C) Copyright IBM Corp. 1994, 2012 All Rights Reserved.  
//    
//   US Government Users Restricted Rights - Use, duplication or  
//   disclosure restricted by GSA ADP Schedule Contract with  
//   IBM Corp.  
//    </copyright> 

// #include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <imqi.hpp> // WebSphere MQ MQI

int main(int argc, char * * argv) {
	ImqQueueManager mgr;				// Queue manager
	ImqQueue queue;						// Queue
	ImqMessage msg;						// Data message
	int      buflen;					// Buffer length
	char     buffer[256];				// Message buffer
	ImqChannel * pchannel = 0;			// Channel definition

	printf("Sample IMQSPUT start\n");
	if (argc < 2) {
		printf("Required parameter missing - queue name\n");
		exit((int)99);
	}

	// Define a channel for client communication.
	if (argc > 3) {
		ImqString strParse(argv[3]);
		ImqString strToken;

		pchannel = new ImqChannel;
		pchannel->setHeartBeatInterval(1);

		// Break down the channel definition,
		// which is of the form "channel-name/transport-type/connection-name".
		if (strParse.cutOut(strToken, '/')) {
			pchannel->setChannelName(strToken);

			if (strParse.cutOut(strToken, '/')) {

				// Interpret the transport type.
				if (strToken.upperCase() == (ImqString)"LU62") {
					pchannel->setTransportType(MQXPT_LU62);
				}
				if (strToken.upperCase() == (ImqString)"NETBIOS") {
					pchannel->setTransportType(MQXPT_NETBIOS);
				}
				if (strToken.upperCase() == (ImqString)"SPX") {
					pchannel->setTransportType(MQXPT_SPX);
				}
				if (strToken.upperCase() == (ImqString)"TCP") {
					pchannel->setTransportType(MQXPT_TCP);
				}

				// Establish the connection name.
				if (strParse.cutOut(strToken)) {
					pchannel->setConnectionName(strToken);
				}
			}
		}

		mgr.setChannelReference(pchannel);
	}

	// Connect to queue manager
	if (argc > 2) {
		mgr.setName(argv[2]);
	}

	if (!mgr.connect()) {

		/* stop if it failed */
		printf("ImqQueueManager::connect ended with reason code %d\n",
			(int)mgr.reasonCode());
		exit((int)mgr.reasonCode());
	}

	// Associate queue with queue manager.
	queue.setConnectionReference(mgr);

	// Use parameter as the name of the target queue
	queue.setName(argv[1]);
	printf("target queue is %s\n", argv[1]);

	// Open the target message queue for output
	queue.setOpenOptions(MQOO_OUTPUT /* open queue for output        */
		+ MQOO_FAIL_IF_QUIESCING);     /* but not if MQM stopping      */
	queue.open();

	/* report reason, if any; stop if failed      */
	if (queue.reasonCode()) {
		printf("ImqQueue::open ended with reason code %d\n",
			(int)queue.reasonCode());
	}

	if (queue.completionCode() == MQCC_FAILED) {
		printf("unable to open queue for output\n");
	}

	// Read lines from the console and put them to the message queue
	// Loop until end of input, or there is a failure
	msg.useEmptyBuffer(buffer, sizeof(buffer));
	msg.setFormat(MQFMT_STRING);      /* character string format    */

	while (queue.completionCode() != MQCC_FAILED) {

		if (fgets(buffer, sizeof(buffer), stdin)) {
			/* console read successful    */
			buflen = (int)strlen(buffer); /* length without null        */
			if (buffer[buflen - 1] == '\n') { /* last char is a new-line  */
				buffer[buflen - 1] = '\0';      /* replace new-line with null */
				--buflen;                     /* reduce buffer length       */
			}
		}
		else {
			buflen = 0;           /* treat EOF same as null line          */
		}

		// Put each buffer to the message queue
		if (buflen > 0) {
			msg.setMessageLength(buflen);
			if (!queue.put(msg)) {

				/* report reason, if any */
				printf("ImqQueue::put ended with reason code %d\n",
					(int)queue.reasonCode());
			}

		}
		else {
			/* quit loop when empty line is read */
			break;
		}
	}

	// Close the target queue (if it was opened)
	if (!queue.close()) {

		/* report reason, if any     */
		printf("ImqQueue::close ended with reason code %d\n",
			(int)queue.reasonCode());
	}

	// Disconnect from MQM if not already connected (the
	// ImqQueueManager object handles this situation automatically)
	if (!mgr.disconnect()) {

		/* report reason, if any     */
		printf("ImqQueueManager::disconnect ended with reason code %d\n",
			(int)mgr.reasonCode());
	}

	// Tidy up the channel object if allocated.
	if (pchannel) {
		mgr.setChannelReference();
		delete pchannel;
	}

	printf("Sample IMQSPUT end\n");
	return(0);
}
