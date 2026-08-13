#include <iostream>

using namespace std;

int main() {
  int nascimento, ano_atual;

  cout << "Ano de nascimento: ";
  cin >> nascimento;

  cout << "Ano atual: ";
  cin >> ano_atual;

  int idade = ano_atual - nascimento;

  cout << "Você tem " << idade << " anos" << endl;
  cout << (idade >= 18 ? "Maior de idade" : "Menor de idade") << endl;
}
