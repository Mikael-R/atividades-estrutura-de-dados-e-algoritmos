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

void removerDuplicados(No *&topo) {
  No *aux = NULL;

  while (topo != NULL) {
    int valor = desempilhar(topo);
    bool existe = false;

    for (No *p = aux; p != NULL; p = p->proximo) {
      if (p->valor == valor) existe = true;
    }

    if (!existe) empilhar(aux, valor);
  }

  while (aux != NULL) {
    empilhar(topo, desempilhar(aux));
  }
}

int main() {
  No *topo = NULL;

  empilhar(topo, 1);
  empilhar(topo, 2);
  empilhar(topo, 3);
  empilhar(topo, 2);
  empilhar(topo, 4);
  empilhar(topo, 1);

  removerDuplicados(topo);

  while (topo != NULL) {
    cout << desempilhar(topo) << " ";
  }

  cout << endl;
}
