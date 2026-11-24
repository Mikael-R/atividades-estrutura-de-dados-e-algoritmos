#include <iostream>

using namespace std;

struct NoArvore {
  int data;
  NoArvore *esquerda;
  NoArvore *direita;
};

NoArvore *inserirBST(NoArvore *raiz, int chave) {
  NoArvore *novoNo = new NoArvore;
  novoNo->data = chave;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;

  if (raiz == NULL) {
    return novoNo;
  }

  NoArvore *atual = raiz;
  NoArvore *pai = NULL;

  while (atual != NULL) {
    pai = atual;

    if (chave > atual->data) {
      atual = atual->direita;
    } else if (chave < atual->data) {
      atual = atual->esquerda;
    } else {
      delete novoNo;
      return raiz;
    }
  }

  if (chave > pai->data) {
    pai->direita = novoNo;
  }

  if (chave < pai->data) {
    pai->esquerda = novoNo;
  }

  return raiz;
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
}
