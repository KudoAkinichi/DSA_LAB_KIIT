#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

void inputComplex(struct Complex* c) {
    printf("Enter complex number (real imaginary): ");
    scanf("%lf %lf", &c->real, &c->imaginary);
}

void addComplex(struct Complex c1, struct Complex c2, struct Complex* result) {
    result->real = c1.real + c2.real;
    result->imaginary = c1.imaginary + c2.imaginary;
}

void multiplyComplex(const struct Complex* c1, const struct Complex* c2, struct Complex* result) {
    result->real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    result->imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
}

int main() {
    struct Complex complex1, complex2, result;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputComplex(&complex1);
                inputComplex(&complex2);
                addComplex(complex1, complex2, &result);
                printf("Sum = %.2lf+%.2lfi\n", result.real, result.imaginary);
                break;

            case 2:
                inputComplex(&complex1);
                inputComplex(&complex2);
                multiplyComplex(&complex1, &complex2, &result);
                printf("Product = %.2lf+%.2lfi\n", result.real, result.imaginary);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
