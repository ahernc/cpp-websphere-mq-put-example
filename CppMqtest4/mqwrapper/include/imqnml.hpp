/* %Z% %W% %I% %E% %U% */
#ifndef _IMQNML_HPP_
#define _IMQNML_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQI (WebSphere MQ C++ MQI)
//  Part:          IMQNML.HPP
//
//  Description:   "ImqNamelist" class declaration
//  <N_OCO_COPYRIGHT> 
//  Licensed Materials - Property of IBM
//  
//  63H9336
//  (c) Copyright IBM Corp. 1999, 2005 All Rights Reserved.
//  
//  US Government Users Restricted Rights - Use, duplication or
//  disclosure restricted by GSA ADP Schedule Contract with
//  IBM Corp.
//  <NOC_COPYRIGHT>  

#include "imqobj.hpp" // ImqObject


#define ImqNamelist ImqNml

class IMQ_EXPORTCLASS ImqNamelist : public ImqObject {
  char * opszNames ;
  MQLONG olNameCount ;
  unsigned int obCountRetrieved : 1 ;
  unsigned int obNamesRetrieved : 1 ;
  unsigned int obPadding1 : 14 ;
  unsigned int obPadding2 : 16 ;
public:
  // Overloaded "ImqObject" methods:
  virtual ImqBoolean description ( ImqString & );
  virtual ImqBoolean name ( ImqString & );
  // Directed "ImqObject" methods:
  ImqString description ( ) { return ImqObject::description( ); }
  ImqString name ( ) { return ImqObject::name( ); }
  // New methods:
  ImqNamelist ( );
  ImqNamelist ( const char * );
  ImqNamelist ( const ImqNamelist & );
  virtual ~ ImqNamelist ( );
  void operator = ( const ImqNamelist & );
  ImqBoolean nameCount ( MQLONG & );
  MQLONG nameCount ( );
  ImqBoolean namelistName ( const MQLONG, ImqString & );
  ImqString namelistName ( const MQLONG );
} ;


#endif
