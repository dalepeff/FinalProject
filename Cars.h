#ifndef CARS_H
#define CARS_H
#include <vector>
#include <queue>
#include <list>
#include<iostream>

struct CarNode{
    bool visited;
    int price;
    std::string model;
    std::string make;
    int year;
    std::string condition;
    CarNode *parent;
    CarNode *leftChild;
    CarNode *rightChild;

    CarNode(){};

    CarNode(int in_year, std::string in_model, std::string in_make, int in_price, std::string in_condition)
    {
        year = in_year;
        model = in_model;
        make = in_make;
        price = in_price;
        condition = in_condition;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class Cars
{
    public:
        Cars();
        ~Cars();
        void printCarInventory();
        void addCarNode(std::string make, std::string model, int year,std::string condition, int price);
        void searchByYear(int yearmin, int yearmax);
        void searchByPrice(int pricemin, int pricemax);
        void searchByMake(std::string makename);
        void searchByModel(std::string modelname);
        int countCars();
        void changePrice(std::string model,int year);

    protected:
    private:
        void changePrice(std::string model, int year, CarNode * node);
        void searchByMake(std::string make, CarNode * node);
        void searchByModel(std::string modelname, CarNode * node);
        void searchByYear(int yearmin, int yearmax, CarNode * node);
        void searchByPrice(int pricemin, int pricemax, CarNode * node);
        void printCarInventory(CarNode * node);
        CarNode *root;
        void countCars(CarNode *node, int &nodecount);

};

#endif // MOVIETREE_H

