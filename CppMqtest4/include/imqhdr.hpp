/* %Z% %W% %I% %E% %U% */
#ifndef _IMQHDR_HPP_
#define _IMQHDR_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQI (WebSphere MQ C++ MQI)
//  Part:          IMQHDR.HPP
//
//  Description:   "ImqHeader" class declaration
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

#include <imqstr.hpp> // ImqString


#define ImqHeader ImqHdr

class IMQ_EXPORTCLASS ImqHeader : public ImqItem {
public :
  // New methods:
  ImqHeader ( );
  ImqHeader ( const ImqHeader & );
  virtual ~ ImqHeader ( );
  void operator = ( const ImqHeader & );
  virtual MQLONG characterSet ( ) const = 0 ;
  virtual MQLONG encoding ( ) const = 0 ;
  virtual ImqString format ( ) const = 0 ;
  virtual MQLONG headerFlags ( ) const = 0 ;
  virtual void setCharacterSet ( const MQLONG = MQCCSI_Q_MGR ) = 0 ;
  virtual void setEncoding ( const MQLONG = MQENC_NATIVE ) = 0 ;
  virtual void setFormat ( const char * = 0 ) = 0 ;
  virtual void setHeaderFlags ( const MQLONG = 0 ) = 0 ;
} ;


#endif
