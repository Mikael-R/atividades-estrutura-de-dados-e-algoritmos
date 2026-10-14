#include <iostream>

using namespace std;

struct No {
  int valor;
  No *proximo;
};

void empilhar(No *&topo, int valor) {
  topo = new No{valor, topo};
}

int desempilhar(No *&topo) {
  int valor = topo->valor;
  No *remover = topo;
  topo = topo->proximo;
  delete remover;
  return valor;
}

void removerMeio(No *&topo) {
  int n = 0;

  for (No *aux = topo; aux != NULL; aux = aux->proximo) {
    n++;
  }

  int meio = n / 2;
  No *aux = NULL;

  for (int i = 0; i < meio; i++) {
    empilhar(aux, desempilhar(topo));
  }

  desempilhar(topo);

  while (aux != NULL) {
    empilhar(topo, desempilhar(aux));
  }
}

int main() {
  No *topo = NULL;

  empilhar(topo, 1);
  empilhar(topo, 2);
  empilhar(topo, 3);
  empilhar(topo, 4);
  empilhar(topo, 5);

  removerMeio(topo);

  while (topo != NULL) {
    cout << desempilhar(topo) << " ";
  }

  cout << endl;
}
