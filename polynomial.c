#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Polynomial {
    struct Node* head;
};

struct Polynomial* createPolynomial() {
    struct Polynomial* poly = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    poly->head = NULL;
    return poly;
}

void addTerm(struct Polynomial* poly, int coefficient, int exponent) {
    struct Node* newTerm = (struct Node*)malloc(sizeof(struct Node));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = poly->head;
    poly->head = newTerm;
}

struct Polynomial* addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2) {
    struct Polynomial* result = createPolynomial();
    struct Node* current1 = poly1->head;
    struct Node* current2 = poly2->head;

    while (current1 || current2) {
        if (current1 && current2 && current1->exponent == current2->exponent) {
            int coefficient = current1->coefficient + current2->coefficient;
            if (coefficient != 0) {
                addTerm(result, coefficient, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1 && (!current2 || current1->exponent > current2->exponent)) {
            addTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else {
            addTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    return result;
}

void printPolynomial(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current) {
        if (current->coefficient != 0) {
            if (current->exponent == 0) {
                printf("%d", current->coefficient);
            } else if (current->exponent == 1) {
                printf("%dx", current->coefficient);
            } else {
                printf("%dx^%d", current->coefficient, current->exponent);
            }
            if (current->next) {
                printf(" + ");
            }
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Polynomial* poly1 = createPolynomial();
    addTerm(poly1, 3, 4);
    addTerm(poly1, 2, 2);
    addTerm(poly1, 1, 0);

    struct Polynomial* poly2 = createPolynomial();
    addTerm(poly2, 4, 3);
    addTerm(poly2, 5, 1);

    struct Polynomial* result = addPolynomials(poly1, poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    // Clean up memory (free allocated nodes)
    // You can add this part to release memory after you're done with the polynomials.

    return 0;
}
