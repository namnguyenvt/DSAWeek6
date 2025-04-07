//
// Created by nguye on 8/04/2025.
//

#include <iostream>
using namespace std;

int POWER_RECURSION(int x, int y) {
  if (y == 0) {
    return 1;
  } else if (y == 1) {
    return x;
  } else {
    return x * POWER_RECURSION(x, y - 1);
  }
}

int main() {
  int integer, exponent, result;

  cout << "Enter the integer: ";
  cin >> integer;

  cout << "Enter the exponent: ";
  cin >> exponent;

  result = POWER_RECURSION(integer, exponent);
  cout << "Result: " << result;
  return 0;
}
