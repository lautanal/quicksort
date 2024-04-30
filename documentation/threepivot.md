# Three Pivot Quicksort

<img src="png/runtime.png" width="750">

Kushagra et al. showed that increasing the number of pivot elements can further improve the efficiency of quicksort. Based on empirical experiments, the three-pivot algorithm can achieve a 7-9% improvement compared to the dual-pivot algorithms in use (picture above)

In the proposed algorithm, three pivot elements are selected from the set, for example the first, second and last element. These are put in order of magnitude. Each element of the set is first compared to the middle pivot element and then to one of the other two pivot elements. The elements of the set can thus be divided into four subsets, which are processed recursively with the same algorithm (picture below).

<img src="png/threepivot.png" width="750">

The file [src/quicksort_threepivot.h](https://github.com/lautanal/quicksort/blob/master/src/quicksort_threepivot.h) has an implementation in C++.
