// Insertion sort algorithm

template <typename Iterator>
void insertion_sort(Iterator lo, Iterator hi) {
    
    if (lo >= hi) return;
    for (Iterator i=lo+1; i<=hi; i++) {
        Iterator j = i-1;
        while (j >= lo and *j > *(j+1)) {
            swap(*j, *(j+1));
            j--;
        }
    }
}
