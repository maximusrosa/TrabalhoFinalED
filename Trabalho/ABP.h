#ifndef ABP_H_
#define ABP_H_

typedef struct NodoABP ABP;

struct NodoABP {
    int info;
    ABP *esq;
    ABP *dir;
};

ABP* criaABP();
void insereABP(ABP **arv, int num, long int *comparacoes);
ABP* consultaABP(ABP *arv, int chave, long int *comparacoes);
ABP* destroiABP(ABP *arv);

// Retorna se encontrou ou não o valor
int consultaValorABP(ABP *arv, int valor, long int *comps);

//Encontra o menor valor
int encontraMenorValorABP(ABP *arv);

//Encontra o maior valor
int encontraMaiorValorABP(ABP *arv);

void dezMaisRepetidosABP(ABP *arv, int quantidade);

#endif // ABP_H_
