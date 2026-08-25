#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - 1 - i; j++) {
      if (vetor[j] > vetor[j + 1]) {
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
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
  int vetor[5] = {8, 4, 6, 3, 9};

  cout << "Vetor original: ";
  imprimirVetor(vetor, 5);

  bubbleSort(vetor, 5);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 5);
}
