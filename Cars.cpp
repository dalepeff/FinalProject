#include "Cars.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <sstream>
#include <limits>

using namespace std;

Cars::Cars()
{
    //ctor
    root = NULL;
}

Cars::~Cars()
{
    //dtor
}

void Cars::addCarNode(std::string make, std::string model, int year, std::string condition, int price){

    CarNode *temp = root;
    CarNode *node = new CarNode;
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->make = make;
    node->model = model;
    node->year = year;
    node->condition = condition;
    node->price = price;
    CarNode *parent = NULL;

    while (temp != NULL){
        parent = temp;
        if (node->year > temp->year){
            temp = temp->leftChild;}
        else{
            temp = temp->rightChild;}
    }
        if (parent == NULL){
            root = node;}
        else if (node->year > parent->year){
            parent->leftChild = node;
            node->parent = parent;
        }
        else{
            parent->rightChild = node;
            node->parent = parent;
        }
}

void Cars::printCarInventory(){
    printCarInventory(root);
}


void Cars::printCarInventory(CarNode *node){
    if(node->leftChild != NULL){
            Cars::printCarInventory(node->leftChild);}
        cout<<"Make: "<<node->make<<" Model: "<<node->model<<" Year: "<<node->year<<" Condition: "<<node->condition<<" Price: "<<node->price<<endl;
        if(node->rightChild != NULL){
            Cars::printCarInventory(node->rightChild);}
}

void Cars::searchByYear(int yearmin, int yearmax){
    searchByYear(yearmin, yearmax, root);

    cout<<'\n'<<"End of search (if no results found, please enter a valid year range.)"<< '\n'<<endl;
}

void Cars::searchByYear(int yearmin, int yearmax, CarNode *node){
    if(node->leftChild != NULL){
        Cars::searchByYear(yearmin, yearmax, node->leftChild);}
    if(node->year >=yearmin && node->year <= yearmax){
        cout << '\n' <<"Match Found:" << endl;
        cout << "===========" << endl;
        cout << "Make: " << node->make << endl;
        cout << "Model:" << node->model << endl;
        cout << "Year: " << node->year << endl;
        cout << "Condition: " << node->condition << endl;
        cout << "Price: $" << node->price<< '\n'<<endl;
    }
    if (node->rightChild != NULL){
        Cars::searchByYear(yearmin,yearmax,node->rightChild);
    }
}

void Cars::searchByPrice(int pricemin, int pricemax){
    searchByPrice(pricemin,pricemax, root);

    cout<<'\n'<<"End of search (if no results found, please enter a valid price range.)"<<endl;
}

void Cars::searchByPrice(int pricemin, int pricemax, CarNode * node){
    if(node->leftChild != NULL){
        Cars::searchByPrice(pricemin, pricemax, node->leftChild);}
    if(node->price >=pricemin && node->price <= pricemax){
        cout << '\n' <<"Match Found:" << endl;
        cout << "===========" << endl;
        cout << "Make: " << node->make << endl;
        cout << "Model:" << node->model << endl;
        cout << "Year: " << node->year << endl;
        cout << "Condition: " << node->condition << endl;
        cout << "Price: $" << node->price<< '\n'<<endl;
    }
    if (node->rightChild != NULL){
        Cars::searchByPrice(pricemin,pricemax,node->rightChild);
    }
}

void Cars::searchByModel(std::string modelname){
    Cars::searchByModel(modelname, root);

    cout<<'\n'<<"End of search (if no results found, please enter a valid Model)"<<endl;
}

void Cars::searchByModel(std::string modelname, CarNode * node){
   if(node->leftChild != NULL){
        Cars::searchByModel(modelname, node->leftChild);}
    if(node->model == modelname){
        cout << '\n' <<"Match Found:" << endl;
        cout << "===========" << endl;
        cout << "Make: " << node->make << endl;
        cout << "Model:" << node->model << endl;
        cout << "Year: " << node->year << endl;
        cout << "Condition: " << node->condition << endl;
        cout << "Price: $" << node->price<< '\n'<<endl;
    }
    if (node->rightChild != NULL){
        Cars::searchByModel(modelname,node->rightChild);
    }
}

void Cars::searchByMake(std::string makename){
    Cars::searchByMake(makename, root);

    cout<<'\n'<<"End of search (if no results found, please enter a valid Model)"<<endl;
}

void Cars::searchByMake(std::string makename, CarNode * node){
   if(node->leftChild != NULL){
        Cars::searchByMake(makename, node->leftChild);}
    if(node->make == makename){
        cout << '\n' <<"Match Found:" << endl;
        cout << "===========" << endl;
        cout << "Make: " << node->make << endl;
        cout << "Model:" << node->model << endl;
        cout << "Year: " << node->year << endl;
        cout << "Condition: " << node->condition << endl;
        cout << "Price: $" << node->price<< '\n'<<endl;
    }
    if (node->rightChild != NULL){
        Cars::searchByMake(makename,node->rightChild);
    }
}




void Cars::changePrice(std::string model, int year){
    Cars::changePrice(model,year,root);
}


void Cars::changePrice(std::string model, int year, CarNode *node){
    int newprice;
    if(node->leftChild != NULL){
        Cars::changePrice(model,year, node->leftChild);}
    if(node->model == model){
        if (node->year == year){
        cout << '\n' <<"Match Found:" << endl;
        cout << "===========" << endl;
        cout << "Make: " << node->make << endl;
        cout << "Model:" << node->model << endl;
        cout << "Year: " << node->year << endl;
        cout << "Condition: " << node->condition << endl;
        cout << "Price: $" << node->price<< '\n'<<endl;
        cout << "Enter a new price for this car: ";
        cin >>newprice;
        node->price = newprice;
        cout<<'\n'<<"New price is: $"<<node->price<<endl;
        }
    }
    if (node->rightChild != NULL){
        Cars::changePrice(model,year,node->rightChild);
    }
}


void Cars::countCars(CarNode *node, int &nodecount){
    if(node->leftChild != NULL){
        Cars::countCars(node->leftChild, nodecount);}
    nodecount++;
    if(node->rightChild != NULL){
        Cars::countCars(node->rightChild, nodecount);}
}

int Cars::countCars(){
    int nodecount = 0;
    countCars(root, nodecount);
    return nodecount;
}


