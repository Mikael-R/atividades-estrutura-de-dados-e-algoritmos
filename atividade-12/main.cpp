#include <iostream>

using namespace std;

struct No {
  int valor;
  No *anterior;
  No *proximo;
};

struct Lista {
  No *inicio;
  No *fim;
};

void inicializar(Lista &lista) {
  lista.inicio = NULL;
  lista.fim = NULL;
}

bool vazia(Lista &lista) {
  return lista.inicio == NULL;
}

int tamanho(Lista &lista) {
  int count = 0;
  No *aux = lista.inicio;

  while (aux != NULL) {
    count++;
    aux = aux->proximo;
  }

  return count;
}

void inserirInicio(Lista &lista, int valor) {
  No *novo = new No{valor, NULL, lista.inicio};

  if (vazia(lista)) {
    lista.fim = novo;
  } else {
    lista.inicio->anterior = novo;
  }

  lista.inicio = novo;
}

void inserirFim(Lista &lista, int valor) {
  No *novo = new No{valor, lista.fim, NULL};

  if (vazia(lista)) {
    lista.inicio = novo;
  } else {
    lista.fim->proximo = novo;
  }

  lista.fim = novo;
}

void inserirPosicao(Lista &lista, int posicao, int valor) {
  int n = tamanho(lista);

  if (posicao < 0 || posicao > n) return;

  if (posicao == 0) {
    inserirInicio(lista, valor);
    return;
  }

  if (posicao == n) {
    inserirFim(lista, valor);
    return;
  }

  No *aux = lista.inicio;

  for (int i = 0; i < posicao; i++) {
    aux = aux->proximo;
  }

  No *novo = new No{valor, aux->anterior, aux};
  aux->anterior->proximo = novo;
  aux->anterior = novo;
}

void removerInicio(Lista &lista) {
  if (vazia(lista)) return;

  No *remover = lista.inicio;
  lista.inicio = lista.inicio->proximo;

  if (lista.inicio == NULL) {
    lista.fim = NULL;
  } else {
    lista.inicio->anterior = NULL;
  }

  delete remover;
}

void removerFim(Lista &lista) {
  if (vazia(lista)) return;

  No *remover = lista.fim;
  lista.fim = lista.fim->anterior;

  if (lista.fim == NULL) {
    lista.inicio = NULL;
  } else {
    lista.fim->proximo = NULL;
  }

  delete remover;
}

void removerPosicao(Lista &lista, int posicao) {
  int n = tamanho(lista);

  if (posicao < 0 || posicao >= n) return;

  if (posicao == 0) {
    removerInicio(lista);
    return;
  }

  if (posicao == n - 1) {
    removerFim(lista);
    return;
  }

  No *aux = lista.inicio;

  for (int i = 0; i < posicao; i++) {
    aux = aux->proximo;
  }

  aux->anterior->proximo = aux->proximo;
  aux->proximo->anterior = aux->anterior;
  delete aux;
}

void imprimir(Lista &lista) {
  No *aux = lista.inicio;

  cout << "[";

  while (aux != NULL) {
    cout << aux->valor;

    if (aux->proximo != NULL) {
      cout << " <-> ";
    }

    aux = aux->proximo;
  }

  cout << "]" << endl;
}

bool busca(Lista &lista, int valor) {
  No *aux = lista.inicio;

  while (aux != NULL) {
    if (aux->valor == valor) return true;
    aux = aux->proximo;
  }

  return false;
}

void liberar(Lista &lista) {
  while (!vazia(lista)) {
    removerInicio(lista);
  }
}

int main() {
  Lista lista;
  inicializar(lista);

  inserirFim(lista, 10);
  inserirFim(lista, 20);
  inserirFim(lista, 30);
  inserirInicio(lista, 5);
  inserirPosicao(lista, 2, 15);

  cout << "Lista: ";
  imprimir(lista);
  cout << "Tamanho: " << tamanho(lista) << endl;

  cout << "Busca 15: " << (busca(lista, 15) ? "encontrado" : "nao encontrado") << endl;
  cout << "Busca 99: " << (busca(lista, 99) ? "encontrado" : "nao encontrado") << endl;

  removerInicio(lista);
  removerFim(lista);
  removerPosicao(lista, 1);

  cout << "Apos remocoes: ";
  imprimir(lista);
  cout << "Tamanho: " << tamanho(lista) << endl;

  liberar(lista);
}
