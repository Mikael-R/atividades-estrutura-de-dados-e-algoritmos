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

void inserir(Lista &lista, int valor) {
  No *novo = new No{valor, lista.fim, NULL};

  if (vazia(lista)) {
    lista.inicio = novo;
  } else {
    lista.fim->proximo = novo;
  }

  lista.fim = novo;
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

bool removerValor(Lista &lista, int valor) {
  No *aux = lista.inicio;

  while (aux != NULL && aux->valor != valor) {
    aux = aux->proximo;
  }

  if (aux == NULL) return false;

  if (aux->anterior == NULL) {
    lista.inicio = aux->proximo;
  } else {
    aux->anterior->proximo = aux->proximo;
  }

  if (aux->proximo == NULL) {
    lista.fim = aux->anterior;
  } else {
    aux->proximo->anterior = aux->anterior;
  }

  delete aux;
  return true;
}

void liberar(Lista &lista) {
  while (!vazia(lista)) {
    No *aux = lista.inicio;
    lista.inicio = lista.inicio->proximo;
    delete aux;
  }

  lista.fim = NULL;
}

int main() {
  Lista lista;
  inicializar(lista);

  int opcao;

  do {
    cout << endl;
    cout << "1 - Inserir numero" << endl;
    cout << "2 - Imprimir lista" << endl;
    cout << "3 - Remover por valor" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao == 1) {
      int valor;

      cout << "Numero: ";
      cin >> valor;

      inserir(lista, valor);
      cout << "Numero inserido." << endl;
    } else if (opcao == 2) {
      imprimir(lista);
    } else if (opcao == 3) {
      int valor;

      cout << "Valor: ";
      cin >> valor;

      if (removerValor(lista, valor)) {
        cout << "Valor removido." << endl;
      } else {
        cout << "Valor nao encontrado." << endl;
      }
    } else if (opcao != 0) {
      cout << "Opcao invalida." << endl;
    }
  } while (opcao != 0);

  liberar(lista);
}
