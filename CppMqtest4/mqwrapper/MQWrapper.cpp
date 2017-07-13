#include <stdlib.h>
#include <string>
#include <imqi.hpp>		// Websphere MQ stuff is all in here.
#include "MQWrapper.h"

using namespace std;

namespace MQWrapper
{

	ImqQueueManager queueManager_;				/*!< Queue manager */
	ImqQueue queue_;					/*!< Queue */
	ImqMessage message_;				/*!< Data message */
	//int      buflen_;					/*!< Buffer length */
	//char     buffer_[256];				/*!< Message buffer  */
	ImqChannel * pChannel_ = 0;			/*!< Channel definition */

	char* pQueueName_;					/*!< The name of the Queue */


	MQWrapper::MQWrapper()
	{
	}

	MQWrapper::~MQWrapper()
	{
		// To decide: let's say a client "forgets" to call .disconnect.
		// We could also call disconnect here... possibly offer few options/flags
		// to allow other clients to close and disconnect from the queue in one go?

		// Tidy up the channel object if allocated.
		if (pChannel_) {
			queueManager_.setChannelReference();
			delete pChannel_;
		}
	}


	/**
	*	\brief Opens a connection to MQ.
	*
	*	This can only be called after the Constructor which accepts the parameters abotu the queue.
	*	If opening a connection, don't forget to close it when you are sure you are finished with it!
	*
	*	\return An int code representing the success or failure.
	*			For the complete list of possible codes, see https://www.ibm.com/support/knowledgecenter/en/SSFKSJ_7.5.0/com.ibm.mq.tro.doc/q040710_.htm
	**/
	int MQWrapper::openConnection(const char* QueueName, const char* QueueManagerName, const char* ChannelDefinition)
	{
		ImqString channelParse(ChannelDefinition);
		ImqString strToken;

		pChannel_ = new ImqChannel;
		pChannel_->setHeartBeatInterval(1);

		if (channelParse.cutOut(strToken, '/'))
		{
			pChannel_->setChannelName(strToken);

			if (channelParse.cutOut(strToken, '/'))
			{
				// Interpret the transport type.
				if (strToken.upperCase() == (ImqString)"LU62") {
					pChannel_->setTransportType(MQXPT_LU62);
				}
				if (strToken.upperCase() == (ImqString)"NETBIOS") {
					pChannel_->setTransportType(MQXPT_NETBIOS);
				}
				if (strToken.upperCase() == (ImqString)"SPX") {
					pChannel_->setTransportType(MQXPT_SPX);
				}
				if (strToken.upperCase() == (ImqString)"TCP") {
					pChannel_->setTransportType(MQXPT_TCP);
				}

				// Establish the connection name.
				if (channelParse.cutOut(strToken)) {
					pChannel_->setConnectionName(strToken);
				}
			}
		}

		queueManager_.setChannelReference(pChannel_);

		queueManager_.setName(QueueManagerName);

		if (!queueManager_.connect()) {

			// return reason code: to do: enumeration of exception codes 
			// from mq
			return (int)queueManager_.reasonCode();
		}

		// Associate queue with queue manager.
		queue_.setConnectionReference(queueManager_);

		// Use parameter as the name of the target queue
		queue_.setName(QueueName);

		// Open the target message queue for output
		queue_.setOpenOptions(MQOO_OUTPUT	/* open queue for output        */
			+ MQOO_FAIL_IF_QUIESCING);		/* but not if MQM stopping      */
		queue_.open();

		/* report reason, if any; stop if failed      */
		if (queue_.reasonCode()) {
			return (int)queue_.reasonCode();
		}

		if (queue_.completionCode() == MQCC_FAILED) {
			// printf("unable to open queue for output\n");
			// To do: try to recreate this scenario... the completion code
			// for now, just return the MQCC_FAILED value (which is 2, and doesn't 
			// really tell us a lot)
			return (int)MQCC_FAILED;
		}

		// If we get here, we're all good:
		return 0;
	}





	///**
	//*	\brief Puts a message into the the MQ.
	//*
	//*	If opening a connection, don't forget to close it when you are sure you are finished with it!
	//*
	//*	\return An int code representing the success or failure of putting the message into the queue.
	//*			For the complete list of possible codes, see https://www.ibm.com/support/knowledgecenter/en/SSFKSJ_7.5.0/com.ibm.mq.tro.doc/q040710_.htm
	//**/
	int MQWrapper::putMessage(const char* messageContent)
	{

		message_.useEmptyBuffer(messageContent, sizeof(messageContent));
		message_.setFormat(MQFMT_STRING);      /* character string format */

		const size_t buflen = (int)strlen(messageContent);
		message_.setMessageLength(buflen);
		if (!queue_.put(message_)) {
			/* report reason, if any */
			return (int)queue_.reasonCode();
		}

		return 0;
	}




	int MQWrapper::disconnect()
	{
		// Close the target queue (if it was opened)
		if (!queue_.close()) {
			/* report reason, if any     */
			return (int)queue_.reasonCode();
		}

		// Disconnect from MQM if not already connected (the
		// ImqQueueManager object handles this situation automatically)
		if (!queueManager_.disconnect()) {
			return (int)queueManager_.reasonCode();
		}

		// All good.
		return 0;
	}

	int MQWrapper::getInteger()
	{
		return 0;
	}


}