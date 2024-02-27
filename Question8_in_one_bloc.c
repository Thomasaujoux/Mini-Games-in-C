#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode *next;
} PolyNode;

// Function prototypes
PolyNode* createNode(int coefficient, int exponent);
PolyNode* readPolynomial();
PolyNode* addPolynomials(PolyNode *p1, PolyNode *p2);
PolyNode* subtractPolynomials(PolyNode *p1, PolyNode *p2);
PolyNode* multiplyPolynomials(PolyNode *p1, PolyNode *p2);
int evaluatePolynomial(PolyNode *p, int x);

// Real definitions

// Function to create a new polynomial node
PolyNode* createNode(int coefficient, int exponent) {
    PolyNode *newNode = (PolyNode*)malloc(sizeof(PolyNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to read a polynomial from the user
PolyNode* readPolynomial() {
    int coefficient, exponent;
    PolyNode *head = NULL, *tail = NULL;

    printf("Enter polynomial terms (coefficient exponent). Enter 0 0 to end:\n");
    while (1) {
        scanf("%d %d", &coefficient, &exponent);
        if (coefficient == 0 && exponent == 0) {
            break;
        }
        PolyNode *newNode = createNode(coefficient, exponent);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    return head;
}

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL;
    PolyNode **node = &result;

    while (p1 && p2) {
        if (p1->exponent > p2->exponent) {
            *node = createNode(p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            *node = createNode(p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int sum = p1->coefficient + p2->coefficient;
            if (sum != 0) {
                *node = createNode(sum, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        node = &((*node)->next);
    }

    // Append the remaining terms of the longer polynomial
    while (p1) {
        *node = createNode(p1->coefficient, p1->exponent);
        p1 = p1->next;
        node = &((*node)->next);
    }
    while (p2) {
        *node = createNode(p2->coefficient, p2->exponent);
        p2 = p2->next;
        node = &((*node)->next);
    }

    return result;
}

// Function to subtract two polynomials
PolyNode* subtractPolynomials(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL;
    PolyNode **node = &result;

    while (p1 && p2) {
        if (p1->exponent > p2->exponent) {
            *node = createNode(p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            // Negate the coefficient because we are subtracting
            *node = createNode(-p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            // Subtract the coefficients
            int difference = p1->coefficient - p2->coefficient;
            if (difference != 0) {
                *node = createNode(difference, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if (*node) {
            node = &((*node)->next);
        }
    }

    // Append the remaining terms of the longer polynomial
    while (p1) {
        *node = createNode(p1->coefficient, p1->exponent);
        p1 = p1->next;
        node = &((*node)->next);
    }
    while (p2) {
        // Negate the coefficient because we are subtracting
        *node = createNode(-p2->coefficient, p2->exponent);
        p2 = p2->next;
        node = &((*node)->next);
    }

    return result;
}


// Helper function to insert a new term into the result polynomial in sorted order
void insertTerm(PolyNode **head, int coeff, int exp) {
    PolyNode *newNode = createNode(coeff, exp);
    if (!*head || exp > (*head)->exponent) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PolyNode *current = *head;
        while (current->next && current->next->exponent >= exp) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode *p1, PolyNode *p2) {
    if (!p1 || !p2) {
        return NULL;
    }

    PolyNode *result = NULL;
    for (PolyNode *i = p1; i != NULL; i = i->next) {
        PolyNode *temp = NULL;
        for (PolyNode *j = p2; j != NULL; j = j->next) {
            insertTerm(&temp, i->coefficient * j->coefficient, i->exponent + j->exponent);
        }
        result = addPolynomials(result, temp);
    }

    return result;
}

// Function to evaluate a polynomial at a given value of x using Horner's method
// Make sure that you defined your polynom such that all the coefficient are defined going from your largest exposant to the smallest equal to 0, if some coeffcients are null you need to write them for the evaluation function to work adequatly
int evaluatePolynomial(PolyNode *p, int x) {
    if (!p) {
        return 0;
    }
    int result = p->coefficient;
    p = p->next;
    while (p != NULL) {
        result = result * x + p->coefficient;
        p = p->next;
    }
    return result;
}


// Help functions to test my code above 
// Function to append a term to the polynomial
void appendTerm(PolyNode **head, int coeff, int exp) {
    PolyNode *newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        PolyNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print a polynomial
void printPolynomial(PolyNode *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%dx^%d ", p->coefficient, p->exponent);
        if (p->next != NULL && p->next->coefficient >= 0) {
            printf("+ ");
        }
        p = p->next;
    }
    printf("\n");
}

// Helper function to free polynomial memory
void freePolynomial(PolyNode *p) {
    while (p != NULL) {
        PolyNode *temp = p;
        p = p->next;
        free(temp);
    }
}

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