#include <iostream>

using namespace std;

int main() {
  int vetor[5] = {1, 2, 3, 4, 5};

  int soma = 0;
  int subtracao = vetor[0];
  int multiplicacao = 1;

  for (int i = 0; i < 5; i++) {
    soma += vetor[i];
    multiplicacao *= vetor[i];

    if (i > 0) {
      subtracao -= vetor[i];
    }
  }

  cout << "Soma: ";
  for (int i = 0; i < 5; i++) {
    cout << vetor[i];

    if (i < 4) {
      cout << "+";
    }
  }
  cout << " = " << soma << endl;

  cout << "Subtracao: ";
  for (int i = 0; i < 5; i++) {
    cout << vetor[i];

    if (i < 4) {
      cout << "-";
    }
  }
  cout << " = " << subtracao << endl;

  cout << "Multiplicação: ";
  for (int i = 0; i < 5; i++) {
    cout << vetor[i];

    if (i < 4) {
      cout << "*";
    }
  }
  cout << " = " << multiplicacao << endl;
}
