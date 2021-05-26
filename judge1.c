#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int counter = 0;

int ones_counter(int numero){
    int i=0;
    int currentCounter=0;
    for(i;i<(sizeof(int)*8);i++) { 
        if(1&numero) currentCounter++; numero = numero>>1;
    }
    return currentCounter;
}

int main()
{
    long long int limite_inferior;
    long long int limite_superior;
    scanf("%lld %lld", &limite_inferior, &limite_superior);

    long long int j = limite_inferior;
    for(j; j<= limite_superior; j++){
        counter = ones_counter(j) + counter;
    }
    printf("%lld\n", counter);
    return 0;
}
