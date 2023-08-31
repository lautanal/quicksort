// Functions to select pivot points


template <typename Iterator>
void median_3(Iterator left, Iterator right) {
    Iterator mid = left + (right - left)/2;
    if (*left < *mid and *left < *right) {
        if (*mid < *right) {
            swap(*left, *mid);
        } else {
            swap(*left, *right);
        }
    } else if (*left > *mid and *left > *right) {
        if (*mid < *right) {
            swap(*left, *right);
        } else {
            swap(*left, *mid);
        }
    }
}


template <typename Iterator>
void median_5(Iterator left, Iterator right) {

    int deltaptr = (right - left)/4;

    for (int i = 0; i < 4; i++) { 
        for (int  j = i + 1; j < 5; j++) { 
            if (*(left + j*deltaptr) < *(left + i*deltaptr)) { 
                swap(*(left + j*deltaptr), *(left + i*deltaptr));
            } 
        } 
    }
    swap(*left, *(left + 2*deltaptr));

} 


template <typename Iterator>
void dualpivot_5_13(Iterator left, Iterator right) {

    int deltaptr = (right - left)/4;

    for (int i = 0; i < 4; i++) { 
        for (int  j = i + 1; j < 5; j++) { 
            if (*(left + j*deltaptr) < *(left + i*deltaptr)) { 
                swap(*(left + j*deltaptr), *(left + i*deltaptr));
            } 
        } 
    }
    swap(*left, *(left + deltaptr));
    swap(*right, *(left + 3*deltaptr));
} 


template <typename Iterator>
void dualpivot_7_24(Iterator left, Iterator right) {

    int deltaptr = (right - left)/6;

    for (int i = 0; i < 6; i++) { 
        for (int  j = i + 1; j < 7; j++) { 
            if (*(left + j*deltaptr) < *(left + i*deltaptr)) { 
                swap(*(left + j*deltaptr), *(left + i*deltaptr));
            } 
        } 
    }
    swap(*left, *(left + deltaptr));
    swap(*right, *(left + 3*deltaptr));
} 


template <typename Iterator>
void threepivot_7_135(Iterator left, Iterator right) {

    int deltaptr = (right - left)/6;

    for (int i = 0; i < 6; i++) { 
        for (int  j = i + 1; j < 7; j++) { 
            if (*(left + j*deltaptr) < *(left + i*deltaptr)) { 
                swap(*(left + j*deltaptr), *(left + i*deltaptr));
            } 
        } 
    }
    swap(*left, *(left + deltaptr));
    swap(*(left+1), *(left + 3*deltaptr));
    swap(*right, *(left + 5*deltaptr));
} 


template <typename Iterator>
void quicksort_3way_mod(Iterator lo, Iterator hi) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (lo >= hi) return;
    if (lo + 25 > hi) {
        insertion_sort(lo, hi);
        return;
    }

    Iterator i = lo, j = hi+1, lt=lo;
    const value_type v = *lo;

    while (i < j) {
        while (*(++i) <= v and i < j) {
            if (*i < v and i < j) {
                swap(*i, *lt);
                lt++;
            }
        }
        while (*(--j) > v and j > i);
        if (j > i) {
            if (*j < v) {
                rotate_left_3(*j, *i, *lt);
                lt++;
            } else {
                swap(*j, *i);
            }
        }
    }
    swap(*lt, *j);
    quicksort_3way_mod(lo, lt-1);
    quicksort_3way_mod(j+1, hi);
}


template <typename Iterator>
void quicksort_3way(Iterator lo, Iterator hi) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (lo >= hi) return;
    if (lo + 25 > hi) {
        insertion_sort(lo, hi);
        return;
    }

    const value_type v = *lo;
    Iterator lt = lo, gt = hi, i = lo+1;

    while (i <= gt) {
        if (*i < v) {
            swap(*i, *lt);
            lt++;
            i++;
        } else if(*i > v) {
            swap(*i, *gt);
            gt--;
        } else {
            i++;
        }
    }
    quicksort_3way(lo, lt-1);
    quicksort_3way(gt+1, hi);
}
