#include <iostream>
#include <string>

using namespace std;

struct No {
  char valor;
  No *proximo;
};

void empilhar(No *&topo, char valor) {
  topo = new No{valor, topo};
}

char desempilhar(No *&topo) {
  char valor = topo->valor;
  No *remover = topo;
  topo = topo->proximo;
  delete remover;
  return valor;
}

int main() {
  string texto;
  No *topo = NULL;

  cout << "Texto: ";
  getline(cin, texto);

  for (int i = 0; i < (int)texto.size(); i++) {
    empilhar(topo, texto[i]);
  }

  while (topo != NULL) {
    cout << desempilhar(topo);
  }

  cout << endl;
}
