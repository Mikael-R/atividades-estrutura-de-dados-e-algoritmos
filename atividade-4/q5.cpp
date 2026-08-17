#include <iostream>

using namespace std;

void tabuada(int numero) {
  for (int i = 1; i <= 10; i++) {
    cout << numero << " + " << i << " = " << numero + i << endl;
    cout << numero << " - " << i << " = " << numero - i << endl;
    cout << numero << " * " << i << " = " << numero * i << endl;

    if (i != 0) {
      cout << numero << " / " << i << " = " << (float) numero / i << endl;
    }

    cout << endl;
  }
}

int main() {
  int numero;

  cout << "Digite um numero inteiro: ";
  cin >> numero;

  tabuada(numero);
}
