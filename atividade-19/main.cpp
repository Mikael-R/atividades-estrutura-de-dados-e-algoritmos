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

NoArvore *buscarBST(NoArvore *raiz, int chave) {
  if (raiz == NULL || raiz->data == chave) {
    return raiz;
  }

  if (chave < raiz->data) {
    return buscarBST(raiz->esquerda, chave);
  }

  return buscarBST(raiz->direita, chave);
}

void emOrdem(NoArvore *raiz) {
  if (raiz == NULL) {
    return;
  }

  emOrdem(raiz->esquerda);
  cout << raiz->data << " ";
  emOrdem(raiz->direita);
}

int main() {
  NoArvore *raiz = inserirBST(NULL, 50);
  inserirBST(raiz, 30);
  inserirBST(raiz, 70);
  inserirBST(raiz, 20);
  inserirBST(raiz, 40);
  inserirBST(raiz, 60);
  inserirBST(raiz, 80);

  cout << "Arvore (em ordem): ";
  emOrdem(raiz);
  cout << endl;

  int chave;
  cout << "Digite o valor a buscar: ";
  cin >> chave;

  if (buscarBST(raiz, chave) != NULL) {
    cout << "Valor " << chave << " encontrado na arvore." << endl;
  } else {
    cout << "Valor " << chave << " nao encontrado na arvore." << endl;
  }
}