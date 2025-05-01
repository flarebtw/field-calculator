#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @brief Считывает введенное значение
 * @return Возвращает ощибку если число меньше либо равно 0, иначе возвращает введеное число
 */
int pInput(void);

/**
 * @brief Проверяет введеное значение на неотрицательность
 * @param value введеное значение
 * @return Возвращает ошибку если введеное значение меньше либо равно 0
 */
void checkValue(int value);

/**
 * @brief Проверяет, является ли введеное значение простым числом
 * @param p порядок поля
 * @return Возвращает ошибку если введеное число не простое
 */
void checkPrime(const int p);

/**
 * @brief Считывает введеное значение
 * @return Возвраащает введеное значение
 */
int Input(void);

/**
 * @brief Вычисляет значение дроби в поле z(p)
 * @param a Числитель дроби
 * @param b Знаменатель дроби
 * @param p Порядок поля
 * @return Возвращает значение дроби в поле z(p)
 */
int getX(const int a, const int b, const int p);

/**
 * @brief Вычисляет элемент в поле z(p)
 * @param number Исходное число
 * @param p Порядок поля
 * @return Возвращает значение элемента в поле z(p)
 */
int getElementInField(const int number,const int p);

/**
 * @param fraction дробь
 * @param integer целое
 */
enum{
    fraction,
    integer
};

/**
 * @brief Точка входа в программу
 * @return В случае успеха, возвращает 0
 */
int main(void) {
    int shouldContinue = 1;

    while (shouldContinue) {
        puts("Enter p value:");
        const int p = pInput();
        checkPrime(p);

        printf("Choose your element type:\n");
        printf("Fraction - %d\n", fraction);
        printf("Integer - %d\n", integer);
        const int choice = Input();
        switch (choice) {
        case fraction:
            printf("Enter your numerator: \n");
            const int a = Input();
            printf("Enter your denominator: \n");
            const int b = Input();
            printf("%d/%d in field of %d is %d\n", a, b, p, getX(a, b, p));
            break;
        case integer:
            printf("Enter your element: \n");
            const int number = Input();
            printf("%d in field of %d is: %d\n", number, p, getElementInField(number, p));
            break;
        default:
            errno = ERANGE;
            perror("Function does not exist");
            exit(EXIT_FAILURE);
            break;
        }

        printf("Do you want to run the program again? (1 - Yes, 0 - No): ");
        shouldContinue = Input();
        if (shouldContinue == 0) {
            printf("Exiting the program...\n");
        }

        while (getchar() != '\n'); 
    }

    return 0;
}

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