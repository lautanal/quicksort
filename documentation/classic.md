# Classic Quicksort

<img src="png/classic.png" width="750">

The principle of classic QuickSort is to divide the array into two parts based on a so-called pivot element. The elements of the array are compared to the pivot and arranged so that elements smaller than the pivot are placed to its left, elements greater than the pivot are placed to its right, and elements equal to the pivot can be on either side (Figure).

The partitioning of the array into two parts can be implemented in several ways. Any element can be chosen as the pivot, and there are multiple methods for moving elements. Below is Sedgewick’s partitioning algorithm in pseudocode, where the pivot is always chosen as the first element of the current subarray.

<img src="png/classic_pseudocode.png" width="750">

The file [src/quicksort_classic.h](https://github.com/lautanal/quicksort/blob/master/src/quicksort_classic.h) has a similar implementation in C++.