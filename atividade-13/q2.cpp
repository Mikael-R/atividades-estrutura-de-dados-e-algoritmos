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

int buscarPosicao(Lista &lista, int valor) {
  No *aux = lista.inicio;
  int posicao = 1;

  while (aux != NULL) {
    if (aux->valor == valor) return posicao;
    aux = aux->proximo;
    posicao++;
  }

  return -1;
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
    cout << "3 - Buscar valor" << endl;
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

      int posicao = buscarPosicao(lista, valor);

      if (posicao == -1) {
        cout << "Valor nao encontrado." << endl;
      } else {
        cout << "Valor encontrado na posicao " << posicao << "." << endl;
      }
    } else if (opcao != 0) {
      cout << "Opcao invalida." << endl;
    }
  } while (opcao != 0);

  liberar(lista);
}
