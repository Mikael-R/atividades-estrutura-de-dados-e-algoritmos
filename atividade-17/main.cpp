#include <iostream>

using namespace std;

struct Conteudo {
  string texto;
  Conteudo *proximo;
};

struct Disciplina {
  string nome;
  int creditos;
  Conteudo *conteudos;
  Disciplina *proximo;
};

struct Aluno {
  string nome;
  string cpf;
  int idade;
  string matricula;
  Disciplina *disciplinas;
  Aluno *proximo;
};

struct Fila {
  Aluno *inicio;
  Aluno *fim;
};

bool vazia(Fila &fila) {
  return fila.inicio == NULL;
}

Aluno *buscarAluno(Fila &fila, string matricula) {
  Aluno *aux = fila.inicio;

  while (aux != NULL && aux->matricula != matricula) {
    aux = aux->proximo;
  }

  return aux;
}

Disciplina *buscarDisciplina(Aluno *aluno, string nome) {
  if (aluno == NULL) return NULL;

  Disciplina *aux = aluno->disciplinas;

  while (aux != NULL && aux->nome != nome) {
    aux = aux->proximo;
  }

  return aux;
}

void enfileirar(Fila &fila, string nome, string cpf, int idade, string matricula) {
  Aluno *novo = new Aluno{nome, cpf, idade, matricula, NULL, NULL};

  if (vazia(fila)) {
    fila.inicio = novo;
    fila.fim = novo;
    return;
  }

  fila.fim->proximo = novo;
  fila.fim = novo;
}

void liberarDisciplina(Disciplina *disciplina) {
  while (disciplina->conteudos != NULL) {
    Conteudo *conteudo = disciplina->conteudos;
    disciplina->conteudos = conteudo->proximo;
    delete conteudo;
  }

  delete disciplina;
}

bool desenfileirar(Fila &fila) {
  if (vazia(fila)) return false;

  Aluno *aluno = fila.inicio;
  fila.inicio = aluno->proximo;

  if (fila.inicio == NULL) {
    fila.fim = NULL;
  }

  while (aluno->disciplinas != NULL) {
    Disciplina *disciplina = aluno->disciplinas;
    aluno->disciplinas = disciplina->proximo;
    liberarDisciplina(disciplina);
  }

  delete aluno;
  return true;
}

bool adicionarDisciplina(Fila &fila, string matricula, string nome, int creditos) {
  Aluno *aluno = buscarAluno(fila, matricula);

  if (aluno == NULL || buscarDisciplina(aluno, nome) != NULL) return false;

  aluno->disciplinas = new Disciplina{nome, creditos, NULL, aluno->disciplinas};
  return true;
}

bool removerDisciplina(Fila &fila, string matricula, string nome) {
  Aluno *aluno = buscarAluno(fila, matricula);

  if (aluno == NULL) return false;

  Disciplina **aux = &aluno->disciplinas;

  while (*aux != NULL && (*aux)->nome != nome) {
    aux = &(*aux)->proximo;
  }

  if (*aux == NULL) return false;

  Disciplina *alvo = *aux;
  *aux = alvo->proximo;
  liberarDisciplina(alvo);
  return true;
}

void listarDisciplinas(Fila &fila, string matricula) {
  Aluno *aluno = buscarAluno(fila, matricula);

  if (aluno == NULL) {
    cout << "Aluno nao encontrado." << endl;
    return;
  }

  cout << "Disciplinas de " << aluno->nome << ":" << endl;

  for (Disciplina *aux = aluno->disciplinas; aux != NULL; aux = aux->proximo) {
    cout << "- " << aux->nome << " (" << aux->creditos << " creditos)" << endl;
  }
}

bool adicionarConteudo(Fila &fila, string matricula, string disciplina, string texto) {
  Disciplina *materia = buscarDisciplina(buscarAluno(fila, matricula), disciplina);

  if (materia == NULL) return false;

  materia->conteudos = new Conteudo{texto, materia->conteudos};
  return true;
}

bool removerConteudo(Fila &fila, string matricula, string disciplina, string texto) {
  Disciplina *materia = buscarDisciplina(buscarAluno(fila, matricula), disciplina);

  if (materia == NULL) return false;

  Conteudo **aux = &materia->conteudos;

  while (*aux != NULL && (*aux)->texto != texto) {
    aux = &(*aux)->proximo;
  }

  if (*aux == NULL) return false;

  Conteudo *alvo = *aux;
  *aux = alvo->proximo;
  delete alvo;
  return true;
}

void listarConteudos(Fila &fila, string matricula, string disciplina) {
  Disciplina *materia = buscarDisciplina(buscarAluno(fila, matricula), disciplina);

  if (materia == NULL) {
    cout << "Disciplina nao encontrada." << endl;
    return;
  }

  cout << "Conteudos de " << materia->nome << ":" << endl;

  for (Conteudo *aux = materia->conteudos; aux != NULL; aux = aux->proximo) {
    cout << "- " << aux->texto << endl;
  }
}

void listarAlunos(Fila &fila) {
  if (vazia(fila)) {
    cout << "Fila vazia." << endl;
    return;
  }

  for (Aluno *aluno = fila.inicio; aluno != NULL; aluno = aluno->proximo) {
    cout << aluno->nome << " | CPF " << aluno->cpf << " | " << aluno->idade << " anos | " << aluno->matricula << endl;

    for (Disciplina *disciplina = aluno->disciplinas; disciplina != NULL; disciplina = disciplina->proximo) {
      cout << "  " << disciplina->nome << " (" << disciplina->creditos << "): ";

      for (Conteudo *conteudo = disciplina->conteudos; conteudo != NULL; conteudo = conteudo->proximo) {
        cout << conteudo->texto << (conteudo->proximo != NULL ? ", " : "");
      }

      cout << endl;
    }
  }
}

int main() {
  Fila fila{NULL, NULL};

  enfileirar(fila, "Ana", "111.111.111-11", 20, "2024001");
  enfileirar(fila, "Bruno", "222.222.222-22", 22, "2024002");

  adicionarDisciplina(fila, "2024001", "Algoritmos", 4);
  adicionarDisciplina(fila, "2024001", "Banco de Dados", 4);
  adicionarConteudo(fila, "2024001", "Algoritmos", "Vetores");
  adicionarConteudo(fila, "2024001", "Algoritmos", "Filas");

  listarDisciplinas(fila, "2024001");
  listarConteudos(fila, "2024001", "Algoritmos");

  removerConteudo(fila, "2024001", "Algoritmos", "Filas");
  removerDisciplina(fila, "2024001", "Banco de Dados");

  cout << endl;
  listarAlunos(fila);

  desenfileirar(fila);

  cout << endl;
  listarAlunos(fila);

  desenfileirar(fila);
}
