// swaps.h


// Swapping and rotation of elements in an array

template <typename Type>
void swap(Type &a, Type &b) {
    Type temp = a;
    a = b;
    b = temp;
}


//void swap2(Type* x, Type* y) {
//   Type temp;
//   temp = *x;
//   *x = *y; 
//   *y = temp;
//  
//   return;
//}


template <typename Type>
void rotate_left_3(Type &a, Type &b, Type &c)
{
    Type tmp = a;
    a = b;
    b = c;
    c = tmp;
}


template <typename Type>
void rotate_left_4(Type &a, Type &b, Type &c, Type &d)
{
    Type tmp = a;
    a = b;
    b = c;
    c = d;
    d = tmp;
}


template <typename Type>
void rotate_left_5(Type &a, Type &b, Type &c, Type &d, Type &e)
{
    Type tmp = a;
    a = b;
    b = c;
    c = d;
    d = e;
    e = tmp;
}


template <typename Type>
void rotate_left_6(Type &a, Type &b, Type &c, Type &d, Type &e, Type &f)
{
    Type tmp = a;
    a = b;
    b = c;
    c = d;
    d = e;
    e = f;
    f = tmp;
}


template <typename Type>
void sort5(Type &A0, Type &A1, Type &A2, Type &A3, Type &A4)
{
    if (A0 > A1)
        swap(A0, A1);
    if (A3 > A4)
        swap(A3, A4);
    if (A2 > A4)
        swap(A2, A4);
    if (A2 > A3)
        swap(A2, A3);
    if (A0 > A3)
        swap(A0, A3);
    if (A0 > A2)
        swap(A0, A2);
    if (A1 > A4)
        swap(A1, A4);
    if (A1 > A3)
        swap(A1, A3);
    if (A1 > A2)
        swap(A1, A2);
}

