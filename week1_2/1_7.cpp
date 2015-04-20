/*
Investigate the use of the compiler error warning flags discussed in Sect. 1.3.3. For example: (i) declare an integer
 as a constant variable and then attempt to change this value later in the code; and (ii) attempt to set an integer
 variable to the value 3.2.
*/

//int main(int argc, char* argv[]) {
//
//    const int in1 = 5;
//
//    in1 = 6;
//
//    return 0;
//}

// Error: Read_only variable is not assignable! Does not compile

//int main(int argc, char* argv[]) {
//
//    int in1 = 3.2;
//
//    return 0;
//}

// Warning: Implicit conversion from 3.2 to 3! Still compiles
