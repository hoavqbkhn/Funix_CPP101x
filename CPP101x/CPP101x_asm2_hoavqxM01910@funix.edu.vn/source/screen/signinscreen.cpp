#include "common.h"
#include "signinscreen.h"

#include "algorithm/bublesortalgorithm.h"
#include "algorithm/selectionsortalgorithm.h"

const static int ID_LENGTH  = 8;

static int ARRAY[ID_LENGTH] = {1,2,3,4,5,7,8,6};

SignInScreen::SignInScreen()
{
    mInputID = new int[ID_LENGTH];
    mDefaultID = new int[ID_LENGTH];
    mDefaultID = ARRAY;
}

SignInScreen::~SignInScreen()
{
    if(mInputID){
        delete mInputID;
        mInputID = nullptr;
    }

}

void SignInScreen::process()
{
    do{
        printf("NHAP MA SO CA NHAN GOM %d CHU SO:\n", ID_LENGTH);
        for(int i = 0; i < ID_LENGTH; i++){
            std::string input = "";
            int integer = ERROR_INVALID_NUMBER_LETTER;
            do{
                input.clear();
                printf("NHAP SO THU [%d]: ", i+1);
                cin >> input;
                integer = validateNumberLetterInput(input);
            }while(integer == ERROR_INVALID_NUMBER_LETTER);
            mInputID[i] = integer;
        }
    }while(!isValidInput());

    system("pause");
}

bool SignInScreen::isValidInput()
{
    printf("MANG NHAP VAO TRUOC KHI SAP XEP:");
    printArray(mInputID, ID_LENGTH);
    printf("\n");

    //using selection sort for input from screen
    auto selectionSort = std::make_shared<SelectionSortAlgorithm>(mInputID, ID_LENGTH);
    selectionSort->solve();
    selectionSort->printOutPut();
    int *selectionSortArray = selectionSort->getOutput();

    printf("MA SO CA NHAN TRUOC KHI SAP XEP:");
    printArray(mDefaultID, ID_LENGTH);
    printf("\n");

    //using buble sort for default personal key
    auto bubleSort = std::make_shared<BubleSortAlgorithm>(mDefaultID, ID_LENGTH);
    bubleSort->solve();
    bubleSort->printOutPut();
    int *bubleSortArray = bubleSort->getOutput();

    for(int i = 0; i < ID_LENGTH; i++){
        if(bubleSortArray[i] != selectionSortArray[i]){
            return false;
        }
    }

    return true;
}
