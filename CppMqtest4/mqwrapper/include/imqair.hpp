#ifndef _IMQAIR_HPP_
#define _IMQAIR_HPP_
/* %Z% %W% %I% %E% %U% */

//  Library:       WebSphereMQ
//  Component:     IMQI (WebSphereMQ C++ MQI)
//  Part:          IMQAIR.HPP
//
//  Description:   "ImqAuthenticationRecord" class declaration
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
//


#include <imqmgr.hpp>  // ImqQueueManager

#define ImqAuthenticationRecord ImqAir

class IMQ_EXPORTCLASS ImqAuthenticationRecord : public virtual ImqError {
  ImqAuthenticationRecord * opairNext ;
  ImqAuthenticationRecord * opairPrevious ;
  ImqQueueManager * opmgr ;
  MQLONG olType ;
  ImqString ostrConnectionName ;
  ImqString ostrPassword ;
  ImqString ostrUserName ;
protected :
  // New methods:
  void setNextAuthenticationRecord ( ImqAuthenticationRecord * pair = 0 )
    { opairNext = pair ; }
  void setPreviousAuthenticationRecord ( ImqAuthenticationRecord * pair = 0 )
    { opairPrevious = pair ; }
public :
  // New methods:
  ImqAuthenticationRecord ( );
  virtual ~ ImqAuthenticationRecord ( );
  void operator = ( const ImqAuthenticationRecord & );
  const ImqString & connectionName ( ) const
    { return ostrConnectionName ; }
  ImqQueueManager * connectionReference ( ) const
    { return opmgr ; }
#if defined( MQCNO_VERSION_4 ) || defined( __OS400__ )
  void copyOut ( MQAIR * );
  void clear ( MQAIR * );
#endif
  ImqAuthenticationRecord * nextAuthenticationRecord ( ) const
    { return opairNext ; }
  const ImqString & password ( ) const
    { return ostrPassword ; }
  ImqAuthenticationRecord * previousAuthenticationRecord ( ) const
    { return opairPrevious ; }
  void setConnectionName ( const ImqString & str )
    { ostrConnectionName = str ; }
  void setConnectionName ( const char * psz = 0 )
    { ostrConnectionName = psz ; }
  void setConnectionReference ( ImqQueueManager & mgr )
    { setConnectionReference( & mgr ); }
  void setConnectionReference ( ImqQueueManager * = 0 );
  void setPassword ( const ImqString & str )
    { ostrPassword = str ; }
  void setPassword ( const char * psz = 0 )
    { ostrPassword = psz ; }
  void setType ( const MQLONG lType )
    { olType = (MQLONG)lType ; }
  void setUserName ( const ImqString & str )
    { ostrUserName = str ; }
  void setUserName ( const char * psz = 0 )
    { ostrUserName = psz ; }
  MQLONG type ( ) const
    { return olType ; }
  const ImqString & userName ( ) const
    { return ostrUserName ; }
} ;


#endif
