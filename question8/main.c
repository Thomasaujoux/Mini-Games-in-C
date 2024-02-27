// main.c
#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Define polynomial 1: 3x^3 + 2x^2 + x
    PolyNode *poly1 = NULL;
    appendTerm(&poly1, 3, 3);
    appendTerm(&poly1, 2, 2);
    appendTerm(&poly1, 1, 1);
    appendTerm(&poly1, 0, 0);

    // Define polynomial 2: 5x^2 + x + 10
    PolyNode *poly2 = NULL;
    appendTerm(&poly2, 5, 2);
    appendTerm(&poly2, 1, 1);
    appendTerm(&poly2, 10, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Perform and print operations
    PolyNode *sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPolynomial(sum);

    PolyNode *diff = subtractPolynomials(poly1, poly2);
    printf("Difference: ");
    printPolynomial(diff);
    

    PolyNode *prod = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    printPolynomial(prod);

    int x = 2;
    printf("Evaluation of Polynomial 1 at x = %d: %d\n", x, evaluatePolynomial(poly1, x));

    // Free the allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    freePolynomial(diff);
    freePolynomial(prod);

    return 0;
}