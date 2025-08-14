#include <iostream>
 int main()
 {
 int sum = 0, value = 0;
 // readuntil end-of-file, calculating a running total of all values read
 while (std::cin >> value)
 sum += value; // equivalenttosum = sum + value
 std::cout << "Sum is: " << sum << std::endl;
 return 0;
 }