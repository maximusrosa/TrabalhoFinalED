#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LSE.h"
#include "utils.h"
#include "options.h"
#include "aleatoria_LSE.h"

LSE* insereAleatorioLSE(int quantidade, long int *comps) {
    LSE* ptLista = malloc(sizeof(LSE));
    clock_t start, end;
    int num_aleatorio, i;
    long int total_comparacoes = 0;
    long int compTemp;
    float miliseconds;
    FILE* arq_saida = fopen("insere.txt", "w");

    int aviso = (0.01 * quantidade);

    start = clock();

    printf("Insercao |Tempo\t|Comparacoes\n");

    for (i = 1; i <= quantidade; i++)
    {
        num_aleatorio = gera_num_aleatorio(quantidade);

        insereFim(ptLista, num_aleatorio, &compTemp);

        if (i % aviso == 0 || i == 0)
        {
            end = clock();
            miliseconds = (end - start) / CLOCKS_PER_SEC * 1000;
            printf("%d\t | %.0f\t|%ld\n", i, miliseconds, compTemp);
            fprintf(arq_saida, "%d %.0f %ld\n", i, miliseconds, compTemp);
        }

    }

    *comps = total_comparacoes;

    fclose(arq_saida);
    return ptLista;
}

void analiseAleatoriaLSE(int quantidade) {
    LSE *ptLista;
    clock_t start, end;
    float miliseconds;
    long int comparacoes;

    start = clock();                                            // inicia a contagem do tempo para inserção
    ptLista = insereAleatorioLSE(quantidade, &comparacoes);
    end = clock();                                              // finaliza contagem do tempo para inserção

    miliseconds = (float)(end - start) / CLOCKS_PER_SEC * 1000; // calcula o tempo decorrido

    printf("\n%d dados foram inseridos em %.0f ms.\n", quantidade, miliseconds);
    printf("Comparacoes realizadas: %ld\n", comparacoes);


    printf("\nConsultas\n");
    consultaAleatoriaLSE(ptLista);

    ptLista = destroiLista(ptLista);
}

void consultaAleatoriaLSE (LSE *ptLista) {
    double temposConsulta[3];
    long int comparacoes[3];
    int i, sucessoConsulta;
    int valores[3]; // valor mínimo, valor médio e valor máximo
    FILE* arq_saida = fopen("consulta.txt", "w");

    clock_t start, end;

    valores[0] = encontraMenorValorLSE(ptLista);
    valores[1] = encontraMaiorValorLSE(ptLista) / 2;
    valores[2] = encontraMaiorValorLSE(ptLista);

    start = clock();

    for (i = 0; i < 3; i++)
    {
        sucessoConsulta = consultaValorLSE(ptLista, valores[i], &comparacoes[i]);
        end = clock();

        temposConsulta[i] = end - start / CLOCKS_PER_SEC * 1000;

        if (sucessoConsulta)
            printf("Valor %d encontrado na lista.\n", valores[i]);
        else
            printf("Valor %d nao encontrado na lista.\n", valores[i]);
    }


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






