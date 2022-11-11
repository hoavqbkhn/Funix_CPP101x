#ifndef ALGORITHMABS_H
#define ALGORITHMABS_H


class SortingArrayAlgorithmAbs
{
public:
    SortingArrayAlgorithmAbs(int* arr, int len);
    virtual ~SortingArrayAlgorithmAbs();

    virtual void solve() = 0;

    int* getOutput() const;
    virtual void printOutPut();

protected:
    int* mArrayInput;
    int mLength;

};

#endif // ALGORITHMABS_H
