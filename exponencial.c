#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniforme(){
    double u = rand() / ((double) RAND_MAX + 1);
    //u == 0 -->  ln(u) <-- problema
    //limitando u entre (0,1]
    u = 1.0 - u;
    return u;
}

int main(){
    //Na Exponencial, E[X] = 1/l
    double l;
    printf("informe o tempo médio: ");
    scanf("%lf", &l);
    l = 1.0/l;

    int semente = time(NULL);
    srand(semente);

    //geracao dos valores
    double qtd_valores_gerados = 10000000;
    double soma = 0.0;


    for(int i = 0; i < qtd_valores_gerados; i++){
        double valor = (-1.0/l) * log(uniforme());
        printf("%lf\n",valor);
        getchar();
        soma += valor;
    }

    printf("Média dos valores gerados: %lf\n", (soma/qtd_valores_gerados));

    return 0;


}