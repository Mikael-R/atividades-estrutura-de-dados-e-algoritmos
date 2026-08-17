#include <iostream>

using namespace std;

bool verificarPar(int num) {
  return num % 2 == 0;
}

int main() {
  int num;

  cout << "Informe um número: ";
  cin >> num;

  cout << (verificarPar(num) ? "par" : "ímpar") << endl;
}
