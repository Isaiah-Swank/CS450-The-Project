#include <algorithm>
#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include "binsearch.h"

#define MAX_SIZE 20

TEST(Binsearch, Basic) {
    int a[MAX_SIZE];
    int size = DeepState_IntInRange(0, MAX_SIZE);

    for(int i = 0; i < size, i++)
    {
        a[i] = Deepstate_Int();
    }

    std::sort(std::begin(a), std::begin(a) + size);

    LOG(TRACE) << "size = " << size;
    for(int i = 0; i < size; i++)
    {
        LOG(TRACE) << "a[" << i << "] = " << a[i];
    }

    int t = Deepstate_Int();
    LOG(TRACE) << "R = " << R;

    if(R != -1)
    {
        ASSERT (a[R] == t);
    }
    else
    {
       for(int i = 0; i < size; i++)
       {
        ASSERT (a[i] != t);
       } 
    }
}