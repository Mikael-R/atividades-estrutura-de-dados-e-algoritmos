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

int contar(NoArvore *raiz) {
  if (raiz == NULL) {
    return 0;
  }

  return 1 + contar(raiz->esquerda) + contar(raiz->direita);
}

void emOrdem(NoArvore *raiz, int *valores, int &n) {
  if (raiz == NULL) {
    return;
  }

  emOrdem(raiz->esquerda, valores, n);
  valores[n] = raiz->data;
  n++;
  emOrdem(raiz->direita, valores, n);
}

bool mesmoConjunto(NoArvore *a, NoArvore *b) {
  int na = contar(a);
  int nb = contar(b);

  if (na != nb) {
    return false;
  }

  int *va = new int[na];
  int *vb = new int[nb];
  int ia = 0;
  int ib = 0;

  emOrdem(a, va, ia);
  emOrdem(b, vb, ib);

  bool iguais = true;

  for (int i = 0; i < na; i++) {
    if (va[i] != vb[i]) {
      iguais = false;
    }
  }

  delete[] va;
  delete[] vb;

  return iguais;
}

int main() {
  NoArvore *arvore1 = inserirBST(NULL, 15);
  inserirBST(arvore1, 10);
  inserirBST(arvore1, 20);
  inserirBST(arvore1, 5);
  inserirBST(arvore1, 12);
  inserirBST(arvore1, 25);

  NoArvore *arvore2 = inserirBST(NULL, 15);
  inserirBST(arvore2, 12);
  inserirBST(arvore2, 20);
  inserirBST(arvore2, 5);
  inserirBST(arvore2, 25);
  inserirBST(arvore2, 10);

  NoArvore *arvore3 = inserirBST(NULL, 15);
  inserirBST(arvore3, 10);
  inserirBST(arvore3, 20);
  inserirBST(arvore3, 5);
  inserirBST(arvore3, 12);
  inserirBST(arvore3, 30);

  if (mesmoConjunto(arvore1, arvore2)) {
    cout << "Arvore 1 e arvore 2 tem o mesmo conjunto." << endl;
  } else {
    cout << "Arvore 1 e arvore 2 nao tem o mesmo conjunto." << endl;
  }

  if (mesmoConjunto(arvore1, arvore3)) {
    cout << "Arvore 1 e arvore 3 tem o mesmo conjunto." << endl;
  } else {
    cout << "Arvore 1 e arvore 3 nao tem o mesmo conjunto." << endl;
  }
}
