#include <iostream>

using namespace std;

int main() {
  int vetor[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  for (int i = 14; i >= 0; i--) {
    cout << vetor[i] << endl;
  }
}
