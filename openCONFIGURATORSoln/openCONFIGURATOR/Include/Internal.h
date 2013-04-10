/**
 *****************************************************************************************************
 \file			Internal.h

 \brief			Handles function definitions and constant defintions used internally
 *****************************************************************************************************
 */

/*

 (c) Kalycito Infotech Private Limited

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
#ifndef Internal_h
#define Internal_h

/****************************************************************************************************/
/* Includes */

#include <stddef.h>
#include <string>
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>
#include "Exports.h"
#include "Index.h"
#include "ProjectSettings.h"
#include "ProcessImage.h"
#include "Declarations.h"
#include "Node.h"
#include "IndexCollection.h"
#include "NetworkManagement.h"
#include "Exception.h"

/*************************************************************************************************/
/* Defines */

#define TOOL_VERSION "1.2.2"
#define LAST_TOOL_VERSION "1.2.1"
#define PREV_TOOL_VERSION_1 "1.1.0"
#define PREV_TOOL_VERSION_2 "1.0.1"
#define PREV_TOOL_VERSION_3 "1.0.0"
#define PREV_TOOL_VERSION_4 "1.1.1"
#define PREV_TOOL_VERSION_5 "1.1.2"
#define PREV_TOOL_VERSION_6 "1.2.0"
#define TOOL_INTER_REL_VERSION_1 "1.1.2.1"
#define TOOL_INTER_REL_VERSION_2 "1.1.2.2"
#define TOOL_INTER_REL_VERSION_3 "1.1.2.3"
#define TOOL_INTER_REL_VERSION_4 "1.1.2.4"
#define TOOL_INTER_REL_VERSION_5 "1.1.2.5"
#define ALLOC_BUFFER 5
#define INDEX_LEN 5
#define SUBINDEX_LEN 3
#define RANGE_INDEX 3
#define STR_ALLOC_BUFFER 1
#define MAX_PI_SIZE 4064
#define PROJECT_FILE_NAME 500
#define LINUX_INSTALL_DIR "/usr/share/openCONFIGURATOR-"TOOL_VERSION
#define LINUX_INSTALL_DIR_LEN 50
#define BUILD_COMMENT "This file was autogenerated by openCONFIGURATOR-"TOOL_VERSION" on "

#define INCLUDE_GUARD_CHECK "#ifndef XAP_h"
#define INCLUDE_GUARD_START "#define XAP_h"
#define INCLUDE_GUARD_END "#endif"

#define EPL_NODEASSIGN_NODE_EXISTS      0x00000001L // Bit 0
#define EPL_NODEASSIGN_NODE_IS_CN       0x00000002L // Bit 1
#define EPL_NODEASSIGN_START_CN         0x00000004L // Bit 2
#define EPL_NODEASSIGN_MANDATORY_CN     0x00000008L // Bit 3
#define EPL_NODEASSIGN_KEEPALIVE        0x00000010L //currently not used in EPL V2 standard
#define EPL_NODEASSIGN_SWVERSIONCHECK   0x00000020L // Bit 5
#define EPL_NODEASSIGN_SWUPDATE         0x00000040L // Bit 6
#define EPL_NODEASSIGN_ASYNCONLY_NODE   0x00000100L // Bit 8
#define EPL_NODEASSIGN_MULTIPLEXED_CN   0x00000200L // Bit 9
#define EPL_NODEASSIGN_RT1              0x00000400L // Bit 10
#define EPL_NODEASSIGN_RT2              0x00000800L // Bit 11
#define EPL_NODEASSIGN_MN_PRES          0x00001000L // Bit 12
#define EPL_NODEASSIGN_CHAINED_CN       0x00004000L // Bit 14
#define EPL_NODEASSIGN_VALID            0x80000000L // Bit 31
/************************************************************************************************/
/* Enumerations */

typedef enum
{
	ADD = 0, DELETE
} EOperation;

/************************************************************************************************/
/* structure */

#define BUILDTIME_BUF_LEN 80

typedef struct
{
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[BUILDTIME_BUF_LEN];
} sBuildTime;

/************************************************************************************************/
/* Externs */

extern int iConfigDate;
extern int iConfigTime;
extern UINT32 uiCycleNumber;

/************************************************************************************************/
/* Global variables */

static const int gSimpleArrSize = 19;
static const UINT32 uiPreScalar = 0;

/****************************************************************************************************/
/* Function Declarations */

char* ConvertToUpper(char* str);
char* IntToAscii(long value, char* result, INT32 base);
bool CheckIfNotPDO(char* Index);
bool CheckIfNotPDO(char* Index);
void ProcessUniqueIDRefs();
char* SubString(char* str, INT32 startPos, INT32 len);
char* Reverse(char* str);
ocfmRetCode ProcessPDONodes();
ocfmRetCode ProcessPDONodes(bool isBuild);
ocfmRetCode GenerateMNOBD(bool isBuild);
bool CheckIfManufactureSpecificObject(char* Index);
bool IsAscii(char c);
INT32 LenOfCNBuffer(char* Buffer);
char* PadLeft(char* str, char padChar, INT32 padLength);
unsigned long HexToInt(char *a);
Index* GetMNIndexValues(char* Index);
bool CheckAllowedCNIndexes(char* indexValue);
bool CheckBlockedMNIndexes(char* indexValue);
//TODO: To be removed. Convert cdc to binary
INT32 ConvertCdcToBinary(char* fileName, char* tempFile);
char* GetParameterAccess(char* access);
bool CheckEndElement(INT32 varNodeType, char* element, char* compareWith);
bool CheckStartElement(INT32 varNodeType, char* element, char* compareWith);
bool CheckifSimpleDT(char* Name, char* size);
char* GetPIName(INT32 varNodeID);
void SetIndexAttributes(xmlTextReaderPtr reader, Index* objIndex,
		bool& hasPDO);
void SetSubIndexAttributes(xmlTextReaderPtr reader, SubIndex* objSubIndex);
void SetDataTypeAttributes(xmlTextReaderPtr reader, DataType* objDataType);
char* ConvertToHexformat(char* hexValue, INT32 padLength, bool doPadding);
INT32 GetCNDataLen(char* Buffer);
bool CheckIfDataTypeExists(char* dtVal, INT32 NodeID);
bool CheckIfMappingPDO(char* Index);
bool CheckIfHex(char* value);
void WriteXAPElements(ProcessImage piCol[], xmlTextWriterPtr& writer,
		INT32 VarCount, EPIDirectionType piType);
void StartXAPxml(xmlTextWriterPtr& writer, xmlDocPtr& doc);
void EndWrtitingXAP(xmlTextWriterPtr& writer, char* fileName, xmlDocPtr& doc);
bool CheckIfSubIndexExists(INT32 varNodeID, NodeType varNodeType, char* indexID,
		char* subIndexID);
ocfmRetCode ProcessProjectXML(xmlTextReaderPtr reader, char* pjtPath);
bool IfVersionNumberMatches(xmlTextReaderPtr reader);
bool SetProjectSettingsAuto(xmlTextReaderPtr reader);
bool SetProjectSettingsCommunication(xmlTextReaderPtr reader);
INT32 GetConfigDate();
INT32 GetConfigTime();
bool GetandCreateNode(xmlTextReaderPtr reader, char* pjtPath);
bool SaveProjectXML(char* ProjectPath, char* ProjectName);
void SetSIdxValue(char* Idx, char* SIdx, char* value,
		IndexCollection * objIdxCol, INT32 varNodeId, NodeType varNodeType,
		bool setDefaultValue);
ocfmRetCode AddOtherRequiredCNIndexes(INT32 varNodeId);
void CreateMNPDOVar(INT32 Offset, INT32 dataSize, IEC_Datatype dtenum,
		PDOType pdoType, Node *objNode);
INT32 GetNodeTotalIndexSubIndex(INT32 varNodeID);
INT32 ReverseData(UINT8 *acTemp1, UINT8 *acTemp2, UINT32 size);
char* StringToUpper(char* str);
void SetFlagForRequiredCNIndexes(INT32 varNodeId);
void UpdateCNCycleTime(IndexCollection *objIdxCol, char* cycleTime);
void UpdateNumberOfEnteriesSIdx(Index *objIndex, NodeType varNodeType);
//INT32 GetDataSize(char* dataTypeVal);
bool CheckIfStringDatatypes(char* dataTypeValue);
bool CheckIfDataTypeByNameExists(char* dtName, INT32 iNodeID);
ocfmRetCode AddOtherMNIndexes(INT32 varNodeID);
void AuotgenerateOtherIndexs(Node* objNode);
void UpdatedCNDateORTime(Index* pobjMNIndex, INT32 iNodeId, DateTime eDT);
void CopyPDODefToAct(INT32 iNodeID, NodeType varNodeType);
void CopyMNPropDefToAct(INT32 iNodeID, NodeType varNodeType);
void CopySubIndexDefToAct(INT32 iNodeID, NodeType varNodeType, bool bForce,
		char *indexId, char *subIndexId);
void CopyIndexDefToAct(INT32 iNodeID, NodeType varNodeType, char *indexId);
void SetFlagForRequiredMNIndexes(INT32 iNodeId);
bool CheckAllowedDTForMapping(char* dtName);
void SetFeatures(xmlTextReaderPtr reader, Feature* stFeature);
Index GetPDOIndexByOffset(Index* objIndex);
char* SetNodeAssigmentBits(Node* objNode);
char* GetLastAvailableCycleNumber();
ocfmRetCode RecalculateMultiplex();
void CheckAndCorrectName(char* checkName);
void CheckAndReAssignMultiplex(INT32 iCNNodeId, char* cycleValue);
ocfmRetCode CheckMutliplexAssigned();
UINT32 GetFreeCycleNumber(UINT32 uiCycleNumber);
bool IsMultiplexCycleNumberContinuous(UINT32 uiCycleNumber);
void CalculateCNPollResponse(INT32 iNodeID, NodeType varNodeType);
ocfmRetCode CheckUpperAndLowerLimits(char* lowLimit, char* highLimit);
ocfmRetCode AddSubobject(INT32 iNodeID, NodeType enumNodeType,
		char* pbIndexID);
SubIndex* GetMNSubIndexValues(char* Index, char* subIndex);
void UpdateCNAsyncMTUsize(IndexCollection *objIdxCol, char* asyncMTUsize);
void UpdateCNMultiPrescal(IndexCollection *objIdxCol, char* multiPrescal);
bool CheckIfValueZero(char* Value);
INT32 GetDecimalValue(char* Value);
void UpdateCNNodeAssignment(Node* objNode);
void ResetMultiplexedCNForceCycle();
bool CheckIfMultiplexedCNExist();
void CopyCustomErrorString(ocfmRetCode* stRet, char* pcCustomErrString);
void UpdateCNMultipleCycleAssign(Node* objNode);
void UpdateMNNodeAssignmentIndex(Node *objNode, INT32 cnCount, char* varIndex,
		bool allowMNSubindex);
void RecalculateCNPresTimeout(char* subIndexId);
bool ValidateCNPresTimeout(char* subIndexId, char* checkValue);
void CopyOldNodeIdAssignmentObject(Node* objNode, INT32 iOldNodeId);
void CopyOldNodeIdAssignmentObjectSubindex(Node* objNode, INT32 iOldNodeId,
		char* varIndex);
bool CheckAccessTypeForInclude(char* accesstype);
SubIndex* DuplicateSubIndexObject(SubIndex* objSubindex);
void EnableDisableMappingPDO(IndexCollection* objIdxCol, Index* objIndex,
		char* Buffer, bool enableFlag);
void FormatCdc(IndexCollection *objIndexCollection, char* Buffer1,
		FILE* fileptr, NodeType varNodeType);
bool IsDefaultActualNotEqual(BaseIndex* baseIndexObject);
bool ReactivateMappingPDO(IndexCollection* objIndexCol, Index* objIndex);
void BRSpecificFormatCdc(IndexCollection *objIndexCollection, char* Buffer1,
		FILE* fileptr, NodeType varNodeType, INT32 iNodeId);
void BRSpecificGetIndexData(Index* objIndex, char* Buffer, INT32 iNodeId);
INT32 BRSpecificgetCNsTotalIndexSubIndex(INT32 iNodeID);
void UpdateCNSoCTolerance(IndexCollection *objIdxCol, char* socTolerance);
INT32* ArrangeNodeIDbyStation();
void SortNodeID(INT32 *iNodeIDColl, INT32 iColSize);
bool IsPresMN();
void SetPresMNNodeAssigmentBits();
bool CheckToolVersion(char* currentToolVersion);
void UpdatePreqActLoad(Node* objNode, AutoGenerate pjtSetting);
void UpdatePresActLoad(Node* objNode);
void UpdateCNPresMNActLoad(Node* objNode);
void UpdateCNVisibleNode(Node* objNode);
bool ISCNNodeAssignmentValid(Node* objNode);
bool CopyMNSubindexToCN(Node* objNode, char *Index, char *subIndex);
void CalculatePayload();
void SetCNLossObjects(INT32 iNodeID, NodeType varNodeType);
void ResetAllSubIndexFlag(Index *objIndex);
ocfmRetCode SetSubIndexAttributesByAttribute(INT32 iNodeID,
		NodeType varNodeType, char* indexID, char* subIndexID,
		AttributeType attributeType, char* inAttributeValue);
void SetBuildTime();
const char* GetBuildTime();
ocfmRetCode ParseFile(char* fileName, INT32 varNodeID, NodeType varNodeType);
char* ConvertStringToHex(char* actString);

#endif // internal_h
