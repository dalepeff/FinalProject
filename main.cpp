#include <iostream>
#include "Cars.h"
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
    Cars Crs;
    string line;
    ifstream inFile;
    inFile.open("CarList.txt");
    string year, condition, price;
    char make[256];
    char model[256];
    bool correct=false;

    int i=0;

    while (getline( inFile, line ))
        {
            stringstream category( line );
            cin.getline(make,256);
            cin.getline(model, 256);
            getline(category, year);
            stringstream ss(year);
            int intyear;
            ss >> intyear;
            getline( category, condition,  ',' );
            getline( category, price,   ',' );
            stringstream sp(price);
            int intprice;
            sp >> intprice;

                Crs.addCarNode(make, model, intyear, condition, intprice);}



    int QUIT = 6;
    int menu = -1;


    while(menu!=QUIT){

        cout << "======Main Menu======" << endl;
        cout << "1. Add a car to the inventory" << endl;
        cout << "2. Print the dealership's inventory" << endl;
        cout << "3. Search for a car." << endl;
        cout << "4. Change the price of a car." << endl;
        cout << "5. Count the cars" << endl;
        cout << "6. Quit" << endl;

        cin>>menu;
        string junk;
        getline(cin, junk);

        if (menu == 1)
        {
            string insertCondition;
            int insertYear, insertPrice;
            cout<<"Insert info about car."<<endl;
            cout<<"Make: ";
            cin.getline(make,256);
            cout<<"Model: ";
            cin.getline(model,256);
            cout<<"Year: ";
            cin>>insertYear;
            while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> insertYear;
                                }

            cout<<"Condition (New or Used): ";
            cin>>insertCondition;
            if(insertCondition == "New" || insertCondition== "Used" || insertCondition=="new" || insertCondition=="used")
                {
                    correct=true;
                }
            while(correct==false)
            {

                cout<<"Not a valid input, please enter New or Used"<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin>>insertCondition;
            if(insertCondition == "New" || insertCondition== "Used" || insertCondition=="new" || insertCondition=="used")
                {
                    correct=true;
                }
            }
            cout<<"Price: ";
            cin>>insertPrice;
                    while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> insertPrice;}
            cout<<'\n'<<endl;

            Crs.addCarNode(make, model, insertYear, insertCondition, insertPrice);
        }

        if (menu == 2){
            Crs.printCarInventory();
        }

        if (menu == 3){
            int searchcriteria = 0;

            cout<<"Please select search Criteria"<<endl;
            cout<<"1. Year"<<endl;
            cout<<"2. Price"<<endl;
            cout<<"3. Model"<<endl;
            cout<<"4. Make"<<endl;
            cout<<"5. Quit to main menu"<<endl;
            cin >> searchcriteria;
            while(cin.fail()||searchcriteria<1 || searchcriteria>5) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> searchcriteria;
    }

            if (searchcriteria == 1){
                int yearmin, yearmax;
                cout<< "Minimum car year: ";
                cin >> yearmin;
                while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> yearmin;
    }


                cout<< "Max car year: ";
                cin>> yearmax;
                while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> yearmax;
    }
                while(yearmin > yearmax){
                    cout<< "Please enter a max value that is higher than the minimum."<<endl;
                    cin>>yearmax;
                }


                Crs.searchByYear(yearmin, yearmax);}

            if (searchcriteria == 2){
                int pricemin, pricemax;
                cout<< "Minimum price: ";
                cin >> pricemin;
                while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> pricemin;
    }

                cout << "Maximum price: ";
                cin >> pricemax;
                while(cin.fail()) {
                    cout << "Please Enter a valid number." << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> pricemax;
    }
                while(pricemin > pricemax){
                    cout<< "Please enter a max value that is higher than the minimum."<<endl;
                    cin>>pricemax;
                }

                Crs.searchByPrice(pricemin, pricemax);
            }
            if (searchcriteria == 3){
                cout<<"enter model"<<endl;
                cin>>model;
                Crs.searchByModel(model);

            }
            if (searchcriteria == 4){
                cout<<"enter make"<<endl;
                cin>>make;
                Crs.searchByMake(make);
            }
        }

        if (menu==4){
            string model;
            int year;
            cout<<"enter model:";
            cin>>model;
            cout<< "enter year:"<<endl;
            cin >> year;
            Crs.changePrice(model,year);
        }

        if (menu == 5){
            cout<<'\n'<<"The system currently has "<<Crs.countCars()<<" cars."<<'\n'<<endl;
        }

    }
    cout << "Goodbye!" << endl;


    return 0;
}
