#include <iostream>

using namespace std;

string inverter(string texto) {
  if (texto.length() <= 1) {
    return texto;
  }

  return inverter(texto.substr(1)) + texto[0];
}

int main() {
  string texto;

  cout << "Digite uma string: ";
  cin >> texto;

  cout << "Invertida: " << inverter(texto) << endl;
}
