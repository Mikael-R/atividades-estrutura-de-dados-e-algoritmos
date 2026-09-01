#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string vetor[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - 1 - i; j++) {
      if (vetor[j] > vetor[j + 1]) {
        string temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
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

  cout << "Algoritmo: Bubble Sort" << endl;

  cout << "Vetor original: ";
  imprimirVetor(vetor, 4);

  bubbleSort(vetor, 4);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 4);
}
