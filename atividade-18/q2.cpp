#include <iostream>

using namespace std;

bool isPalindromo(string palavra, int inicio, int fim) {
  if (inicio >= fim) {
    return true;
  }

  if (palavra[inicio] != palavra[fim]) {
    return false;
  }

  return isPalindromo(palavra, inicio + 1, fim - 1);
}

int main() {
  string palavra;

  cout << "Digite uma palavra: ";
  cin >> palavra;

  if (isPalindromo(palavra, 0, palavra.length() - 1)) {
    cout << "\"" << palavra << "\" e palindromo" << endl;
  } else {
    cout << "\"" << palavra << "\" nao e palindromo" << endl;
  }
}
