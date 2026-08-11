#include <iostream>

using namespace std;

int main() {
  int num, soma_total = 0, qtd_pares = 0, qtd_impares = 0;

  for (int i = 1; i <= 10; i++) {
    cout << "Digite o " << i << "° número: ";
    cin >> num;

    num % 2 ? qtd_impares++ : qtd_pares++;
    soma_total += num;
  }

  cout << endl << "Pares: " << qtd_pares << endl;
  cout << "Ímpares: " << qtd_impares << endl;
  cout << "Soma: " << soma_total << endl;
}
