/* %Z% %W% %I% %E% %U% */
#ifndef _IMQPRO_HPP_
#define _IMQPRO_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQI (WebSphere MQ C++ MQI)
//  Part:          IMQPRO.HPP
//
//  Description:   "ImqProcess" class declaration
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

#include <imqobj.hpp> // ImqObject


#define ImqProcess ImqPro

class IMQ_EXPORTCLASS ImqProcess : public ImqObject {
public :
  // Overloaded "ImqObject" methods:
  virtual ImqBoolean description ( ImqString & );
  virtual ImqBoolean name ( ImqString & );
  // Directed "ImqObject" methods:
  ImqString description ( ) { return ImqObject::description( ); }
  ImqString name ( ) { return ImqObject::name( ); }
  // New methods:
  ImqProcess ( );
  ImqProcess ( const char * );
  ImqProcess ( const ImqProcess & );
  virtual ~ ImqProcess ( );
  void operator = ( const ImqProcess & );
  ImqBoolean applicationId ( ImqString & );
  ImqString applicationId ( );
  ImqBoolean applicationType ( MQLONG & );
  MQLONG applicationType ( );
  ImqBoolean environmentData ( ImqString & );
  ImqString environmentData ( );
  ImqBoolean userData ( ImqString & );
  ImqString userData ( );
} ;


#endif
