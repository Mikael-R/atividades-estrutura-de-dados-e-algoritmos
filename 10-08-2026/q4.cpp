#include <iostream>

using namespace std;

void print_tabuada(int numero) {
  for (int i = 1; i <= 10; i++) {
    cout << numero << "x" << i << "=" << i * numero << endl;
  }
}

int main() {
  int numero;

  cout << "Digite um número: ";
  cin >> numero;

  print_tabuada(numero);
}
