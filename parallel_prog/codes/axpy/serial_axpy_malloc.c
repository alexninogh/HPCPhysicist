//Author: Alessandro Renzi - Date: 08/07/2025 - License: GPL3
#include <stdio.h>
#include <stdlib.h>

/* daxpy.c - A simple DAXPY implementation in C.

 This program demonstrates the DAXPY operation, which is fundamental in
 linear algebra and scientific computing. The name stands for
 "Double-precision A*X Plus Y". It calculates the result of scaling a
 vector X by a scalar A and adding the result to another vector Y.
 
 The operation is: Y = A * X + Y
 
*/

/* --- Function Prototypes ---
  Those are not really useful in a single file program but are useful
  as placeholders to remember which functions are defined in this program
  Defining function prototypes here permit to define the implementation later, for
  example after the main.
*/
void daxpy(int n, double a, double *x, double *y);
void print_vector(const char *name, int n, double *v);

// --- Main ---

int main(void) {

/* --- Inputs ---
 * While this program is very simple, it is important to distinguish inputs from outputs
 * and from "core logic"
 */

    // N: The number of elements in our vectors.
    int n = 5;

    // A: The scalar value (a double-precision floating-point number).
    double a = 2.0;

/* --- Structures and data initializations ---
*/

    // X: The first input vector. We allocate memory for 'n' doubles.
    double *x = malloc(sizeof(double) * n);
    if (x == NULL) {
        perror("malloc for x failed");
        return 1;
    }

    // Y: The second input vector, which will also store the result.
    double *y = malloc(sizeof(double) * n);
    if (y == NULL) {
        perror("malloc for y failed");
        free(x); // Clean up previously allocated memory
        return 1;
    }

    // Initialize our vectors with some example data.
    for (int i = 0; i < n; i++) {
        x[i] = i + 1.0; // X = [1.0, 2.0, 3.0, 4.0, 5.0]
        y[i] = i + 1.0; // Y = [1.0, 2.0, 3.0, 4.0, 5.0]
    }

// --- Core Logic ---

    printf("## Before DAXPY ##\n");
    print_vector("X", n, x);
    print_vector("Y", n, y);
    printf("A = %f\n\n", a);

    // Perform the DAXPY operation.
    daxpy(n, a, x, y);

// --- Outputs ---

    printf("## After DAXPY ##\n");
    print_vector("Result (Y)", n, y);

// --- Cleanup ---

    // Free the memory we allocated to prevent memory leaks.
    free(x);
    free(y);

    return 0;
}

/*
 * The daxpy function itself.
 *
 * This function takes the number of elements 'n', the scalar 'a',
 * and pointers to the vectors 'x' and 'y' as input. It then
 * performs the 'a*x + y' operation and stores the result back into 'y'.
 */
void daxpy(int n, double a, double *x, double *y) {
    for (int i = 0; i < n; i++) {
        y[i] = a * x[i] + y[i];
    }
}

/*
 * A helper function to print the contents of a vector.
 *
 * This makes it easy to visualize the vectors before and after the
 * DAXPY operation.
 */
void print_vector(const char *name, int n, double *v) {
    printf("%s = [", name);
    for (int i = 0; i < n; i++) {
        printf(" %f", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}