#include "ComplexNumber.hpp"

int main(int argc, char * argv[]) {
    ComplexNumber z1(4.0, 3.0);

    std::cout << "z1 = " << z1 << "\n";
    std::cout << "Modulus z1 = "
    << z1.CalculateModulus() << "\n";
    std::cout << "Argument z1 = "
    << z1.CalculateArgument() << "\n";

    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";

    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = -z2 = " << z3 << "\n";

    ComplexNumber z4;
    z4 = z1 + z2;
    std::cout << "z1 + z2 = " << z4 << "\n";

    ComplexNumber zs[2];
    zs[0] = z1;
    zs[1] = z2;
    std::cout << "Second element of zs = "
    << zs[1] << "\n";

    // Test new stuff
    // Getting private members
    std::cout << "Real part of z1 = " << z1.GetRealPart() << "\n";

    std::cout << "Imaginary part of z1 = " << z1.GetImaginaryPart() << "\n";

    std::cout << "Friend function: Real part of z1 = " << RealPart(z1) << "\n";

    std::cout << "Friend function: Imaginary part of z1 = " << ImaginaryPart(z1) << "\n";

    // Copy constructor
    ComplexNumber z_copy(z1);
    std::cout << "Copy constructor test: z_copy = " << z_copy << "\n";

    // Custom constructor (one input)
    ComplexNumber z5(4.2);
    std::cout << "Custom constructor test: z5 = " << z5 << "\n";

    // Conjugate
    std::cout << "Conjugate test: conj(z1) = " << z1.CalculateConjugate() << "\n";

    // Set conjugate
    z1.SetConjugate();
    std::cout << "Set conjugate test: z1.SetConjugate(); z1 = " << z1 << "\n";
    z1.SetConjugate();
    std::cout << "Second test: z1.SetConjugate(); z1 = " << z1 << "\n";

    // Power of zero
    ComplexNumber z7;
    z7 = z1.CalculatePower(0.0);
    std::cout << "z7 = z1^0 = " << z7 << "\n";

    return 0;
}

//Desired output

//z1 = (4 + 3i)
//Modulus z1 = 5
//Argument z1 = 0.643501
//z2 = z1*z1*z1 = (-44 + 117i)
//z3 = -z2 = (44 - 117i)
//z1 + z2 = (-40 + 120i)
//Second element of zs = (-44 + 117i)
//Real part of z1 = 4
//Imaginary part of z1 = 3
//Friend function: Real part of z1 = 4
//Friend function: Imaginary part of z1 = 3
//Copy constructor test: z_copy = (4 + 3i)
//Custom constructor test: z5 = (4.2 + 0i)
//Conjugate test: conj(z1) = (4 - 3i)






