// header files
#include "Heap_Utility.h"

// local constants
const int MIN_HEAP_CAPACITY = 100;
const int NON_VALID_PRIORITY = -1;

int accessPriority( PriorityCode code )
{
  // initialize variables
  static int *intArray = NULL;
  static int arraySize = 0;
  int randNum, currentIndex;

  // check for INITIALIZE_PRIORITY_ENGINE code
  if( code == INITIALIZE_PRIORITY_ENGINE )
  {
    // create the new int array and fill it with NON_VALID_PRIORITY
    intArray = ( int *)malloc( MIN_HEAP_CAPACITY * sizeof( int ) );

    // iterate through the array
    for( currentIndex = 0; currentIndex < MIN_HEAP_CAPACITY; currentIndex++ )
    {
      // put NON_VALID_PRIORITY in each index of the array
      intArray[ currentIndex ] = NON_VALID_PRIORITY;
    }
  }
  // check for GET_PRIORITY code
  if( code == GET_PRIORITY )
  {
    // generate random number between 1 and 100
    randNum = rand() % MIN_HEAP_CAPACITY + 1;

    // check if the random value has already been used ( in array )
    while( isInArray( intArray, randNum, MIN_HEAP_CAPACITY ) )
    {
      // generate another random number between 1 and 100
      randNum = rand() % MIN_HEAP_CAPACITY + 1;

    }
    // add value to array
    intArray[ arraySize ] = randNum;

    // increment arraySize
    arraySize++;

    // return the new value
    return randNum;
  }

  // check for CLEAR_PRIORITY_ENGINE code
  if( code == CLEAR_PRIORITY_ENGINE )
  {
    // free the newly created ADT
    free( intArray );


  }
  // return NON_VALID_PRIORITY
  return NON_VALID_PRIORITY;

}

bool addRawDataToHeap( HeapType *heap,
                               int ctrctrLicense,
                                   const char *ctrctrBizName,
                                      const char *ctrctrClassCode,
                                          const char *ctrctrClassDetail,
                                              const char *ctrctrCity,
                                               int priority, bool displayFlag )
{
  // initialize variables

  // check to make sure the size has not been reached
  if( heap->size < MIN_HEAP_CAPACITY )
  {
    // add new data to the heap size index
    setContractorRawData( &heap->array[ heap->size ], ctrctrLicense,
            ctrctrBizName, ctrctrClassCode, ctrctrClassDetail, ctrctrCity,
                                          heap->array[ heap->size ].priority );

    // increment the size
    heap->size = heap->size + 1;

    // call bubbleUp to resort the data
    bubbleUp( heap, heap->size - 1, displayFlag );

    // return true
    return true;
  }
  // else return false
  return false;

}

void bubbleUp( HeapType *heap, int currentIndex, bool displayFlag )
{
  // initialize variables
  ContractorType currentNode = heap->array[ currentIndex ];
  int parentIndex = ( currentIndex - 1 ) / 2;

  // check if parent has a higher priority # than the current AND parentIndex >0
  if( currentNode.priority < heap->array[ parentIndex ].priority
                                                            && parentIndex >= 0 )
  {
    // if displayFlag
    if( displayFlag )
    {
      // print the beginning bubble up message
      printf( "   - Bubble up swap:\n" );

    }
    // swap the indicies
    setContractorStructData( &heap->array[ currentIndex ],
                                                   heap->array[ parentIndex ] );

    setContractorStructData( &heap->array[ parentIndex ], currentNode );

    // if displayFlag
    if( displayFlag )
    {
      // print the bubble up child message
      printf( "\t- moving up child: %s (%d)\n",
                          heap->array[ currentIndex ].businessName,
                                         heap->array[ currentIndex ].priority );

      // print the bubble up parent message
      printf( "\t- moving down parent: %s (%d)\n",
                            heap->array[ parentIndex ].businessName,
                                          heap->array[ parentIndex ].priority );
    }

    // recursive call to the parent
    bubbleUp( heap, parentIndex, displayFlag );
  }
}

HeapType *clearHeap( HeapType *heap )
{
  // initialize variables

  // free the array in the heap
  free( heap->array );

  // free the heap
  free( heap );

  // return NULL
  return NULL;

}

bool getDataFromFile( HeapType *heap, const char *fileName, bool displayFlag )
{
  // initialize variables

  char bizName[ STD_STR_LEN ], classCode[ MIN_STR_LEN ];
  char classDet[ STD_STR_LEN ], city[ MIN_STR_LEN ];
  char junkStr[ MAX_STR_LEN ];
  int licNum = 0, currentIndex = 0, priorityNum;


  // open input file
  if( openInputFile( fileName ) )
  {

  	// if verbose ( displayFlag )
    if( displayFlag )
    {
      // print the beginning loading line
      printf( "Begin Loading Data From File . . .\n" );
    }

  	// access priority initialize
    priorityNum = accessPriority( INITIALIZE_PRIORITY_ENGINE );

  	// read and ignore header line
    readStringToLineEndFromFile( junkStr );

  	// get license number, read prime
    licNum = readIntegerFromFile();

  	// while not at the end of the input file
    while( !checkForEndOfInputFile() )
    {
  		// remove comma
      readCharacterFromFile();

  		// get business name
  			// readStringToDelimeter
      readStringToDelimiterFromFile( COMMA, bizName );

  		// get class code
      readStringToDelimiterFromFile( COMMA, classCode );

  		// get class detail
      readStringToDelimiterFromFile( COMMA, classDet );

  		// get city
  			// readStringToLineEnd
        readStringToLineEndFromFile( city );

  		//  get priority # : access priority get priority
      priorityNum = accessPriority( GET_PRIORITY );

  		// if verbose
      if( displayFlag )
      {
  			// print the current index + 1
        printf( "%d) ", currentIndex + 1 );

        // print the licenseNum
        printf( "License Number: %d, ", licNum );

        // print the businessName
        printf( "Business Name: %s, ", bizName );

        // print the class code
        printf( "Class Code: %s, ", classCode );

        // print the class detail
        printf( "Class Detail: %s, ", classDet );

        // print the city
        printf( "City: %s, ", city );

        // print the priority number
        printf( "Priority: %d\n", priorityNum );
      }

  		// add rawdata to heap
      if( addRawDataToHeap( heap, licNum, bizName, classCode, classDet,
                                              city, priorityNum, displayFlag ) )
      {
  		    // get license number / reprime
          licNum = readIntegerFromFile();

  		    // increment index
          currentIndex++;
      }

    }
    // close input file
    closeInputFile();

    // if displayFlag
    if( displayFlag )
    {
      // print end of loading input message
      printf( ". . . End Loading Data From File\n" );
    }

    // return true
    return true;
  }
  // else return false
  return false;

}

bool heapIsEmpty( const HeapType heap )
{
  // initialize variables

  // return if the heap is empty
  return ( heap.size == 0 );

}

HeapType *initializeHeap()
{
  // initialize variables/ allocate memory for new HeapType
  HeapType *newHeap = ( HeapType * )malloc( sizeof( HeapType * ) );

  // set the size for heap to 0
  newHeap->size = 0;

  // allocate the memory for the ContractorType array
  newHeap->array = ( ContractorType * )malloc( MIN_HEAP_CAPACITY *
                                                   sizeof( ContractorType * ) );

  // return the new HeapType
  return newHeap;

}

bool isInArray( int *array, int value, int arraySize )
{
  // initialize variables
  int currentIndex;

  // iterate through the array
  for( currentIndex = 0; currentIndex < arraySize; currentIndex++ )
  {
    // check if the current indexes priority value matches the value parameter
    if( array[ currentIndex ] == value )
    {
      // if it matches, return true
      return true;

    }
  }

  // else return false
  return false;

}

void removeFromHeap( ContractorType *returned,
                                             HeapType *heap, bool displayFlag )
{
  // initialize variables

  // copy the top of the heap to the return parameter
  setContractorStructData( returned, heap->array[ 0 ] );

  // set the value at the bottom of the heap to the top of the heap
  setContractorStructData( &heap->array[ 0 ], heap->array[ heap->size ] );

  // reduce the size by one
  heap->size = heap->size - 1;

  // call trickleDown to resort the heap
  trickleDown( heap, 0, displayFlag );

}

void setContractorRawData( ContractorType *destPtr,
                                 int ctrctrLicense,
                                     const char *ctrctrBizName,
                                        const char *ctrctrClassCode,
                                               const char *ctrctrClassDetail,
                                                        const char *ctrctrCity,
                                                                 int priority )
{
  // initialize variables

  // copy the licenseNum
  destPtr->licenseNum = ctrctrLicense;

  // copy the businessName
  strcpy( destPtr->businessName, ctrctrBizName );

  // copy the classCode
  strcpy( destPtr->classCode, ctrctrClassCode );

  // copy the classDetail
  strcpy( destPtr->classDetail, ctrctrClassDetail );

  // copy the city
  strcpy( destPtr->city, ctrctrCity );

  // copy the priority
  destPtr->priority = priority;

}

void setContractorStructData( ContractorType *destPtr,
                                                  const ContractorType source )
{
  // call the setContractorRawData
  setContractorRawData( destPtr, source.licenseNum, source.businessName,
                                        source.classCode, source.classDetail,
                                                 source.city, source.priority );

}

void trickleDown( HeapType *heap, int currentIndex, bool displayFlag )
{
  // initialize variables
  int leftIndex, rightIndex;
  ContractorType parent = heap->array[ currentIndex ];

  // find the left and right child indicies
  leftIndex = ( currentIndex * 2 ) + 1;
  rightIndex = ( currentIndex * 2 ) + 2;

  // check for left AND right indicies less than array size
  if( leftIndex < heap->size && rightIndex < heap->size )
  {
    // if displayFlag
    if( displayFlag )
    {
      // print the trickle down starting message
      printf( "   - Trickle down swap:\n");

    }
    // check for left OR right priority better ( smaller ) than currentIndex
    if( heap->array[ leftIndex ].priority < parent.priority ||
                          heap->array[ rightIndex ].priority < parent.priority )
    {
      // if left is smaller than right
      if( heap->array[ leftIndex ].priority < heap->array[ rightIndex].priority)
      {
        // swap with the left child
        setContractorStructData( &heap->array[ currentIndex ],
                                                      heap->array[ leftIndex] );
        setContractorStructData( &heap->array[ leftIndex ], parent );

        // check for display flag
        if( displayFlag )
        {
          // print the trickle down message for current
          printf( "\t- moving down parent: %s (%d)\n",
                            heap->array[ currentIndex ].businessName,
                                         heap->array[ currentIndex ].priority );

          // print trickle down message for left child
          printf( "\t- moving up left child: %s (%d)\n",
                            heap->array[ leftIndex ].businessName,
                                            heap->array[ leftIndex ].priority );
        }

        // recurse to the left child
        trickleDown( heap, leftIndex, displayFlag );
      }
      // else assume right smaller, swap with right
      setContractorStructData( &heap->array[ currentIndex ],
                                                    heap->array[ rightIndex ] );
      setContractorStructData( &heap->array[ rightIndex ], parent );

      // recurse to the right child
      trickleDown( heap, rightIndex, displayFlag );

    }
  }
  // check for only the left child less than array size ( no right child )
  if( leftIndex < heap->size )
  {
    // check if left child priority is better than currentIndex
    if( heap->array[ leftIndex ].priority < parent.priority )
    {
      // swap with the left child
      setContractorStructData( &heap->array[ currentIndex ],
                                                    heap->array[ leftIndex] );
      setContractorStructData( &heap->array[ leftIndex ], parent );

      // recurse to the left child
      trickleDown( heap, leftIndex, displayFlag );
    }
  }
 }


#include "Heap_Utility.h"
#include <time.h>

int main()
   {
    HeapType *heapTest;
    ContractorType testVal;
    int index;
    char dispChar;
    char fileName[ STD_STR_LEN ];
    bool displayFlag = false;

    // seed random number generator
    srand( time( NULL ) );

    printf( "\nHEAP CLASS TEST\n" );
    printf( "===============\n\n" );

    printf(  "Enter file name: " );
    scanf( "%s", fileName );
    fflush( stdin );

    printf(  "Show Heap Operations (y/n)? " );
    scanf( "%c", &dispChar );
    fflush( stdin );

    if( dispChar == 'y' || dispChar == 'Y' )
       {
        displayFlag = true;
       }

    heapTest = initializeHeap();

    if( getDataFromFile( heapTest, fileName, displayFlag ) )
       {
        for( index = 0; index < 5; index++ )
           {
            removeFromHeap( &testVal, heapTest, displayFlag );
            printf( "\nBusiness: %s removed\n", testVal.businessName );
           }
       }

    else
       {
        printf( "\nData not found - Program aborted\n" );
       }

    printf( "\nProgram End\n" );

    heapTest = clearHeap( heapTest );

    return 0;
   }
