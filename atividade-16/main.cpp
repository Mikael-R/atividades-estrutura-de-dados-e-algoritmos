#include <iostream>

using namespace std;

struct No {
  string nome;
  string tipo;
  No *proximo;
};

struct Fila {
  No *inicio;
  No *fim;
};

int prioridade(string tipo) {
  if (tipo == "Idoso") return 4;
  if (tipo == "PCD" || tipo == "Gestante") return 3;
  if (tipo == "Autista") return 2;
  return 1;
}

void enfileirar(Fila &fila, string nome, string tipo) {
  No *novo = new No{nome, tipo, NULL};
  int nivel = prioridade(tipo);

  if (fila.inicio == NULL) {
    fila.inicio = novo;
    fila.fim = novo;
    return;
  }

  if (nivel > prioridade(fila.inicio->tipo)) {
    novo->proximo = fila.inicio;
    fila.inicio = novo;
    return;
  }

  No *aux = fila.inicio;

  while (aux->proximo != NULL && prioridade(aux->proximo->tipo) >= nivel) {
    aux = aux->proximo;
  }

  novo->proximo = aux->proximo;
  aux->proximo = novo;

  if (novo->proximo == NULL) {
    fila.fim = novo;
  }
}

bool remover(Fila &fila, string nome) {
  if (fila.inicio == NULL) return false;

  if (fila.inicio->nome == nome) {
    No *alvo = fila.inicio;
    fila.inicio = alvo->proximo;

    if (fila.inicio == NULL) {
      fila.fim = NULL;
    }

    delete alvo;
    return true;
  }

  No *aux = fila.inicio;

  while (aux->proximo != NULL && aux->proximo->nome != nome) {
    aux = aux->proximo;
  }

  if (aux->proximo == NULL) return false;

  No *alvo = aux->proximo;
  aux->proximo = alvo->proximo;

  if (alvo->proximo == NULL) {
    fila.fim = aux;
  }

  delete alvo;
  return true;
}

bool atender(Fila &fila, string &nome, string &tipo) {
  if (fila.inicio == NULL) return false;

  No *remover = fila.inicio;
  nome = remover->nome;
  tipo = remover->tipo;
  fila.inicio = remover->proximo;

  if (fila.inicio == NULL) {
    fila.fim = NULL;
  }

  delete remover;
  return true;
}

void imprimir(Fila &fila) {
  if (fila.inicio == NULL) {
    cout << "Fila vazia." << endl;
    return;
  }

  No *aux = fila.inicio;
  int posicao = 1;

  while (aux != NULL) {
    cout << posicao << ". " << aux->nome << " (" << aux->tipo << ")" << endl;
    aux = aux->proximo;
    posicao++;
  }
}

int main() {
  Fila fila{NULL, NULL};
  string nome;
  string tipo;

  enfileirar(fila, "Joao", "Normal");
  enfileirar(fila, "Maria", "Idoso");
  enfileirar(fila, "Pedro", "Normal");
  enfileirar(fila, "Ana", "Gestante");
  enfileirar(fila, "Lucas", "PCD");
  enfileirar(fila, "Carla", "Autista");

  cout << "Fila:" << endl;
  imprimir(fila);

  if (remover(fila, "Lucas")) {
    cout << "Removido: Lucas" << endl;
  }

  cout << "Fila:" << endl;
  imprimir(fila);

  while (atender(fila, nome, tipo)) {
    cout << "Atendido: " << nome << " (" << tipo << ")" << endl;
  }

  cout << "Fila:" << endl;
  imprimir(fila);
}
