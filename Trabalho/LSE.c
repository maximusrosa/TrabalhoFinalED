#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LSE.h"

LSE* criaLista() {
    return NULL;
}

LSE* insereFim(LSE *ptLista, int num, long int *comps){
    *comps = 1;
    LSE *novo, *ptAux=ptLista;
    
    novo = (LSE*) malloc(sizeof(LSE));
    novo->numero = num;
 
    (*comps)++;
    if (ptLista == NULL){
        novo->proximo = ptLista; // = NULL
        ptLista = novo;
    } else{
        while(ptAux->proximo != NULL) {
            (*comps)++;
            ptAux = ptAux->proximo;
        }
    
    ptAux->proximo = novo;
    novo->proximo = NULL;
    }

    return ptLista;
}

LSE *consultaLSE(LSE *ptLista, int num, long int *comps) {
    *comps = 2;
    if (ptLista == NULL || ptLista->numero == num) return ptLista;

    while (ptLista != NULL) {
        (*comps)++;
        if (ptLista->numero == num) return ptLista;
        (*comps)++;
        ptLista = ptLista->proximo;
    }

    return NULL;
}

int consultaValorLSE(LSE *ptLista, int valor, long int *comparacoes) {
    long int comps;

    LSE *consulta = consultaLSE(ptLista, valor, &comps);
    *comparacoes = comps;

    return consulta != NULL;
}


LSE* destroiLista(LSE *ptLista){
    LSE *ptAux;
    while (ptLista != NULL){
        ptAux = ptLista;
        ptLista = ptLista->proximo;
        free(ptAux);
    }

    return NULL;
}

int encontraMenorValorLSE(LSE *ptLista) {
    if (ptLista == NULL) {
        printf("A lista está vazia.\n");
        return -1; // Valor inválido
    }

    int menor = ptLista->numero;
    ptLista = ptLista->proximo;

    while (ptLista != NULL) {
        if (ptLista->numero < menor) {
            menor = ptLista->numero;
        }
        ptLista = ptLista->proximo;
    }

    return menor;
}
int encontraMaiorValorLSE(LSE *ptLista) {
    if (ptLista == NULL) {
        printf("A lista está vazia.\n");
        return -1; // Valor inválido
    }

    int maior = ptLista->numero;
    ptLista = ptLista->proximo;

    while (ptLista != NULL) {
        if (ptLista->numero > maior) {
            maior = ptLista->numero;
        }
        ptLista = ptLista->proximo;
    }

    return maior;
}

int encontraValorMedioLSE (LSE *ptLista) {
    int maior_valor;

    if (ptLista == NULL) {
        printf("A lista está vazia.\n");
        return -1; // Valor inválido
    }
    else
     maior_valor = encontraMaiorValorLSE(ptLista);

    return (int)(maior_valor / 2);
}
void contarFrequenciaLSE(LSE *ptLista) {
    if (ptLista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    while (ptLista != NULL) {
        int valor = ptLista->numero;
        int frequencia = 0;

        // Percorre a lista para contar a frequência do valor
        LSE *temp = ptLista;
        while (temp != NULL) {
            if (temp->numero == valor) {
                frequencia++;
            }
            temp = temp->proximo;
        }

        printf("Valor %d aparece %d vezes na lista.\n", valor, frequencia);

        // Avança para o próximo valor único
        while (ptLista != NULL && ptLista->numero == valor) {
            ptLista = ptLista->proximo;
        }
    }
}

