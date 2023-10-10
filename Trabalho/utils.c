#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Retorna um número aleatório entre 1 e o parâmetro informado
int gera_num_aleatorio(int max) {
    int randomNumber;

    if (max <= RAND_MAX) 
        randomNumber = rand();
    
    return 1 + (randomNumber % max) * (1 + (rand() % 5));

}

void generateRandomNumbersWithDuplicates(int totalNumbers, int duplicationPercent, int **resultNumbers) {
    srand(time(NULL));

    // Calcula o número mínimo de duplicatas
    int minDuplicates = totalNumbers * duplicationPercent / 100;

    // Calcula o número de números únicos
    int uniqueCount = totalNumbers - minDuplicates;

    // Alocar memória para o array de números resultante
    *resultNumbers = (int *)malloc(totalNumbers * sizeof(int));

    if (*resultNumbers == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        exit(1);
    }

    // Gera os números únicos
    for (int i = 0; i < uniqueCount; i++) {
        (*resultNumbers)[i] = rand() % (totalNumbers * 10) + 1;
    }

    // Gera as duplicatas
    for (int i = uniqueCount; i < totalNumbers; i++) {
        (*resultNumbers)[i] = (*resultNumbers)[rand() % uniqueCount];
    }

    // Embaralha os números para garantir aleatoriedade
    for (int i = totalNumbers - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = (*resultNumbers)[i];
        (*resultNumbers)[i] = (*resultNumbers)[j];
        (*resultNumbers)[j] = temp;
    }
}


