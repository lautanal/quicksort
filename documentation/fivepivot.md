# Five Pivot Quicksort

<img src="png/multipivot2.png" width="750">

In multi-pivot algorithms, an odd number of pivots is typically used. The five- and seven-pivot methods are extensions of the three-pivot algorithm.

An element is first compared to the middle pivot to determine which side of the array it belongs to. The comparison then continues with the other pivots until the exact position of the element in the partitioning is determined.

Element swaps are usually performed as multi-element rotations to minimize the number of element manipulations (see figure).

<img src="png/cyclicshifts.png" width="750">

There is an implementation in C++ in the file [src/quicksort_fivepivot.h](https://github.com/lautanal/quicksort/blob/master/src/quicksort_fivepivot.h).
