#include <iostream>
#include <string>

using namespace std;

void insertionSort(string vetor[], int tamanho) {
  for (int i = 1; i < tamanho; i++) {
    string atual = vetor[i];
    int j = i - 1;

    while (j >= 0 && vetor[j] > atual) {
      vetor[j + 1] = vetor[j];
      j--;
    }

    vetor[j + 1] = atual;
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

  cout << "Algoritmo: Insertion Sort" << endl;

  cout << "Vetor original: ";
  imprimirVetor(vetor, 4);

  insertionSort(vetor, 4);

  cout << "Vetor ordenado: ";
  imprimirVetor(vetor, 4);
}
