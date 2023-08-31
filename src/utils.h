// utils.h

// Functions to generate, check and print arrays

// Random string generator
std::string string_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


// Check array is in order
template <typename Iterator>
bool check_inorder(Iterator lo, Iterator hi) {
    for (Iterator i=lo+1; i<=hi; i++) {
        if  (*i < *(i-1)) {
            return false;
        }
    }
    return true;
}


template <typename Iterator>
int check_same(Iterator lo, Iterator hi) {
    int nsame = 0;
    for (Iterator i=lo+1; i<=hi; i++) {
        if  (*i == *(i-1)) {
//            std::cout << "False" << std::endl;
            nsame++;
        }
    }
//    std::cout << "OK" << std::endl;
    return nsame;
}


// Print array
template <typename Iterator>
void printArr(Iterator lo, Iterator hi) {
    for (Iterator i=lo; i<=hi; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return;
}
