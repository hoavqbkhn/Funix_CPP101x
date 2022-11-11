#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    std::fstream file("donation_total.txt", std::ios_base::app);
    std::string choice = "";
    int sum = 0;
    do{
        printf("QUYEN GOP?\n");
        printf("1.TIEP TUC\n");
        printf("2.KET THUC\n");
        cin >> choice;
        if(choice == "1"){
            printf("VUI LONG NHAP THEO DINH DANG: <TEN> <SO TIEN>:");
            std::string input;
            std::getline(std::cin,input);
            std::getline(std::cin,input);
            stringstream ss(input);
            std::string name;
            int money;
            ss >> name >> money;
            sum += money;
        }
    }while(choice == "1");
    file << sum << endl;
    file.close();

    return 0;
}
