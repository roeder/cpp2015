#include "iostream"
#include "string"

int main(int argc, char* argv[]) {

    std::string name1;
    std::string name2;

    std::cout << "Enter given name\n";
    std::getline(std::cin, name1);

    std::cout << "Enter family name\n";
    std::getline(std::cin, name2);

    std::cout << "Your name is " << name1 <<  " " << name2 << "\n";

    return 0;
}
