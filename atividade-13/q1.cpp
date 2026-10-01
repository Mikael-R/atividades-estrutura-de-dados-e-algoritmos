#include <iostream>
#include <string>

using namespace std;

struct No {
  string nome;
  int idade;
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

int quantidade(Lista &lista) {
  int count = 0;
  No *aux = lista.inicio;

  while (aux != NULL) {
    count++;
    aux = aux->proximo;
  }

  return count;
}

void inserir(Lista &lista, string nome, int idade) {
  No *novo = new No{nome, idade, lista.fim, NULL};

  if (vazia(lista)) {
    lista.inicio = novo;
  } else {
    lista.fim->proximo = novo;
  }

  lista.fim = novo;
}

void imprimir(Lista &lista) {
  if (vazia(lista)) {
    cout << "Lista vazia." << endl;
    return;
  }

  No *aux = lista.inicio;
  int posicao = 1;

  while (aux != NULL) {
    cout << posicao << ". " << aux->nome << " - " << aux->idade << " anos" << endl;
    aux = aux->proximo;
    posicao++;
  }
}

No *buscar(Lista &lista, string nome) {
  No *aux = lista.inicio;

  while (aux != NULL) {
    if (aux->nome == nome) return aux;
    aux = aux->proximo;
  }

  return NULL;
}

bool remover(Lista &lista, string nome) {
  No *aux = buscar(lista, nome);

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
    cout << "1 - Inserir aluno" << endl;
    cout << "2 - Imprimir lista" << endl;
    cout << "3 - Quantidade de alunos" << endl;
    cout << "4 - Buscar aluno pelo nome" << endl;
    cout << "5 - Remover aluno" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    if (opcao == 1) {
      string nome;
      int idade;

      cout << "Nome: ";
      getline(cin, nome);
      cout << "Idade: ";
      cin >> idade;
      cin.ignore();

      inserir(lista, nome, idade);
      cout << "Aluno inserido." << endl;
    } else if (opcao == 2) {
      imprimir(lista);
    } else if (opcao == 3) {
      cout << "Quantidade de alunos: " << quantidade(lista) << endl;
    } else if (opcao == 4) {
      string nome;

      cout << "Nome: ";
      getline(cin, nome);

      No *aluno = buscar(lista, nome);

      if (aluno == NULL) {
        cout << "Aluno nao encontrado." << endl;
      } else {
        cout << "Encontrado: " << aluno->nome << " - " << aluno->idade << " anos" << endl;
      }
    } else if (opcao == 5) {
      string nome;

      cout << "Nome: ";
      getline(cin, nome);

      if (remover(lista, nome)) {
        cout << "Aluno removido." << endl;
      } else {
        cout << "Aluno nao encontrado." << endl;
      }
    } else if (opcao != 0) {
      cout << "Opcao invalida." << endl;
    }
  } while (opcao != 0);

  liberar(lista);
}
