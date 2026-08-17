#include <iostream>

using namespace std;

int somar(int num1, int num2) {
  return num1 + num2;
}

int main() {
  int num1, num2;

  cout << "Digite o primeiro número: ";
  cin >> num1;

  cout << "Digite o segundo número: ";
  cin >> num2;

  cout << num1 << "+" << num2 << "=" << somar(num1, num2) << endl;
}
