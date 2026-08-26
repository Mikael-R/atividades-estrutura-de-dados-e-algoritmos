#include <iostream>

using namespace std;

void insertionSort(int vetor[], int tamanho) {
  for (int i = 1; i < tamanho; i++) {
    int atual = vetor[i];
    int j = i - 1;

    while (j >= 0 && vetor[j] > atual) {
      vetor[j + 1] = vetor[j];
      j--;
    }

    vetor[j + 1] = atual;
  }
}

void imprimirVetor(int vetor[], int tamanho) {
  cout << "{";
  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i];

    if (i < tamanho - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;
}

int main() {
  int vetor[5] = {9, 8, 4, 10, 6};

  cout << "Vetor original: ";
  imprimirVetor(vetor, 5);

  insertionSort(vetor, 5);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 5);
}
