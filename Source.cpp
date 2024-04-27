/*************************************************
* Program: 
* ================================================
* Programmer: Cameron Abo
* Class: CS 1C M/W 10:30a
*************************************************/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

enum SortType
{
    CARGO,
    NAME
};

enum ShipType
{
	SMALL,
	MEDIUM,
	LARGE,
	ERROR
};

struct Ship
{
    /*Ship() 
    {
        make = "";
        model = "";
        cargoCap = -1;
        type = ERROR;
        currentCap = -1;
        name = "";
    }*/
    Ship(string make, string model, int cargoCap, ShipType type)
    {
        this->make = make;
        this->model = model;
        this->cargoCap = cargoCap;
        this->type = type;
        currentCap = 0;
        name = this->make + ", " + this->model;
    }

    //Ship Variables
    string     name;
    string     make;
    string     model;
    int         cargoCap;
    int         currentCap;
    ShipType    type;
};

int partitionCargo(vector<Ship*>& arr, int low, int high);

int partitionString(vector<Ship*>& arr, int low, int high);

void quickSort(vector<Ship*>& arr, int low, int high, SortType mode = NAME);

void swap(Ship*& a, Ship*& b);

void printArray(vector<Ship*> arr, int size);

int main()
{
    const int SIZE = 15;
    //Ship* arr[SIZE];
    vector<Ship*> arr(15);
    arr[0] = new Ship("Crusader", "C2 Hercules", 696, LARGE);
    arr[1] = new Ship("Crusader", "M2 Hercules", 522, LARGE);
    arr[2] = new Ship("RSI", "Aurora CL", 6, SMALL);
    arr[3] = new Ship("Aegis", "Avenger Titan", 8, SMALL);
    arr[4] = new Ship("Drake", "Caterpillar", 576, LARGE);
    arr[5] = new Ship("RSI", "Constellation Andromeda", 96, MEDIUM);
    arr[6] = new Ship("RSI", "Constellation Taurus", 174, MEDIUM);
    arr[7] = new Ship("Drake", "Cutless Black", 46, MEDIUM);
    arr[8] = new Ship("Drake", "Cutter", 4, SMALL);
    arr[9] = new Ship("MISC", "Freelancer", 66, SMALL);
    arr[10] = new Ship("MISC", "Freelancer MAX", 120, MEDIUM);
    arr[11] = new Ship("MISC", "Hull A", 64, SMALL);
    arr[12] = new Ship("MISC", "Hull B", 384, MEDIUM);
    arr[13] = new Ship("MISC", "Hull C", 4608, LARGE);
    arr[14] = new Ship("Crusader", "Mercury Star Runner", 114, MEDIUM); 


    printArray(arr, SIZE);
   
    cout << "\nSorting by Caro Capacity...\n";
    quickSort(arr, 0, SIZE - 1, CARGO);

    printArray(arr, SIZE);

    cout << "\nSorting by Ship Name...\n";
    quickSort(arr, 0, SIZE - 1);
    printArray(arr, SIZE);


	return 0;
}



int partitionCargo(vector<Ship*>& arr, int low, int high)
{
    int pivot = arr[high]->cargoCap;
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j]->cargoCap < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partitionString(vector<Ship*>& arr, int low, int high)
{
    string pivot = arr[high]->name;
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j]->name < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<Ship*>& arr, int low, int high, SortType mode)
{
    if (low < high)
    {
        int pivot = mode == CARGO ? partitionCargo(arr, low, high) : partitionString(arr, low, high);

        quickSort(arr, low, pivot - 1, mode);
        quickSort(arr, pivot + 1, high, mode);
    }
}

void swap(Ship*& a, Ship*& b)
{
    //cout << "<swapping " << a << " & " << b << ">\n";
    Ship* temp;
    temp = a;
    a = b;
    b = temp;
    //cout << "<Finished>\n";
}

void printArray(vector<Ship*> arr, int size)
{
    cout << "\nShips:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]->name << endl;
        cout << "Cargo Capacity: " << arr[i]->cargoCap << " SCU\n\n";
    }
    
}