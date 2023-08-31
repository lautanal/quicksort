// quicksort_fivepivot.h


// Five pivot quicksort algorithm

template <typename Iterator>
void quicksort_five_pivot(Iterator lo, Iterator hi) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    if (lo >= hi) return;
    if (lo + 25 > hi) {
        insertion_sort(lo, hi);
        return;
    }

    sort5(*lo, *(lo + 1), *(lo + 2), *(hi - 1), *hi);
    const value_type p1 = *lo, p2 = *(lo + 1), p3 = *(lo + 2), p4 = *(hi - 1), p5 = *hi;
    Iterator i1 = lo + 3, i2 = lo + 3, i3 = lo + 3, i4 = hi - 2, i5 = hi - 2, i6 = hi - 2;

    while (i3 <= i4) {

        while (*i3 < p3 && i3 <= i4) {
            if (*i3 < p1) {
                rotate_left_3(*i3, *i2, *i1);
                i1++, i2++;
            } else {
                if (*i3 < p2) {
                    swap(*i2, *i3);
                    i2++;
                }
            }
            i3++;
        }

        while(*i4 > p3 && i3 <= i4) {
            if (*i4 > p5) {
                rotate_left_3(*i4, *i5, *i6);
                i6--, i5--;
            } else {
                if (*i4 > p4) {
                    swap(*i4, *i5);
                    i5--;
                }
            }
            i4--;
        }

        if (i3 <= i4) {
            if (*i3 < p4) {
                if (*i4 > p2) {
                    // a3 and a2 element
                    swap(*i3, *i4);
                } else {
                    if (*i4 > p1) {
                        // a3 and a1
                        rotate_left_3(*i3, *i2, *i4); i2++;
                    } else {
                        // a3 and a0
                        rotate_left_4(*i3, *i2, *i1, *i4);
                        i2++, i1++;
                    }
                }
            } else {
                if (*i3 < p5) {
                    if (*i4 > p2) {
                        // a4 and a2 element
                        rotate_left_3(*i3, *i4, *i5);
                        i5--;
                    } else {
                        if (*i4 > p1) {
                            // a4 and a1
                            rotate_left_4(*i3, *i2, *i4, *i5);
                            i2++, i5--;
                        } else {
                            // a4 and a0
                            rotate_left_5(*i3, *i2, *i1, *i4, *i5); 
                            i2++, i1++, i5--;
                        }
                    }
                } else {
                    if (*i4 > p2) {
                        // a5 and a2 element
                        rotate_left_4(*i3, *i4, *i5, *i6);
                        i5--, i6--;
                    } else {
                        if (*i4 > p1) {
                            // a5 and a1
                            rotate_left_5(*i3, *i2, *i4, *i5, *i6);
                            i2++, i5--, i6--;
                        } else {
                            // a5 and a0
                            rotate_left_6(*i3, *i2, *i1, *i4, *i5, *i6);
                            i2++, i1++, i5--, i6--;
                        }
                    }
                }
            }
            i4--, i3++;
        }
    }

    rotate_left_4(*(lo + 2), *(i1 - 1), *(i2 - 1), *(i3 - 1));
    rotate_left_3(*(lo + 1), *(i1 - 2), *(i2 - 2));
    swap(*(lo + 0), *(i1 - 3));
    rotate_left_3(*(hi - 1), *(i6 + 1), *(i5 + 1));
    swap(*(hi - 0), *(i6 + 2));

    quicksort_five_pivot(lo,   i1 - 4);
    quicksort_five_pivot(i1 - 2, i2 - 3);
    quicksort_five_pivot(i2 - 1, i3 - 2);
    quicksort_five_pivot(i3,     i5);
    quicksort_five_pivot(i5 + 2, i6 + 1);
    quicksort_five_pivot(i6 + 3, hi);
}
