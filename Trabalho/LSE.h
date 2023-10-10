#ifndef LSE_H_

#define LSE_H_

typedef struct tipoNo LSE;

struct tipoNo{
    int numero;
    LSE *proximo;
};

/* Operações */

// Cria uma lista vazia
LSE* criaLista();

// Insere no final da lista
LSE* insereFim(LSE *ptLista, int num, long int *comps);

// Consulta um nó da lista e retorna ele (retorna NULL se não encontrar)
LSE* consultaLSE(LSE *ptLista, int num, long int *comps);

// Retorna se encontrou ou não o valor
int consultaValorLSE(LSE *ptLista, int valor, long int *comparacoes);

// Destrói uma lista
LSE* destroiLista(LSE *ptLista);

//Encontra menor da lista
int encontraMenorValorLSE(LSE *ptLista);

//Encontra maior da lista
int encontraMaiorValorLSE(LSE *ptLista);

#endif // LSE_H_