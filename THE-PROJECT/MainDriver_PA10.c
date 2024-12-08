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
