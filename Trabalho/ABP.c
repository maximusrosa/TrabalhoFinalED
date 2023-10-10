#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABP.h"

/* Operações */

ABP* criaABP() {
    return NULL;
}

void insereABP(ABP **arv, int num, long int *comparacoes) {
    ABP *aux = *arv;
    long int comps = 0;
    while (aux) {
        comps++;
        if (num < aux->info)
            arv = &aux->esq;
        else
            arv = &aux->dir;

        aux = *arv;
    }

    aux = (ABP*) malloc(sizeof(ABP));
    aux->info = num;
    aux->esq = NULL;
    aux->dir = NULL;

    *comparacoes = comps;
    *arv = aux;
}


int consultaValorABP(ABP *arv, int valor, long int *comps) {
    long int comparacoes;
    ABP* consulta = consultaABP(arv, valor, &comparacoes);

    *comps = comparacoes;
    return consulta != NULL;
}


 ABP* consultaABP(ABP *arv, int chave, long int *comparacoes)
 {
    *comparacoes = 0;

    while (arv != NULL) {
        (*comparacoes)++;
        if (arv->info == chave)
            return arv; //achou entao retorna o ponteiro para o nodo

        else if (arv->info > chave) arv = arv->esq;
        else arv = arv->dir;
    }

    return NULL; //se nao achou
}


ABP* destroiABP(ABP *arv) {
    if (arv == NULL) return NULL;

    destroiABP(arv->esq);
    destroiABP(arv->dir);
    free(arv);
    arv = NULL;

    return arv;
}

int encontraMenorValorABP(ABP *arv) {
    if (arv == NULL) {
        printf("A árvore está vazia.\n");
        return -1; // Valor de erro, se a árvore estiver vazia.
    }

    while (arv->esq != NULL) {
        arv = arv->esq;
    }

    return arv->info;
}

int encontraMaiorValorABP(ABP *arv) {
    if (arv == NULL) {
        printf("A árvore está vazia.\n");
        return -1; // Valor de erro, se a árvore estiver vazia.
    }

    while (arv->dir != NULL) {
        arv = arv->dir;
    }

    return arv->info;
}

void contarFrequenciaABP(ABP *arv, int *frequencias, long int *comparacoes) {
    if (arv == NULL) {
        return;
    }

    contarFrequenciaABP(arv->esq, frequencias, comparacoes);

    // Incrementa a frequência para o valor atual na árvore
    frequencias[arv->info]++;

    contarFrequenciaABP(arv->dir, frequencias, comparacoes);
}


void dezMaisRepetidosABP(ABP *arv, int quantidade) {
    int frequencias[quantidade]; // Array para armazenar as frequências dos valores
    for (int i = 0; i < quantidade; i++) {
        frequencias[i] = 0; // Inicializa as frequências com zero
    }

    long int comparacoes = 0; // Variável para contar as comparações
    contarFrequenciaABP(arv, frequencias, &comparacoes);

    // Encontrar os 10 valores mais repetidos
    for (int i = 0; i < 10; i++) {
        int maxFrequencia = 0;
        int valorMaisRepetido = -1;

        for (int j = 0; j < quantidade; j++) {
            if (frequencias[j] > maxFrequencia) {
                maxFrequencia = frequencias[j];
                valorMaisRepetido = j;
            }
        }

        if (valorMaisRepetido != -1) {
            printf("Valor: %d - Frequência: %d\n", valorMaisRepetido, maxFrequencia);
            frequencias[valorMaisRepetido] = 0; // Zera a frequência para não contar novamente
        }
    }
}