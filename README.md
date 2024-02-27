# Mini-Games-in-C

This repository encompass various functionalities, including a Tic-Tac-Toe game, implementations of the Sieve of Eratosthenes algorithm (both standard and optimized versions), and operations on polynomials (such as addition, subtraction, multiplication, and evaluation).

## Tic-Tac-Toe Game

### Overview
This section of the code facilitates a two-player Tic-Tac-Toe game within the console. The game's board is represented as a 3x3 matrix, initially filled with numbers 1 through 9. Players take turns to replace these numbers with 'X' or 'O'. The game includes checks for a winner after each move or declares a draw if the board fills up without any winning condition met.

### Key Functions
- `ViewBoard`: Displays the current state of the game board.
- `IsWinner`: Determines if there is a winner by checking all rows, columns, and diagonals for three identical markers ('X' or 'O') in a sequence.
- `NoWinner`: Verifies if the board is fully occupied without any player winning, indicating a draw.

## Sieve of Eratosthenes

### Standard Implementation (`sieveOfEratosthenes`)
Identifies prime numbers up to a specific limit `n` by progressively marking the multiples of each prime number, starting from 2, as non-prime. The process ceases marking for numbers greater than the square root of `n`.

### Optimized Implementation (`sieveOfEratosthenesOpti`)
Enhances memory and computational efficiency by focusing solely on odd numbers, given 2 is the only even prime. This approach utilizes a compact array, where each position signifies an odd number, to further optimize performance.

## Polynomial Operations

### Data Structure
Polynomials are represented using a linked list structure, where each node (`PolyNode`) includes a coefficient, an exponent, and a pointer to the next term.

### Key Operations
- `createNode`: Generates and initializes a new term of a polynomial.
- `readPolynomial`: Accepts user input for polynomial terms until `0 0` is entered, creating a linked list representation of the polynomial.
- `addPolynomials`, `subtractPolynomials`, `multiplyPolynomials`: Perform addition, subtraction, and multiplication of polynomials, respectively, yielding a new polynomial (linked list) as the result.
- `evaluatePolynomial`: Calculates the value of a polynomial for a specified value of `x`.

These snippets are structured to demonstrate essential programming concepts like dynamic memory management, linked lists, algorithmic implementation, and interactive console inputs, providing foundational functionalities for their respective tasks.
