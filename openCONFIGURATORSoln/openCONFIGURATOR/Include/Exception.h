/**
 ******************************************************************************
 \file		Exception.h

 \brief		This file contains the class declaration that is used to throw exception to the GUI when an error occurs
 ******************************************************************************
 */

/*

 � Kalycito Infotech Private Limited

 License:

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.

 3. Neither the name of Kalycito Infotech Private Limited nor the names of 
 its contributors may be used to endorse or promote products derived
 from this software without prior written permission. For written
 permission, please contact info@kalycito.com.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

 Severability Clause:

 If a provision of this License is or becomes illegal, invalid or
 unenforceable in any jurisdiction, that shall not affect:
 1. the validity or enforceability in that jurisdiction of any other
 provision of this License; or
 2. the validity or enforceability in other jurisdictions of that or
 any other provision of this License.

 ****************************************************************************/
#ifndef exception_h
#define exception_h

/****************************************************************************************************/
/* Includes */

#include "Declarations.h"

/**
 ******************************************************************************************************
 \class			ocfmException
 \brief			This function handles the exception error messages		

 ******************************************************************************************************/
class ocfmException: public std::exception
{
	public:
		ocfmException(void);
		~ocfmException(void) throw ();
	public:
		ocfmRetCode _ocfmRetCode;		/**< Usage to be documented */
	public:
		/*****************************************************************************/
		/**
		 \brief		This function shall be used to copy the error statment string(corresponding to the given error code parameter) to the _ocfmRetCode.errorString member
		 
		 \param		errCode		 Enum Variable of ConfiguratorErrors to hold the error code		

		 \return	void
		 */
		/*****************************************************************************/
		void OCFMException(ConfiguratorErrors errCode);
};

#endif // exception_h
