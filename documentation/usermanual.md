# User Manual

## Program download

Download the repository files. The programs are located in the folder src.

## Installing the program

Copy the folder src into the desired directory.

Compile the program with the following command (Linux and Mac):
g++ -std=c++11 ./src/qs.cpp -o src/qs

## Running the program

The program is started in the installation directory with the command:
./src/qs

Eg: ./src/qs 1 i 10000000

Command line parameters:
- algorithm (1, 2, 3, 5)
- Data type (i, f, s)
- table size