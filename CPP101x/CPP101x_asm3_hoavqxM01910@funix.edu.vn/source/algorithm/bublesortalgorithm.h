#ifndef BUBLESORTALGORITHM_H
#define BUBLESORTALGORITHM_H
#include "algorithm/algorithmabs.h"

class BubleSortAlgorithm : public SortingArrayAlgorithmAbs
{
public:
    BubleSortAlgorithm(int* arr, int len);
    ~BubleSortAlgorithm();

    void solve() override;
    void printOutPut() override;

private:
};

#endif // BUBLESORTALGORITHM_H
