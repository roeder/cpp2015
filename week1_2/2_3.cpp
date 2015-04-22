/* In this exercise you are asked to write and test a program which sums a list of numbers which are provided
 * by a user via std::cin (see Sect. 1.5.2).
 *
 * 1. Write a program that calculates the sum of a collection of positive integers that
are entered by the user from the keyboard. Your program should prompt the user to enter each integer followed by the
 return key, and to enter “−1” at the end of the list of integers to be added. Note that there is no need to store the
 list of integers: you can keep track of the sum as the user is entering the values.
2. Modify your code so that the code terminates if the sum of integers entered up to
that point exceeds 100.
3. Modify your code so that, if the user has entered an incorrect integer, they may
enter “−2” to reset the sum to zero and begin entering integers again. */

#include <iostream>

int main(int argc, char* argv[]) {

 int in;
 int cumsum;
 cumsum = 0;

 bool keep_summing;
 keep_summing = true;

 while (keep_summing) {
  std::cout << "Enter positive integers. Enter -1 to terminate, -2 to restart\n";
  std::cin >> in;
  cumsum += in;
  if (in == -1) {
   keep_summing = false;
   cumsum += 1;
  }
  if (cumsum > 100) {
   keep_summing = false;
  }
  if (in == -2) {
   cumsum = 0;
   std::cout.flush() << "Cumulative sum reset\n";
  }
 }

 std::cout << "Cumulative sum is " << cumsum << "\n";

 return 0;
}