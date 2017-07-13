/* %Z% %W% %I% %E% %U% */
#ifndef _IMQITM_HPP_
#define _IMQITM_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQI (WebSphere MQ C++ MQI)
//  Part:          IMQITM.HPP
//
//  Description:   "ImqItem" class declaration
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

#include <imqerr.hpp> // ImqError


#define ImqItem ImqItm

class ImqMsg ;
class IMQ_EXPORTCLASS ImqItem : public ImqError {
public :
  // New methods:
  ImqItem ( );
  ImqItem ( const ImqItem & );
  virtual ~ ImqItem ( );
  void operator = ( const ImqItem & );
  virtual ImqBoolean copyOut ( ImqMsg & ) = 0 ;
  virtual ImqBoolean pasteIn ( ImqMsg & ) = 0 ;
  static ImqBoolean structureIdIs ( const char *, const ImqMsg & );
} ;


#endif
