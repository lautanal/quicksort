// quicksort_classic.h

// Classic quicksort algorithm (one pivot quicksort)

template <typename Iterator>
void quicksort_classic(Iterator left, Iterator right) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (left >= right) return;
    if (left + 30 > right) {
        insertion_sort(left, right);
        return;
    }

    median_3(left, right);

    Iterator i = left, j = right+1;
    const value_type v = *left;

    while (i < j) {
        while (*(++i) < v && i < right) ;
        while (v < *(--j) && j > left) ;
        if (i < j)
            swap(*i, *j);
    }
    swap(*left, *j);
    quicksort_classic(left, j-1);
    quicksort_classic(j+1, right);
}
