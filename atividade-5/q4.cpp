#include <iostream>

using namespace std;

bool buscaSequencial(int vetor[], int tamanho, int valor) {
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) {
      return true;
    }
  }

  return false;
}

int main() {
  int vetor1[5] = {1, 2, 3, 2, 4};
  int vetor2[4] = {2, 5, 3, 9};

  cout << "Vetor 1: {";
  for (int i = 0; i < 5; i++) {
    cout << vetor1[i];

    if (i < 4) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  cout << "Vetor 2: {";
  for (int i = 0; i < 4; i++) {
    cout << vetor2[i];

    if (i < 3) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  int exclusivos[5];
  int quantidade = 0;

  for (int i = 0; i < 5; i++) {
    if (
      !buscaSequencial(exclusivos, quantidade, vetor1[i]) &&
      !buscaSequencial(vetor2, 4, vetor1[i])
    ) {
      exclusivos[quantidade] = vetor1[i];
      quantidade++;
    }
  }

  if (quantidade == 0) {
    cout << "Nenhum valor exclusivo" << endl;
  } else {
    cout << "Valores exclusivos: {";

    for (int i = 0; i < quantidade; i++) {
      cout << exclusivos[i];

      if (i < quantidade - 1) {
        cout << ", ";
      }
    }

    cout << "}" << endl;
  }

  cout << "Quantidade de valores exclusivos: " << quantidade << endl;
}
