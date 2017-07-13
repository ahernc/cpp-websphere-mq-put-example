/* %Z% %W% %I% %E% %U% */
#ifndef _IMQDST_HPP_
#define _IMQDST_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQI (WebSphere MQ C++ MQI)
//  Part:          IMQDST.HPP
//
//  Description:   "ImqDistributionList" class declaration
//  <N_OCO_COPYRIGHT> 
//  Licensed Materials - Property of IBM
//  
//  63H9336
//  (c) Copyright IBM Corp. 1994, 2005 All Rights Reserved.
//  
//  US Government Users Restricted Rights - Use, duplication or
//  disclosure restricted by GSA ADP Schedule Contract with
//  IBM Corp.
//  <NOC_COPYRIGHT>  

#include <imqque.hpp> // ImqQueue


#define ImqDistributionList ImqDst

class IMQ_EXPORTCLASS ImqDistributionList : public ImqQueue {
  ImqQueue * opfirstDistributedQueue;
protected :
  friend class ImqQueue ;
  // Overloaded "ImqObject" methods:
  virtual void openInformationDisperse ( );
  virtual ImqBoolean openInformationPrepare ( );
  // Overloaded "ImqQueue" methods:
  virtual void putInformationDisperse ( ImqPmo & );
  virtual ImqBoolean putInformationPrepare ( const ImqMsg &, ImqPmo & );
  // New methods:
  void setFirstDistributedQueue ( ImqQueue * pqueue = 0 )
    { opfirstDistributedQueue = pqueue ; }
public :
  // New methods:
  ImqDistributionList ( );
  ImqDistributionList ( const ImqDistributionList & );
  virtual ~ ImqDistributionList ( );
  void operator = ( const ImqDistributionList & );
  ImqQueue * firstDistributedQueue ( ) const
    { return opfirstDistributedQueue ; }
} ;


#endif
