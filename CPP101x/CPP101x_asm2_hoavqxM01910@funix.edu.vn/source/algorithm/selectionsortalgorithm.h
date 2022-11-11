#ifndef SELECTIONSORTALGORITHM_H
#define SELECTIONSORTALGORITHM_H

#include "algorithmabs.h"

class SelectionSortAlgorithm : public SortingArrayAlgorithmAbs
{
public:
    SelectionSortAlgorithm(int* arr, int len);
    ~SelectionSortAlgorithm();

    void solve() override;
    void printOutPut() override;
private:
};

#endif // SELECTIONSORTALGORITHM_H
