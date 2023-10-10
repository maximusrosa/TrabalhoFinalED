#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABP.h"
#include "utils.h"
#include "options.h"
#include "aleatoria_ABP.h"

void analiseAleatoriaABP (int quantidade)
{
    ABP *arv;
    clock_t start, end;
    double miliseconds;
    long int comparacoes;

    start = clock();                                            // inicia a contagem do tempo para inserção
    arv = insereAleatorioABP(quantidade, &comparacoes);
    end = clock();                                              // finaliza contagem do tempo para inserção

    miliseconds = (float)(end - start) / CLOCKS_PER_SEC * 1000; // calcula o tempo decorrido

    printf("\n%d dados foram inseridos em %.0f ms.\n", quantidade, miliseconds);
    printf("Comparacoes realizadas: %ld\n", comparacoes);


    printf("\nConsultas\n");
    consultaAleatoriaABP(arv);

    arv = destroiABP(arv);
}

ABP* insereAleatorioABP(int quantidade, long int *comps) {
    ABP *arv = malloc(sizeof(ABP));
    clock_t start, end;
    int i, aviso, num_aleatorio;
    long int total_comparacoes = 0;
    long int compTemp;
    float miliseconds;
    FILE* arq_saida = fopen("insere.txt", "w");

    arv = criaABP();

    aviso = 0.01 * quantidade;

    start = clock();

    printf("Insercao |Tempo\t|Comparacoes\n");

    for (i = 1; i <= quantidade; i++)
    {
        num_aleatorio = gera_num_aleatorio(quantidade);

        insereABP(&arv, num_aleatorio, &compTemp);

        total_comparacoes += compTemp;

        if (i % aviso == 0 || i == 0)
        {
            end = clock();
            miliseconds = (float) (end - start) / CLOCKS_PER_SEC * 1000;
            printf("%d\t | %.0f\t|%ld\n", i, miliseconds, compTemp);
            fprintf(arq_saida, "%d %.0f %ld\n", i, miliseconds, compTemp);
        }
    }

    *comps = total_comparacoes;

    fclose(arq_saida);

    return arv;
}

void consultaAleatoriaABP (ABP *arv) {
    double temposConsulta[3];
    long int comparacoes[3];
    int i, sucessoConsulta;
    int valores[3]; // valor mínimo, valor médio e valor máximo
    FILE* arq_saida = fopen("consulta.txt", "w");

    clock_t start, end;

    valores[0] = encontraMenorValorABP(arv);
    valores[1] = encontraMaiorValorABP(arv) / 2;
    valores[2] = encontraMaiorValorABP(arv);

    for (i = 0; i < 3; i++)
    {
        start = clock();
        sucessoConsulta = consultaValorABP(arv, valores[i], &comparacoes[i]);
        end = clock();

        temposConsulta[i] = end - start / CLOCKS_PER_SEC * 1000;

        if (sucessoConsulta)
            printf("Valor %d encontrado na arvore.\n", valores[i]);
        else
            printf("Valor %d nao encontrado na arvore.\n", valores[i]);
    }

    //dezMaisRepetidosABP(arv, quantidade);

    printf("\nTempos de consulta\n"
           "Menor valor: %.2f | Comparacoes: %ld\n"
           "Valor Medio: %.2f | Comparacoes: %ld\n"
           "Maior valor: %.2f | Comparacoes: %ld\n",
           temposConsulta[0], comparacoes[0],
           temposConsulta[1], comparacoes[1],
           temposConsulta[2], comparacoes[2]);

    fprintf(arq_saida, "%d %ld\n %d %ld\n %d %ld\n",
            valores[0], comparacoes[0],
            valores[1], comparacoes[1],
            valores[2], comparacoes[2]);
}

