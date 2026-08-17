#include <iostream>

using namespace std;

int maiorNumero(int vetor[10]) {
  int maior = vetor[0];

  for (int i = 1; i < 10; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }

  return maior;
}

int main() {
  int vetor[10] = {1,2,3,4,5,6,7,8,9,10};

  cout << "O maior numero é " << maiorNumero(vetor) << endl;

  return 0;
}
