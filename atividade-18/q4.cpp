#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;

  cout << "Digite n: ";
  cin >> n;

  cout << "Termo " << n << " de Fibonacci: " << fibonacci(n) << endl;
}
