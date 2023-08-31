// quicksort_dualpivot.h

// Dual pivot quicksort algorithms

// Yaroslavskiy dual pivot algorithm
template <typename Iterator>
void quicksort_dual_pivot(Iterator left, Iterator right) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (left >= right) return;
    if (left + 30 > right) {
        insertion_sort(left, right);
        return;
    }


    if (*left > *right)
        swap(*left, *right);
    dualpivot_5_13(left, right);

    const value_type p1 = *left, p2 = *right;
    Iterator lt = left + 1, gt = right - 1, k = left + 1 ;

    while (k <= gt) {
        if (*k < p1) {
            swap(*k, *lt);
            lt++;
        } else if (*k >= p2) {
            while (*gt > p2 && k < gt) {
                gt--;
            } 
            swap(*k, *gt);
            gt--;
            if (*k < p1) {
                swap(*k, *lt);
                lt++;
            }
        }
        k++;
    }

    lt--;
    *left = *lt;
    *lt = p1;

    gt++;
    *right = *gt;
    *gt = p2;

    quicksort_dual_pivot(left, lt-1);
    quicksort_dual_pivot(lt+1, gt-1);
    quicksort_dual_pivot(gt+1, right);
}

// Comparison to larger pivot first
template <typename Iterator>
void quicksort_dual_pivot_largerfirst(Iterator left, Iterator right) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (left >= right) return;
    if (left + 30 > right) {
        insertion_sort(left , right);
        return;
    }

//    Iterator mid = left + (right - left)/2;
//    if (*right > *left and *right > *mid) {
//        swap(*right, *mid);
//    } else if (*left > *right and *left > *mid) {
//        swap(*left, *mid);
//    }

    if (*left > *right)
        swap(*left, *right);
//    dualpivot_5_13(left, right);
    const value_type p1 = *left, p2 = *right;
    Iterator lt = left + 1, gt = right - 1, k = left + 1;

    while (k <= gt) {
        while (*gt > p2) gt--;

        while (*k < p2) {
            if (*k < p1) {
                swap(*k, *lt);
                lt++;
            }
            k++;
        }

        if (k < gt) {
            if (*gt < p1) {
                rotate_left_3(*gt, *k, *lt);
                lt++;
            }
            else {
                swap(*k, *gt);
            }
            gt--;
        }
        k++;
    }

    swap(*left, *(lt - 1));
    swap(*right, *(gt + 1));
    quicksort_dual_pivot_largerfirst(left, lt - 2);
    quicksort_dual_pivot_largerfirst(lt, gt);
    quicksort_dual_pivot_largerfirst(gt + 2, right);
}
