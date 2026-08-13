#include <iostream>

using namespace std;

int main() {
  char vetor[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

  int consoantes = 0;

  for (int i = 0; i < 10; i++) {
    if (
      vetor[i] != 'a' &&
      vetor[i] != 'e' &&
      vetor[i] != 'i' &&
      vetor[i] != 'o' &&
      vetor[i] != 'u'
    ) {
      consoantes++;
    }
  }

  cout << "Quantidade de consoantes: " << consoantes << endl;
}
