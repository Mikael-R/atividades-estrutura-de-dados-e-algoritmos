#include <iostream>

using namespace std;

int main() {
  int numero, maior;

  for (int i = 1; i <= 8; i++) {
    cout << "Digite o " << i << "º número: ";
    cin >> numero;

    if (i == 1 || numero > maior) {
      maior = numero;
    }
  }

  cout << "Maior valor: " << maior << '\n';
  cout << (maior % 2 == 0 ? "Par" : "Ímpar") << '\n';
}
