#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Define the structure for the polynomial
struct Poly {
    struct Node* head;
};

// Function to add a term to the polynomial
void addTerm(struct Poly* poly, int coefficient, int exponent) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;

    if (poly->head == NULL) {
        poly->head = node;
    } else {
        struct Node* current = poly->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Poly* poly) {
    struct Node* current = poly->head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials and store the result in a third polynomial
void addPolynomials(struct Poly* poly1, struct Poly* poly2, struct Poly* resultPoly) {
    struct Node* current1 = poly1->head;
    struct Node* current2 = poly2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            addTerm(resultPoly, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            addTerm(resultPoly, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int sumCoeff = current1->coefficient + current2->coefficient;
            addTerm(resultPoly, sumCoeff, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // Handle remaining terms in poly1
    while (current1 != NULL) {
        addTerm(resultPoly, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    // Handle remaining terms in poly2
    while (current2 != NULL) {
        addTerm(resultPoly, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }
}

int main() {
    // Example usage
    struct Poly poly1 = {NULL};
    struct Poly poly2 = {NULL};
    struct Poly resultPoly = {NULL};

    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 4, 1);
    addTerm(&poly1, 5, 0);

    addTerm(&poly2, 2, 3);
    addTerm(&poly2, 1, 1);
    addTerm(&poly2, 7, 0);

    printf("Polynomial 1: ");
    displayPolynomial(&poly1);

    printf("Polynomial 2: ");
    displayPolynomial(&poly2);

    addPolynomials(&poly1, &poly2, &resultPoly);

    printf("Resultant Polynomial: ");
    displayPolynomial(&resultPoly);

    return 0;
}
