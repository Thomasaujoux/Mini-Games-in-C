// poly.h
#ifndef POLY_H
#define POLY_H

// Node structure for a polynomial term
typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode *next;
} PolyNode;

// Function prototypes
PolyNode* createNode(int coefficient, int exponent);
void appendTerm(PolyNode **head, int coeff, int exp);
void printPolynomial(PolyNode *p);
void freePolynomial(PolyNode *p);
PolyNode* addPolynomials(PolyNode *p1, PolyNode *p2);
PolyNode* subtractPolynomials(PolyNode *p1, PolyNode *p2);
PolyNode* multiplyPolynomials(PolyNode *p1, PolyNode *p2);
int evaluatePolynomial(PolyNode *p, int x);

#endif // POLY_H
