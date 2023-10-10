#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include "options.h"
#include "ordenada_ABP.h"
#include "ordenada_LSE.h"
#include "aleatoria_ABP.h"
#include "aleatoria_LSE.h"


int main() {
    char opcao_quantidade;
    int opcao_analise;
    int quantidade;
    char continuar;

    setlocale(LC_ALL,""); // para imprimir corretamente na tela os caracteres acentuados

    /* Menu da aplicação */
    do {

        do {
            printf("Quantos dados deseja inserir?\n");
            printf("P - %d dados\n", PEQUENA);
            printf("M - %d dados\n", MEDIA);
            printf("G - %d dados\n", GRANDE);

            printf("Entre a opcao: ");
            scanf("%c", &opcao_quantidade);
            fflush(stdin);

            opcao_quantidade = toupper(opcao_quantidade);

            if (opcao_quantidade != 'P' && opcao_quantidade != 'M' && opcao_quantidade != 'G')
                printf("\nOpcao invalida.\n\n");

        } while (opcao_quantidade != 'P' && opcao_quantidade != 'M' && opcao_quantidade != 'G');

        switch (opcao_quantidade)
        {
            case 'P':
                quantidade = PEQUENA;
                break;
            case 'M':
                quantidade = MEDIA;
                break;
            case 'G':
                quantidade = GRANDE;
                break;
            default:
                quantidade = 0;
        }

        printf("\nOpcao escolhida: %c - %d\n\n", opcao_quantidade, quantidade);


        do {
            printf("Qual analise voce deseja executar?\n");
            printf("1 - Ordenadas\n");
            printf("2 - Aleatorias\n");
            printf("3 - LSE Ordenada\n");
            printf("4 - LSE Aleatoria\n");
            printf("5 - ABP Ordenada\n");
            printf("6 - ABP Aleatoria\n");

            printf("Escolha sua opcao:\n");
            scanf("%d", &opcao_analise);
            fflush(stdin);

            if (opcao_analise < 1 || opcao_analise > 6)
                printf("\nOpcao invalida.\n\n");

        } while (opcao_analise < 1 || opcao_analise > 6);

        switch (opcao_analise)
        {
            case 1:
                printf("\n====================================\n");

                printf("Analise Ordenada da LSE\n\n");
                analiseOrdenadaLSE(quantidade);

                printf("\n====================================\n");

                printf("Analise Ordenada da ABP\n\n");
                analiseOrdenadaABP(quantidade);

                printf("\n====================================\n");
                break;

            case 2:
                printf("\n====================================\n");

                printf("Analise Aleatoria da LSE\n\n");
                analiseAleatoriaLSE(quantidade);

                printf("\n====================================\n");

                printf("Analise Aleatoria da ABP\n\n");
                analiseAleatoriaABP(quantidade);

                printf("\n====================================\n");
                break;

            case 3:
                printf("\n====================================\n");

                printf("Analise Ordenada da LSE\n\n");
                analiseOrdenadaLSE(quantidade);

                printf("\n====================================\n");
                break;

            case 4:
                printf("\n====================================\n");

                printf("Analise Aleatoria da LSE\n\n");
                analiseAleatoriaLSE(quantidade);

                printf("\n====================================\n");

                break;

            case 5:
                printf("\n====================================\n");

                printf("Analise Ordenada da ABP\n\n");
                analiseOrdenadaABP(quantidade);

                printf("\n====================================\n");
                break;

            case 6:
                printf("\n====================================\n");

                printf("Analise Aleatoria da ABP\n\n");
                analiseAleatoriaABP(quantidade);

                printf("\n====================================\n");
                break;
            default:
                printf("ERRO!\n");
                break;

        }

        printf("\n(N) Sair (C) Continuar.\n");

        scanf("%c", &continuar);
        fflush(stdin);

    } while (tolower(continuar) != 'n');


    return 0;
}
