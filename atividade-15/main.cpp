#include <iostream>

using namespace std;

struct No {
  int valor;
  No *proximo;
};

struct Fila {
  No *inicio;
  No *fim;
};

bool vazia(Fila &fila) {
  return fila.inicio == NULL;
}

void enfileirar(Fila &fila, int valor) {
  No *novo = new No{valor, NULL};

  if (vazia(fila)) {
    novo->proximo = novo;
    fila.inicio = novo;
    fila.fim = novo;
    return;
  }

  novo->proximo = fila.inicio;
  fila.fim->proximo = novo;
  fila.fim = novo;
}

int desenfileirar(Fila &fila) {
  No *remover = fila.inicio;
  int valor = remover->valor;

  if (fila.inicio == fila.fim) {
    fila.inicio = NULL;
    fila.fim = NULL;
  } else {
    fila.inicio = fila.inicio->proximo;
    fila.fim->proximo = fila.inicio;
  }

  delete remover;
  return valor;
}

void imprimir(Fila &fila) {
  if (vazia(fila)) {
    cout << "[]" << endl;
    return;
  }

  No *aux = fila.inicio;

  cout << "[";

  do {
    cout << aux->valor;

    if (aux->proximo != fila.inicio) {
      cout << " -> ";
    }

    aux = aux->proximo;
  } while (aux != fila.inicio);

  cout << "]" << endl;
}

int main() {
  Fila fila{NULL, NULL};

  enfileirar(fila, 10);
  enfileirar(fila, 20);
  enfileirar(fila, 30);

  cout << "Fila: ";
  imprimir(fila);

  cout << "Desenfileirado: " << desenfileirar(fila) << endl;

  enfileirar(fila, 40);

  cout << "Fila: ";
  imprimir(fila);

  while (!vazia(fila)) {
    cout << "Desenfileirado: " << desenfileirar(fila) << endl;
  }

  cout << "Fila: ";
  imprimir(fila);
}
