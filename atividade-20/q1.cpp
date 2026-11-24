#include <iostream>

using namespace std;

struct Aluno {
  string nome;
  int matricula;
};

struct NoArvore {
  Aluno aluno;
  NoArvore *esquerda;
  NoArvore *direita;
};

NoArvore *inserirBST(NoArvore *raiz, string nome, int matricula) {
  if (raiz == NULL) {
    NoArvore *novoNo = new NoArvore;
    novoNo->aluno.nome = nome;
    novoNo->aluno.matricula = matricula;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
  }

  if (matricula > raiz->aluno.matricula) {
    raiz->direita = inserirBST(raiz->direita, nome, matricula);
  }

  if (matricula < raiz->aluno.matricula) {
    raiz->esquerda = inserirBST(raiz->esquerda, nome, matricula);
  }

  return raiz;
}

NoArvore *buscarBST(NoArvore *raiz, int matricula) {
  if (raiz == NULL || raiz->aluno.matricula == matricula) {
    return raiz;
  }

  if (matricula < raiz->aluno.matricula) {
    return buscarBST(raiz->esquerda, matricula);
  }

  return buscarBST(raiz->direita, matricula);
}

void emOrdem(NoArvore *raiz) {
  if (raiz == NULL) {
    return;
  }

  emOrdem(raiz->esquerda);
  cout << raiz->aluno.matricula << " - " << raiz->aluno.nome << endl;
  emOrdem(raiz->direita);
}

int main() {
  NoArvore *raiz = inserirBST(NULL, "Ana", 15);
  inserirBST(raiz, "Bruno", 10);
  inserirBST(raiz, "Carla", 20);
  inserirBST(raiz, "Diego", 5);
  inserirBST(raiz, "Elena", 12);
  inserirBST(raiz, "Fabio", 25);

  cout << "Alunos (em ordem de matricula):" << endl;
  emOrdem(raiz);
  cout << endl;

  int matricula = 12;
  NoArvore *encontrado = buscarBST(raiz, matricula);

  if (encontrado != NULL) {
    cout << "Matricula " << matricula << " encontrada: " << encontrado->aluno.nome << endl;
  } else {
    cout << "Matricula " << matricula << " nao encontrada." << endl;
  }

  matricula = 99;
  encontrado = buscarBST(raiz, matricula);

  if (encontrado != NULL) {
    cout << "Matricula " << matricula << " encontrada: " << encontrado->aluno.nome << endl;
  } else {
    cout << "Matricula " << matricula << " nao encontrada." << endl;
  }
}
