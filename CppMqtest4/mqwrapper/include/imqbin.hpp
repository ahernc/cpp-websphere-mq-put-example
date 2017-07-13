/* %Z% %W% %I% %E% %U% */
#ifndef _IMQBIN_HPP_
#define _IMQBIN_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQB (WebSphere MQ C++ Support)
//  Part:          IMQBIN.HPP
//
//  Description:   "ImqBinary" class declaration
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

#include <imqitm.hpp> // ImqItem


#define ImqBinary ImqBin

class IMQ_EXPORTCLASS ImqBinary : public ImqItem {
  void * opvoid ;
  size_t ouiLength ;
protected :
  // New methods:
  void clear ( );
public :
  // Overloaded "ImqItem" methods:
  virtual ImqBoolean copyOut ( ImqMsg & );
  virtual ImqBoolean pasteIn ( ImqMsg & );
  // New methods:
  ImqBinary ( );
  ImqBinary ( const ImqBinary & );
  ImqBinary ( const void *, const size_t );
  virtual ~ ImqBinary ( );
  void operator = ( const ImqBinary & );
  ImqBoolean operator == ( const ImqBinary & ) const ;
  ImqBoolean copyOut ( void *, const size_t, const char = 0 );
  size_t dataLength ( ) const { return ouiLength ; }
  ImqBoolean isNull ( ) const ;
  ImqBoolean setDataLength ( const size_t );
  void * dataPointer ( ) const { return opvoid ; }
  ImqBoolean set ( const void *, const size_t );
} ;


#endif
