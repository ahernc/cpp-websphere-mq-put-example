/* %Z% %W% %I% %E% %U% */
#ifndef _IMQCAC_HPP_
#define _IMQCAC_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQB (WebSphere MQ C++ MQI)
//  Part:          IMQCAC.HPP
//
//  Description:   "ImqCache" class declaration
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

extern "C" {
#include <string.h>
}

#include <imqerr.hpp> // ImqError


#define ImqCache ImqCac

class IMQ_EXPORTCLASS ImqCache : public virtual ImqError {
  char * opszBuffer ;
  size_t ouiDataOffset ;
  size_t ouiBufferLength ;
  size_t ouiMessageLength ;
  ImqBoolean obAutomaticBuffer ;
  char ocPadding1[ 3 ];
  // New methods:
  void setAutomaticBuffer ( const ImqBoolean bAutomatic )
    { obAutomaticBuffer = bAutomatic ; }
public :
  // New methods:
  ImqCache ( );
  ImqCache ( const ImqCache & );
  virtual ~ ImqCache ( );
  void operator = ( const ImqCache & );
  ImqBoolean automaticBuffer ( ) const { return obAutomaticBuffer ; }
  size_t bufferLength ( ) const { return ouiBufferLength ; }
  char * bufferPointer ( ) const { return opszBuffer ; }
  void clearMessage ( );
  size_t dataLength ( ) const ;
  size_t dataOffset ( ) const { return ouiDataOffset ; }
  char * dataPointer ( ) const { return bufferPointer( ) + dataOffset( ); }
  size_t messageLength ( ) const { return ouiMessageLength ; }
  ImqBoolean moreBytes ( const size_t );
  ImqBoolean read ( const size_t, char * & );
  ImqBoolean resizeBuffer ( const size_t );
  ImqBoolean setDataOffset ( const size_t );
  ImqBoolean setMessageLength ( const size_t );
  ImqBoolean useEmptyBuffer ( const char *, const size_t );
  ImqBoolean useFullBuffer ( const char *, const size_t );
  ImqBoolean write ( const size_t, const char * );
} ;



#endif
