#include <iostream>

using namespace std;

int buscaSequencial(int vetor[], int tamanho, int valor) {
  int quantidade = 0;

  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) {
      quantidade++;
    }
  }

  return quantidade;
}

int main() {
  int vetor[10] = {1, 2, 3, 2, 5, 2, 7, 8, 2, 10};
  int valor = 2;

  cout << "Vetor: {";
  for (int i = 0; i < 10; i++) {
    cout << vetor[i];

    if (i < 9) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  cout << "Valor pesquisado: " << valor << endl;

  int ocorrencias = buscaSequencial(vetor, 10, valor);

  cout << "Quantidade de ocorrências: " << ocorrencias << endl;
}
