#include "common.h"
#include "configuration.h"
#include "signinscreen.h"

#include "algorithm/bublesortalgorithm.h"
#include "algorithm/selectionsortalgorithm.h"



SignInScreen::SignInScreen()
{

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
    if(!Configuration::getInstance().readPersonalKeyFromFile()){
        system("pause");
        exit(0);
    }

    mInputID = new int[Configuration::getInstance().personalKeyLength()];
    mDefaultID = Configuration::getInstance().personalKeyFromFile();
    do{
        printf("NHAP MA SO CA NHAN GOM %d CHU SO:\n", Configuration::getInstance().personalKeyLength());
        for(int i = 0; i < Configuration::getInstance().personalKeyLength(); i++){
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
}

bool SignInScreen::isValidInput()
{
    printf("MANG NHAP VAO TRUOC KHI SAP XEP:");
    printArray(mInputID, Configuration::getInstance().personalKeyLength());
    printf("\n");

    //using selection sort for input from screen
    auto selectionSort = std::make_shared<SelectionSortAlgorithm>(mInputID, Configuration::getInstance().personalKeyLength());
    selectionSort->solve();
    selectionSort->printOutPut();
    int *selectionSortArray = selectionSort->getOutput();

    printf("MA SO CA NHAN TRUOC KHI SAP XEP:");
    printArray(mDefaultID, Configuration::getInstance().personalKeyLength());
    printf("\n");

    //using buble sort for default personal key
    auto bubleSort = std::make_shared<BubleSortAlgorithm>(mDefaultID, Configuration::getInstance().personalKeyLength());
    bubleSort->solve();
    bubleSort->printOutPut();
    int *bubleSortArray = bubleSort->getOutput();

    for(int i = 0; i < Configuration::getInstance().personalKeyLength(); i++){
        if(bubleSortArray[i] != selectionSortArray[i]){
            return false;
        }
    }

    return true;
}
