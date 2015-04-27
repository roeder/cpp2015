#include "iostream"
#include "string"

int main(int argc, char* argv[]) {

    int i;
    i = 5;

    int* p_j;
    p_j = &i;

    std::cout << "Multiplication: " << 5 * *p_j << "\n";

    int* p_k;
    p_k = new int;
    *p_k = i;

    std::cout << "Reassignment: " << *p_k << "\n";

    return 0;
}
