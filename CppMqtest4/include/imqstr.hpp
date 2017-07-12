/* %Z% %W% %I% %E% %U% */
#ifndef _IMQSTR_HPP_
#define _IMQSTR_HPP_

//  Library:       WebSphere MQ
//  Component:     IMQB (WebSphere MQ C++ Support)
//  Part:          IMQSTR.HPP
//
//  Description:   "ImqString" class declaration
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


#define ImqString ImqStr

class IMQ_EXPORTCLASS ImqString : public ImqItem {
  // New methods:
  const ImqString concatenate ( const ImqString &, const ImqString & ) const ;
  size_t copyOut1 ( ImqString &, const char ) const ;
  static ImqBoolean lock ( );
  static ImqBoolean unlock ( );
protected :
  char * opszString ;
  size_t ouiSize ;
  // New methods:
  ImqBoolean assign ( const ImqString & );
public :
  // Overloaded "ImqItem" methods:
  virtual ImqBoolean copyOut ( ImqMsg & );
  virtual ImqBoolean pasteIn ( ImqMsg & );
  // New methods:
  ImqString ( );
  ImqString ( const ImqString & );
  ImqString ( const char );
  ImqString ( const char * );
  ImqString ( const void *, const size_t );
  virtual ~ ImqString ( );
  void operator = ( const ImqString & );
  ImqString operator + ( const ImqString & ) const ;
  ImqString operator + ( const char ) const ;
  ImqString operator + ( const char * ) const ;
  ImqString operator + ( const double ) const ;
  ImqString operator + ( const long ) const ;
  friend ImqString operator + ( const char * pszThis,
                                const ImqString & strThat )
    { return (ImqString)pszThis + strThat ; }
  void operator += ( const ImqString & );
  void operator += ( const char );
  void operator += ( const char * );
  void operator += ( const double );
  void operator += ( const long );
  ImqString operator ( ) ( const size_t, const size_t ) const ;
  ImqString operator ( ) ( const size_t ui ) const
    { return operator ( ) ( ui, (size_t)1 ); }
  operator char * ( ) const { return opszString ; }
  char & operator [ ] ( const size_t uiIndex ) const
    { return * ( opszString + uiIndex ); }
  ImqBoolean operator < ( const ImqString & str ) const
    { return this -> compare( str ) < 0 ; }
  ImqBoolean operator > ( const ImqString & str ) const
    { return this -> compare( str ) > 0 ; }
  ImqBoolean operator <= ( const ImqString & str ) const
    { return this -> compare( str ) <= 0 ; }
  ImqBoolean operator >= ( const ImqString & str ) const
    { return this -> compare( str ) >= 0 ; }
  ImqBoolean operator == ( const ImqString & str ) const
    { return this -> compare( str ) == 0 ; }
  ImqBoolean operator != ( const ImqString & str ) const
    { return this -> compare( str ) != 0 ; }
  short compare ( const ImqString & ) const ;
  static ImqBoolean copy ( char *, const size_t, const char *,
                           ImqError &, const char = 0 );
  static ImqBoolean copy ( char *, const size_t, const char *,
                           const char = 0 );
  ImqBoolean copyOut ( char *, const size_t, const char = 0 );
  size_t copyOut ( long & ) const ;
  size_t copyOut ( ImqString &, const char = ' ' ) const ;
  size_t cutOut ( long & );
  size_t cutOut ( ImqString &, const char = ' ' );
  ImqBoolean find ( const ImqString & );
  ImqBoolean find ( const ImqString &, size_t & );
  size_t length ( ) const ;
  ImqBoolean pasteIn ( const double, const char * = "%f" );
  ImqBoolean pasteIn ( const long );
  ImqBoolean pasteIn ( const void *, const size_t );
  ImqBoolean set ( const char *, const size_t );
  size_t storage ( ) const { return ouiSize ; }
  ImqBoolean setStorage ( const size_t );
  size_t stripLeading ( const char = ' ' );
  size_t stripTrailing ( const char = ' ' );
  ImqString upperCase ( ) const ;
} ;


#endif
