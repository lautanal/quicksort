# Dual Pivot Quicksort

<img src="png/dualpivot.png" width="750">

In dual-pivot QuickSort, the first and last elements of the array can be chosen as pivot elements, denoted as P₁ and P₂ (Figure), where P₁ is the smaller pivot.

The array is traversed, and its elements are divided into three subarrays. Elements smaller than P₁ are placed at the beginning of the array. Elements larger than P₂ are placed at the end. Elements that fall between the two pivots or are equal to them are placed in the middle (Yaroslavskiy, 2009).

These three subarrays are then processed recursively using the same algorithm until the entire array is sorted.  Below is the pseudocode for Yaroslavskiy’s dual-pivot partitioning algorithm.

<img src="png/dualpivotpseudocode.png" width="750">

The file [src/quicksort_dualpivot.h](https://github.com/lautanal/quicksort/blob/master/src/quicksort_dualpivot.h) has an implementation in C++.
