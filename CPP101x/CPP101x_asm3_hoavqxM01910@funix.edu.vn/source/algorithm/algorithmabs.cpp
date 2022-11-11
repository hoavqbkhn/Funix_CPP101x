#include <iostream>

#include "algorithmabs.h"
#include "common.h"



SortingArrayAlgorithmAbs::~SortingArrayAlgorithmAbs()
{
    if(mArrayInput){
        delete mArrayInput;
        mArrayInput = nullptr;
    }
}

int *SortingArrayAlgorithmAbs::getOutput() const
{
    return mArrayInput;
}

void SortingArrayAlgorithmAbs::printOutPut()
{
    printArray(mArrayInput, mLength);
}

SortingArrayAlgorithmAbs::SortingArrayAlgorithmAbs(int *arr, int len):
    mLength(len)
{
    mArrayInput = new int[len];
    for(auto i = 0; i < len; i++){
        mArrayInput[i] = arr[i];
    }
}
