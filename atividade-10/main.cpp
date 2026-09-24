#include <iostream>

using namespace std;

struct No {
  int valor;
  No *proximo;
};

void removePosicao(No *&head, int posicao) {
  if (head == NULL) return;

  if (posicao == 0) {
    No *aux = head;
    head = head->proximo;
    delete aux;
    return;
  }

  No *aux = head;

  for (int i = 0; i < posicao - 1 && aux->proximo != NULL; i++) {
    aux = aux->proximo;
  }

  if (aux->proximo == NULL) return;

  No *remover = aux->proximo;
  aux->proximo = remover->proximo;
  delete remover;
}

int tamanhoLista(No *head){
  No *aux = head;
  int count = 1;
  while(aux->proximo != NULL) {
    count++;
    aux = aux->proximo;
  }
  return count;
}

int main() {
  No *no1 = new No{1};
  No *no2 = new No{2};
  No *no3 = new No{3};

  no1->proximo = no2;
  no2->proximo = no3;

  removePosicao(no1, 2);

  cout << tamanhoLista(no1);
}
