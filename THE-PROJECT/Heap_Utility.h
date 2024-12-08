#ifndef HEAP_UTILITY_H
#define HEAP_UTILITY_H

// header files
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "File_Input_Utility.h"
#include "StandardConstants.h"

// data types

typedef struct ContractorStruct
   {
    int licenseNum;
    char businessName[ STD_STR_LEN ];
    char classCode[ MIN_STR_LEN ];
    char classDetail[ STD_STR_LEN ];
    char city[ MIN_STR_LEN ];
    int priority;
   } ContractorType;

typedef struct HeapStruct
   {
    ContractorType *array;

    int size;
   } HeapType;

typedef enum { GET_PRIORITY,
               INITIALIZE_PRIORITY_ENGINE, CLEAR_PRIORITY_ENGINE } PriorityCode;

// prototypes

/*
Name: accessPriority
Process: generates unique value between 1 and 100 (MAX_HEAP_CAPACITY),
         generated value is not repeated during one program run
         Priority Codes:
         INITIALIZE_PRIORITY_ENGINE - sets up priority generating system
         GET_PRIORITY - generates a unique value between 1 and 100
                                                             (MAX_HEAP_CAPACITY)
         CLEAR_PRIORITY_ENGINE - deallocates dynamic memory created
         for the function operation
Function input/parameters: control codes as specified (PriorityCode)
Function output/parameters: none
Function output/returned: value as specified (int)
Device input/---: none
Device output/---: none
Dependencies: rand, malloc w/sizeof, isInArray, free
*/
int accessPriority( PriorityCode code );

/*
Name: addRawDataToHeap
Process: adds data to end of heap, uses bubbleUp to resettle heap,
         allows for display of addition operations,
         returns true if successful and not past limit (MAX_HEAP_CAPACITY),
         false otherwise
Function input/parameters: pointer to heap (HeapType *),
                           contractor license (int),
                           contractor business name, class code (const char *),
                           contractor class detail, city (const char *),
                           priority (int), display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: value as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: setContractorRawData, bubbleUp
*/
bool addRawDataToHeap( HeapType *heap,
                               int ctrctrLicense,
                                   const char *ctrctrBizName,
                                      const char *ctrctrClassCode,
                                          const char *ctrctrClassDetail,
                                              const char *ctrctrCity,
                                               int priority, bool displayFlag );

/*
Name: bubbleUp
Process: recursively implements heap bubble up operation with optional display
         of operations,
         necessary swaps use only two lines of code,
         no interim/temporary value used
Function input/parameters: pointer to heap (HeapType *), current index (int),
                           display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, bubbleUp (recursively)
*/
void bubbleUp( HeapType *heap, int currentIndex, bool displayFlag );

/*
Name: clearHeap
Process: deallocates dynamic data used for heap contents
Function input/parameters: pointer to heap (HeapType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
HeapType *clearHeap( HeapType *heap );

/*
Name: getDataFromFile
Process: uploads data from file with unknown number of data sets,
         has internal Boolean for upload verification,
         returns true if data found and uploaded, false otherwise
Function input/parameters: file name (const char *), display flag (bool)
Function output/parameters: pointer to heap (HeapType *)
Function output/returned: result of file operation (bool)
Device input/hard drive: data from HD
Device output/monitor: if internal Boolean set, displays uploaded values
Dependencies: openInputFile, readStringToDelimiterFromFile,
              checkForEndOfInputFile, readIntegerFromFile,
              readCharacterFromFile, initializeContractorNodeFromData,
              accessPriority, addRawDataToHeap, printf, closeInputFile
*/
bool getDataFromFile( HeapType *heap, const char *fileName, bool displayFlag );

/*
Name: heapIsEmpty
Process: returns true if heap is empty, false othwerwise
Function input/parameters: heap (const HeapType)
Function output/parameters: none
Function output/returned: result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool heapIsEmpty( const HeapType heap );

/*
Name: initializeHeap
Process: allocates memory for heap, and for heap contents
Function input/parameters: none
Function output/parameters: none
Function output/returned: pointer to updated heap (HeapType *)
Device input/---: none
Device output/---: none
Dependencies: malloc w/sizeof
*/
HeapType *initializeHeap();

/*
Name: isInArray
Process: utility function that reports if a specified value
         has been found in a given array
Function input/parameters: pointer to integer array (int *), value (int),
                           size of array (int)
Function output/parameters: none
Function output/returned: result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isInArray( int *array, int value, int arraySize );

/*
Name: removeFromHeap
Process: removes value from heap, resets top of heap,
         then resettles heap,
         allows optional display of operations
Function input/parameters: pointer to heap (HeapType *), display flag (bool)
Function output/parameters: pointer to returned value (Contractor *),
                            pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, trickleDown
*/
void removeFromHeap( ContractorType *returned,
                                             HeapType *heap, bool displayFlag );

/*
Name: setContractorRawData
Process: copies data from raw data to destination pointer
Function input/parameters: license number (int),
                           business name & class code (const char *),
                           class detail & city (const char *),
                           priority (int)
Function output/parameters: destination pointer (ContractorType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcpy
*/
void setContractorRawData( ContractorType *destPtr,
                                 int ctrctrLicense,
                                     const char *ctrctrBizName,
                                        const char *ctrctrClassCode,
                                               const char *ctrctrClassDetail,
                                                        const char *ctrctrCity,
                                                                 int priority );

/*
Name: setContractorStructData
Process: copies data from source node to destination pointer
Function input/parameters: node to be copied (const ContractorType)
Function output/parameters: destination pointer (ContractorType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorRawData
*/
void setContractorStructData( ContractorType *destPtr,
                                                  const ContractorType source );

/*
Name: trickleDown
Process: recursively implements heap trickle down operation
         with optional display of operations,
         necessary swaps use only two lines of code,
         no interim/temporary value used
Function input/parameters: pointer to heap (HeapType *), current index (int),
                           display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, trickleDown (recursively)
Author Note: used four "if" and/or "else if" statements,
             used five inequality tests,
             not including display flag tests,
             this is not required but it should be considered
*/
void trickleDown( HeapType *heap, int currentIndex, bool displayFlag );


#endif  // HEAP_UTILITY_H
