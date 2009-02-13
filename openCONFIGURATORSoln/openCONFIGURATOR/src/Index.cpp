///////////////////////////////////////////////////////////////////////////////////////////////
//
//  $Header: $
//
// NAME:  ClassNAME
//
// BASE  CLASSES: none
//  
// PURPOSE:  purpose description
//
// AUTHOR:  
//
//  COPYRIGHT NOTICE:
//
//	****************************************************************************

// (c) Kalycito Infotech Private Limited
//
//  Project:      openCONFIGURATOR 
//
//  Description:  
//
//
//  License:
//
//    Redistribution and use in source and binary forms, with or without
//    modification, are permitted provided that the following conditions
//    are met:
//
//    1. Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//    2. Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//    3. Neither the name of Kalycito Infotech Private Limited nor the names of 
//       its contributors may be used to endorse or promote products derived
//       from this software without prior written permission. For written
//       permission, please contact info@kalycito.com.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
//    COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//    POSSIBILITY OF SUCH DAMAGE.
//
//    Severability Clause:
//
//        If a provision of this License is or becomes illegal, invalid or
//        unenforceable in any jurisdiction, that shall not affect:
//        1. the validity or enforceability in that jurisdiction of any other
//           provision of this License; or
//        2. the validity or enforceability in other jurisdictions of that or
//           any other provision of this License.
//
//****************************************************************************/
//
//  REVISION HISTORY:
// $Log:      $
///////////////////////////////////////////////////////////////////////////////////////////////
#include "../Include/Index.h"
#include <stdio.h>

CIndex::CIndex(void)
	{
		int m_SubIndexCount = collectionObj.Count();
	}

CIndex::~CIndex(void)
	{
	}

EPDOType CIndex::getPDOType() 
	{
		return m_PDOType;
	}
void CIndex::setPDOType(EPDOType PDOType)
	{ m_PDOType = PDOType;}
#pragma region MemberFunctions
/**************************************************************************************************
	* Function Name: addSubIndex
    * Description: add the SubIndex in the Index Object
/****************************************************************************************************/

void CIndex::addSubIndex(CSubIndex objSubIndex) 
	{
		int i = collectionObj.Add();
		collectionObj[i] = objSubIndex ;
		m_SubIndexCount= collectionObj.Count();
		
	}
	
/**************************************************************************************************
	* Function Name: deleteSubIndex
    * Description: delete the SubIndex in the Index Object
/****************************************************************************************************/

void CIndex::deleteSubIndex(int SubIndexID) 
	{
		collectionObj.Remove(SubIndexID);
		m_SubIndexCount = collectionObj.Count();
		printf("\n\nAfter Delete - SubIndexCount:%d\n\n", m_SubIndexCount);
	}
	
int CIndex::getNumberofSubIndexes()
	{return collectionObj.Count();}

CSubIndex* CIndex::getSubIndex(int SubIndexId)
	{
		return &collectionObj[SubIndexId];
	}
	CSubIndex* CIndex::getSubIndexbyIndexValue(char* Index)
	{
		int i = 0;
		for(int i =0; i<m_SubIndexCount;i++)
		{
			CSubIndex objSIndex;
			objSIndex = collectionObj[i];
			if(strcmp(objSIndex.getIndexValue(),Index)==0)
				return &collectionObj[i];
		}		
	}
#pragma endregion MemberFunctions