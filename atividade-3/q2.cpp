#include <iostream>

using namespace std;

int main() {
  int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  int soma = 0;

  cout << "Matriz:" << endl;

  for (int x = 0; x < 3; x++) {
    bool ultima = false;

    for (int y = 0; y < 3; y++) {
      ultima = x == 2 && y == 2;
      cout << matriz[x][y] << (ultima ? '=' : '+');
      soma += matriz[x][y];
    }

    if (ultima) {
      cout << soma;
    }

    cout << endl;
  }
}
