# Ship Sorting
## About
This program was created in order to create functions to sort a list of Ship structs. A similar list of Ship structs is used in the [SC-Cargo-Log](https://github.com/JusDooEt/SC-Cargo-Log-Qt) repository as a way to store the required data of ships from the game Star Citizen. These algorithms will allow the SC-Cargo-Log program to sort the list of ships that the user can select from a combo box. The user will be allowed to sort by cargo capacity from least to greatest and alphabetically using the ship's full name formatted as "make, model". If implemented, these algorithms will add a significant quality of life feature to the program. The algorithm used to sort the list is the quick sort algorithm that has been modified to work with vectors and a specific Ship Struct. See more information about the Quick Sort algorithm [here.](https://github.com/JusDooEt/QuickSort)

## Ship Struct
```
struct Ship
{
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
```
## Sorting Algorithm
As mentioned before, the Quick Sort algorithm is used to sort a vector or Ship objects. The function will allow the programmer to use an enum type to determine the value used to sort the vector, cargo capacity or name. The default will be set to sort by the ship name. Two partition functions exist in order to sort by string or integer value. The enum type will determine which partition function is used in the quick sort.
## Output
```
Initial List of Ships:

Ships:
Crusader, C2 Hercules
Cargo Capacity: 696 SCU

Crusader, M2 Hercules
Cargo Capacity: 522 SCU

RSI, Aurora CL
Cargo Capacity: 6 SCU

Aegis, Avenger Titan
Cargo Capacity: 8 SCU

Drake, Caterpillar
Cargo Capacity: 576 SCU

RSI, Constellation Andromeda
Cargo Capacity: 96 SCU

RSI, Constellation Taurus
Cargo Capacity: 174 SCU

Drake, Cutless Black
Cargo Capacity: 46 SCU

Drake, Cutter
Cargo Capacity: 4 SCU

MISC, Freelancer
Cargo Capacity: 66 SCU

MISC, Freelancer MAX
Cargo Capacity: 120 SCU

MISC, Hull A
Cargo Capacity: 64 SCU

MISC, Hull B
Cargo Capacity: 384 SCU

MISC, Hull C
Cargo Capacity: 4608 SCU

Crusader, Mercury Star Runner
Cargo Capacity: 114 SCU


Sorting by Cargo Capacity...

Ships:
Drake, Cutter
Cargo Capacity: 4 SCU

RSI, Aurora CL
Cargo Capacity: 6 SCU

Aegis, Avenger Titan
Cargo Capacity: 8 SCU

Drake, Cutless Black
Cargo Capacity: 46 SCU

MISC, Hull A
Cargo Capacity: 64 SCU

MISC, Freelancer
Cargo Capacity: 66 SCU

RSI, Constellation Andromeda
Cargo Capacity: 96 SCU

Crusader, Mercury Star Runner
Cargo Capacity: 114 SCU

MISC, Freelancer MAX
Cargo Capacity: 120 SCU

RSI, Constellation Taurus
Cargo Capacity: 174 SCU

MISC, Hull B
Cargo Capacity: 384 SCU

Crusader, M2 Hercules
Cargo Capacity: 522 SCU

Drake, Caterpillar
Cargo Capacity: 576 SCU

Crusader, C2 Hercules
Cargo Capacity: 696 SCU

MISC, Hull C
Cargo Capacity: 4608 SCU


Sorting by Ship Name...

Ships:
Aegis, Avenger Titan
Cargo Capacity: 8 SCU

Crusader, C2 Hercules
Cargo Capacity: 696 SCU

Crusader, M2 Hercules
Cargo Capacity: 522 SCU

Crusader, Mercury Star Runner
Cargo Capacity: 114 SCU

Drake, Caterpillar
Cargo Capacity: 576 SCU

Drake, Cutless Black
Cargo Capacity: 46 SCU

Drake, Cutter
Cargo Capacity: 4 SCU

MISC, Freelancer
Cargo Capacity: 66 SCU

MISC, Freelancer MAX
Cargo Capacity: 120 SCU

MISC, Hull A
Cargo Capacity: 64 SCU

MISC, Hull B
Cargo Capacity: 384 SCU

MISC, Hull C
Cargo Capacity: 4608 SCU

RSI, Aurora CL
Cargo Capacity: 6 SCU

RSI, Constellation Andromeda
Cargo Capacity: 96 SCU

RSI, Constellation Taurus
Cargo Capacity: 174 SCU
```


