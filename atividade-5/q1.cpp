#include <iostream>

using namespace std;

int buscaSequencial(int vetor[], int tamanho, int valor) {
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) {
      return i;
    }
  }

  return -1;
}

int main() {
  int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int valor = 7;

  cout << "Vetor: {";
  for (int i = 0; i < 10; i++) {
    cout << vetor[i];

    if (i < 9) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  cout << "Valor pesquisado: " << valor << endl;

  int posicao = buscaSequencial(vetor, 10, valor);

  if (posicao != -1) {
    cout << "Valor encontrado na posição " << posicao << endl;
  } else {
    cout << "Valor não encontrado" << endl;
  }
}
