#include <iostream>
#include <algorithm>
#include <chrono>

#include "swaps.h"
#include "utils.h"
#include "insertion_sort.h"
#include "quicksort.h"
#include "quicksort_classic.h"
#include "quicksort_dualpivot.h"
#include "quicksort_threepivot.h"
#include "quicksort_fivepivot.h"

using namespace std;

// Calling chosen sorting algorithm function

template <typename Iterator>
void quicksort_start(string sortmode, Iterator left, int size) {
    Iterator right = left + size - 1;

// Start sorting
    if (sortmode == "1") {
        quicksort_classic(left,right);
    } else if (sortmode =="1a") {
        quicksort_3way(left,right);
    } else if (sortmode =="1b") {
        quicksort_3way_mod(left,right);
    } else if (sortmode == "2") {
        quicksort_dual_pivot(left,right);
    } else if (sortmode == "2o") {
        quicksort_dual_pivot_largerfirst(left,right);
    } else if (sortmode == "3") {
        quicksort_three_pivot(left,right);
    } else if (sortmode == "3o") {
        quicksort_three_pivot_optimum(left,right);
    } else if (sortmode == "5") {
        quicksort_five_pivot(left,right);
    } else if (sortmode == "s") {
        std::sort(left, right+1);
    } else {
        quicksort_classic(left,right);
    }
}


// Quicksort main program

int main (int argc, char** argv) {
    string sortmode = "1";
    string datatype = "i";
    int size = 1000000;
    unsigned int maxnumber = 4000000000;

// Command line parameters
// 1. number of pivots
// 2. data type (i=integer, f=float, s=string)
// 3. array size

    if (argc < 2) {
        sortmode = "0";
    } else if (argc == 2) {
        sortmode = argv[1];
    } else if (argc == 3) {
        sortmode = argv[1];
        datatype = argv[2];
    } else if (argc == 4) {
        sortmode = argv[1];
        datatype = argv[2];
        size = atoi(argv[3]);
    } else {
        sortmode = argv[1];
        datatype = argv[2];
        size = atoi(argv[3]);
        maxnumber = atoi(argv[4]);
    }

// Print sort parameters
    cout << "Random array size: " << size << "\n";
    cout << "Max number of different elements: " << maxnumber << endl;
    if (datatype == "s") {
        cout << "Data type : string" << endl;
    } else if (datatype == "f") {
        cout << "Data type : float" << endl;
    } else {
        cout << "Data type: integer" << endl;
    }
    if (sortmode == "1") {
        cout << "\nClassic quicksort:\n";
    } else if (sortmode =="1a") {
        cout << "\nClassic quicksort 3-way:\n";
    } else if (sortmode =="1b") {
        cout << "\nClassic quicksort 3-way mod:\n";
    } else if (sortmode == "2") {
        cout << "\nDual pivot quicksort:\n";
    } else if (sortmode == "2o") {
        cout << "\nDual pivot optimum:\n";
    } else if (sortmode == "3") {
        cout << "\nThree pivot quicksort:\n";
    } else if (sortmode == "3o") {
        cout << "\nThree pivot optimum:\n";
    } else if (sortmode == "5") {
        cout << "\nFive pivot quicksort:\n";
    } else if (sortmode == "s") {
        cout << "\nC++ standard sort:\n";
    } else {
        cout << "\nClassic quicksort:\n";
    }

// Time counter initialization
    bool success = false;
    chrono::time_point<chrono::system_clock> start, end;

// String array
    if (datatype == "s") {
        string *arr = new string[size];
        for (int i=0; i<size; i++) {
            arr[i] = string_random(maxnumber);
        }
        start = chrono::system_clock::now();
        quicksort_start(sortmode, arr, size);
        end = chrono::system_clock::now();
        success = check_inorder(arr, arr+size-1);
        delete[] arr;

// Float array
    } else if (datatype == "f") {
        float *arr = new float[size];
        for (int i=0; i<size; i++) {
            arr[i] = (rand()%(10*maxnumber))/10.0; 
        }
        start = chrono::system_clock::now();
        quicksort_start(sortmode, arr, size);
        end = chrono::system_clock::now();
        success = check_inorder(arr, arr+size-1);
        delete[] arr;

// Integer array
    } else {
        unsigned int *arr = new unsigned int[size];
        for (int i=0; i<size; i++) {
            arr[i] = rand()%maxnumber; 
        }
        start = chrono::system_clock::now();
        quicksort_start(sortmode, arr, size);
        end = chrono::system_clock::now();
        success = check_inorder(arr, arr+size-1);
        delete[] arr;
    }

// Print elapsed time
    cout.precision(5);
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end-start).count() / 1000.0
        << " ms" << endl;

// Check array in order
    if (success) {
        cout << "OK" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
