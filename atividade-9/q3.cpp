#include <iostream>
#include <string>

using namespace std;

void selectionSort(string vetor[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    int indiceMinimo = i;

    for (int j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[indiceMinimo]) {
        indiceMinimo = j;
      }
    }

    if (indiceMinimo != i) {
      string temp = vetor[i];
      vetor[i] = vetor[indiceMinimo];
      vetor[indiceMinimo] = temp;
    }
  }
}

void imprimirVetor(string vetor[], int tamanho) {
  cout << "{";
  for (int i = 0; i < tamanho; i++) {
    cout << "\"" << vetor[i] << "\"";

    if (i < tamanho - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;
}

int main() {
  string vetor[4] = {"Maria", "Bruna", "Alberto", "Joao"};

  cout << "Algoritmo: Selection Sort" << endl;

  cout << "Vetor original: ";
  imprimirVetor(vetor, 4);

  selectionSort(vetor, 4);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 4);
}
