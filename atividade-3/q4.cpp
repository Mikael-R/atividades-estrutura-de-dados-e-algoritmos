#include <iostream>

using namespace std;

int main() {
  int matriz[3][4] = {
    {1, 2, 3, 4},
    {5, 69, 7, 8},
    {9, 10, 11, 12},
  };
  int maior = matriz[0][0];
  int maior_x = 0;
  int maior_y = 0;

  cout << "Matriz:" << endl;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 4; y++) {
      cout << matriz[x][y] << ' ';

      if (matriz[x][y] > maior) {
        maior = matriz[x][y];
        maior_x = x + 1;
        maior_y = y + 1;
      }
    }

    cout << endl;
  }

  cout << "Maior número é " << maior << " na coluna " << maior_y << " e na linha " << maior_x << endl;
}
