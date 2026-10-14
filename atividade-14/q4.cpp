#include <iostream>

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
  string palavra;
  No *topo = NULL;

  cout << "Palavra: ";
  cin >> palavra;

  for (int i = 0; i < (int) palavra.size(); i++) {
    empilhar(topo, palavra[i]);
  }

  bool ok = true;

  for (int i = 0; i < (int) palavra.size(); i++) {
    if (desempilhar(topo) != palavra[i]) ok = false;
  }

  if (ok) cout << "E palindromo." << endl;
  else cout << "Nao e palindromo." << endl;
}
