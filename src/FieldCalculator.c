#include "../include/FieldCalculator.h"

int pInput(void){
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        errno = EIO;
        perror("Value must be an integer");
        exit(EXIT_FAILURE);
    }
    checkValue(value);

    return value;
}

void checkValue(int value){
    if (value <= 0){
        errno = EIO;
        perror("Value must be higher than zero!");
        exit(EXIT_FAILURE);
    }
}

void checkPrime(const int p){
    if (p <= 1) {
        errno = EIO;
        perror("Value must be higher than 1");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            errno = EIO;
            perror("Value is not prime number");
            exit(EXIT_FAILURE);
        }
    }
}

int Input (void){
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        errno = EIO;
        perror("Input error");
        exit(EXIT_FAILURE);
    }
    return value;
}

int getElementInField(const int number, const int p){
    if (number % p == 0){
            return 0;
        }else
        if (number > 0){
            return number % p;
        }
        else{
            return p + (number % p);
        }
}

int getX(const int a, const int b, const int p){
    for(int x = 0; x < p; x++){
        if ((a-b*x) % p == 0){
            return x;
        }
    }
}