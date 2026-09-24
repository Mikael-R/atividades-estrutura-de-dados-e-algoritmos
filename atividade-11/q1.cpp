#include <iostream>

using namespace std;

struct No {
  int dado;
  No * proximo;
};

void printMeioList(No *&head) {
  No *lento = head;
  No *rapido = head;

  while(rapido != NULL && rapido->proximo != NULL) {
    lento = lento->proximo;
    rapido = rapido->proximo->proximo;
  }

  cout << "Valor do meio: " << lento->dado << endl;
}

int main() {
  No *no1 = new No{1};
  No *no2 = new No{2};
  No *no3 = new No{3};
  No *no4 = new No{4};
  No *no5 = new No{5};
  No *no6 = new No{6};

  no1->proximo = no2;
  no2->proximo = no3;
  no3->proximo = no4;
  no4->proximo = no5;
  no5->proximo = no6;

  printMeioList(no1);
}
