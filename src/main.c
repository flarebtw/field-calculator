#include "../include/FieldCalculator.h"

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