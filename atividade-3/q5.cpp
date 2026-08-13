#include <iostream>

using namespace std;

int main() {
  int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  cout << "Matriz:" << endl;

  for (int x = 0; x < 3; x++) {
    int soma_x = 0;

    for (int y = 0; y < 3; y++) {
      soma_x += matriz[x][y];

      cout << matriz[x][y];

      if (y < 2) {
        cout << "+";
      }
    }

    cout << "=" << soma_x << endl;
  }
}
