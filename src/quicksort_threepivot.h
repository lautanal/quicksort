// quicksort_threepivot.h

// Three pivot quicksort algorithms

// Kushagra algorithm
template <typename Iterator>
void quicksort_three_pivot(Iterator left, Iterator right) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (left >= right) return;
    if (left + 30 > right) {
            insertion_sort(left, right);
            return;
    }

// Pivot sampling
    threepivot_7_135(left, right);

    const value_type p1 = *left, p2 = *(left+1), p3 = *right;
    Iterator i = left + 2, j = right - 1, lt = left + 2, gt = right - 1;

// Sort algorithm
    while (i <= j) {
        while (*i < p2) {
            if (*i < p1) {
                swap(*lt, *i);
                lt++;
            }
            i++;
        }
        while (*j > p2) {
            if (*j > p3) {
                swap(*j, *gt);
                gt--;
            }
            j--;
        }
        if (i <= j) {
            if (*i > p3) {
                if (*j < p1) {
                    rotate_left_4(*i, *lt, *j, *gt);
                    lt++;
                } else {
                    rotate_left_3(*i, *j, *gt);
                }
                gt--;
            } else {
                if (*j < p1) {
                    rotate_left_3(*i, *lt, *j);
                    lt++;
                } else {
                    swap(*i, *j);
                }
            }
            i++;
            j--;
        }
    }
    rotate_left_3(*(left+1), *(lt-1), *(i-1));
    swap(*left, *(lt-2));
    swap(*right, *(gt+1));
    quicksort_three_pivot(left, lt-3);
    quicksort_three_pivot(lt-1, i-2);
    quicksort_three_pivot(i, gt);
    quicksort_three_pivot(gt+2, right);
}


// Optimum algorithm
template <typename Iterator>
void quicksort_three_pivot_optimum(Iterator left, Iterator right) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (left >= right) return;
    if (left + 30 > right) {
        insertion_sort(left, right);
        return;
    }

    if (*left > *(left+1))
        swap(*left, *(left+1));
    if (*left > *right) {
        swap(*left, *(left+1));
        swap(*left, *right);
    } else if (*(left + 1) > *right) {
        swap(*(left+1), *right);
    }
    const value_type p1 = *left, p2 = *(left+1), p3 = *right;
    Iterator i = left + 2, j = right - 1, lt = left + 2, gt = right - 1;

    while (i <= j) {
        while (*i < p2) {
            if (*i < p1) {
                swap(*i, *lt);
                lt++;
            }
            i++;
        }

        while (*j > p2) {
            if (*j > p3) {
                swap(*j, *gt);
                gt--;
            }
            j--;
        }

        if (i <= j) {
            if (*i > p3) {
                if (*j < p1) {
                    rotate_left_4(*i, *lt, *j, *gt);
                    lt++;
                } else {
                    rotate_left_3(*i, *j, *gt);
                }
                gt--;
            }
            else {
                if (*j < p1) {
                    rotate_left_3(*i, *lt, *j);
                    lt++;
                } else {
                    swap(*i, *j);
                }
            }
            i++; j--;
        }
    }

    rotate_left_3(*(left + 1), *(lt - 1), *(i - 1));

    swap(*left, *(lt - 2));
    swap(*right, *(gt + 1));

    quicksort_three_pivot_optimum(left, lt - 3);
    quicksort_three_pivot_optimum(lt - 1, i - 2);
    quicksort_three_pivot_optimum(i, gt);
    quicksort_three_pivot_optimum(gt + 2, right);
}
