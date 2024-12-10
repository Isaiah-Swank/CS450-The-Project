#include "binsearch.h"

int binsearch(int *a, int target, unsigned int size)
{
    int end = size -1;
    int beg = 0;

    int mid = (beg + end) / 2;

    while(beg <= end)
    {
        if(a[mid] > target)
        {
            end = mid - 1;
            mid = (beg + end) / 2;
        }
        else if(a[mid] < target)
        {
            beg = mid + 1;
            mid = (beg + end) / 2;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}