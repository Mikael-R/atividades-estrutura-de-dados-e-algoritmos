#include <iostream>

using namespace std;

void selectionSort(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    int indiceMinimo = i;

    for (int j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[indiceMinimo]) {
        indiceMinimo = j;
      }
    }

    if (indiceMinimo != i) {
      int temp = vetor[i];
      vetor[i] = vetor[indiceMinimo];
      vetor[indiceMinimo] = temp;
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
  int vetor[5] = {9, 8, 4, 10, 6};

  cout << "Vetor original: ";
  imprimirVetor(vetor, 5);

  selectionSort(vetor, 5);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 5);
}
