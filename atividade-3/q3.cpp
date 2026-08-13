#include <iostream>

using namespace std;

int main() {
  int matriz[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  int pares = 0;
  int impares = 0;

  cout << "Matriz:" << endl;

  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      cout << matriz[x][y] << ' ';
      matriz[x][y] % 2 ? impares++ : pares++;
    }

    cout << endl;
  }

  cout << "Pares: " << pares << endl;
  cout << "Impares: " << impares << endl;
}
