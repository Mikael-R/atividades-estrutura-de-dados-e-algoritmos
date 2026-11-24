#include <iostream>

using namespace std;

struct NoArvore {
  int data;
  NoArvore *esquerda;
  NoArvore *direita;
};

NoArvore *inserirBST(NoArvore *raiz, int chave) {
  if (raiz == NULL) {
    NoArvore *novoNo = new NoArvore;
    novoNo->data = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
  }

  if (chave > raiz->data) {
    raiz->direita = inserirBST(raiz->direita, chave);
  }

  if (chave < raiz->data) {
    raiz->esquerda = inserirBST(raiz->esquerda, chave);
  }

  return raiz;
}

NoArvore *criarNo(int chave) {
  NoArvore *novoNo = new NoArvore;
  novoNo->data = chave;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;

  return novoNo;
}

bool ehBST(NoArvore *raiz, NoArvore *&anterior) {
  if (raiz == NULL) {
    return true;
  }

  if (!ehBST(raiz->esquerda, anterior)) {
    return false;
  }

  if (anterior != NULL && raiz->data <= anterior->data) {
    return false;
  }

  anterior = raiz;

  return ehBST(raiz->direita, anterior);
}

bool ehBST(NoArvore *raiz) {
  NoArvore *anterior = NULL;
  return ehBST(raiz, anterior);
}

int main() {
  NoArvore *valida = inserirBST(NULL, 15);
  inserirBST(valida, 10);
  inserirBST(valida, 20);
  inserirBST(valida, 5);
  inserirBST(valida, 12);
  inserirBST(valida, 25);

  NoArvore *invalida = criarNo(10);
  invalida->esquerda = criarNo(5);
  invalida->direita = criarNo(15);
  invalida->direita->esquerda = criarNo(3);

  if (ehBST(valida)) {
    cout << "A primeira arvore e BST." << endl;
  } else {
    cout << "A primeira arvore nao e BST." << endl;
  }

  if (ehBST(invalida)) {
    cout << "A segunda arvore e BST." << endl;
  } else {
    cout << "A segunda arvore nao e BST." << endl;
  }
}
