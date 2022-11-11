#include "bublesortalgorithm.h"
#include <algorithm>

BubleSortAlgorithm::BubleSortAlgorithm(int *arr, int len)
    : SortingArrayAlgorithmAbs(arr, len)
{

}

BubleSortAlgorithm::~BubleSortAlgorithm()
{
}

void BubleSortAlgorithm::solve()
{
    bool isUnsorted;
    do {
        isUnsorted = false;
        for (int i = 0; i < (mLength - 1); i++) {
            if (mArrayInput[i] > mArrayInput[i + 1]) {
                isUnsorted = true;
                for (; i < (mLength - 1); i++) {
                    if (mArrayInput[i] > mArrayInput[i + 1]) {
                        std::swap(mArrayInput[i], mArrayInput[i + 1]);
                    }
                }
            }
        }
    } while (isUnsorted);
}

void BubleSortAlgorithm::printOutPut()
{
    printf("[BUBLE SORT] :");
    SortingArrayAlgorithmAbs::printOutPut();
    printf("\n");
}
