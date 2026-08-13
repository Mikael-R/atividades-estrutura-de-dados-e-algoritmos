#include <iostream>

using namespace std;

string resultado(int media) {
  if (media >= 7) return "aprovado";
  if (media >= 5) return "recuperação";
  return "reprovado";
}

int main() {
  int nota1, nota2, nota3;

  cout << "Primeira nota: ";
  cin >> nota1;

  cout << "Segunda nota: ";
  cin >> nota2;

  cout << "Terceira nota: ";
  cin >> nota3;

  int media = (nota1 + nota2 + nota3) / 3;

  cout << "Média: " << media << endl;
  cout << resultado(media) << endl;
}
