#include "selectionsortalgorithm.h"
#include <algorithm>

SelectionSortAlgorithm::SelectionSortAlgorithm(int *arr, int len)
    :SortingArrayAlgorithmAbs(arr, len)
{

}

SelectionSortAlgorithm::~SelectionSortAlgorithm()
{

}

void SelectionSortAlgorithm::solve()
{
    int i, j, minIndex;
    for (i = 0; i < mLength-1; i++)
    {

        // Find the minimum element in
        minIndex = i;
        for (j = i+1; j < mLength; j++){
            if (mArrayInput[j] < mArrayInput[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if(minIndex != i)
            std::swap(mArrayInput[minIndex], mArrayInput[i]);
    }
}

void SelectionSortAlgorithm::printOutPut()
{
    printf("[SELECTION SORT] :");
    SortingArrayAlgorithmAbs::printOutPut();
    printf("\n");
}
