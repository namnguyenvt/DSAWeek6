//
// Created by nguye on 8/04/2025.
//

#include <iostream>
using namespace std;

double POWER_RECURSION(int x, int y) {
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }
  if (y > 1) {
    return x * POWER_RECURSION(x, y - 1);
  }
  return 1.0 / POWER_RECURSION(x, -y);
}

int main() {
  int integer, exponent;

  cout << "Enter the integer: ";
  cin >> integer;

  cout << "Enter the exponent: ";
  cin >> exponent;

  cout << "The result is: " << POWER_RECURSION(integer, exponent) << endl;

  return 0;
}
