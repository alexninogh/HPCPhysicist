//Author: Alessandro Renzi - Date: 08/07/2025 - License: GPL3
#include <stdio.h>
#include <stdlib.h>

/* daxpy.c - A simple DAXPY implementation in C.

This program demonstrates the DAXPY operation, which is fundamental in
linear algebra and scientific computing. The name stands for
"Double-precision a*X Plus Y". It calculates the result of scaling a
vector X by a scalar a and adding the result to another vector D.
 
The operation is: D = a*X + Y
*/

/* --- Function Prototypes ---

Those are not really useful in a single file program but are useful
as placeholders to remember which functions are defined in this program
Defining function prototypes here permit to define the implementation later, for
example after the main.
*/

void daxpy(size_t N, double a, double *X, double *Y, double *D); //out-of-place daxpy
void daxpy(size_t N, double a, double *X, double *Y); //in-place daxpy
void print_vector(const char *name, size_t N, double *v);

// --- Main ---

int main(void) {

/* --- Inputs ---

While this program is very simple, it is important to distinguish inputs from outputs
and from "core logic"
*/
    
    /* --- NOTE ---

    size_t will allow the use arrays with dimension as big as the available memory
    e.g. sizeof(size_t) = 64 for a 64bit system

    There is nothing to gain to keep the array size less than size_t since in general X, Y and D
    will always be greather than few elements up to millions or billions of elements. 

    About the use of size_t for the dimension of an array,
    see: https://www.gnu.org/software/libc/manual/html_node/Important-Data-Types.html
    */
    size_t N = 5; //N: The number of elements in our arrays/vectors.

    double a = 2.0; // a: The scalar value, scale factor of X (a double-precision floating-point number).

/* --- Structures and data initializations ---

In this version of the code "serial_axpy_malloc" we are going to use malloc to avoid the filling of the stack size
related to the allocation of static "c-array" like in "serial_axpy_array".
------> FAI NOTARE che array e' un caso speciale in quanto siccome e' un esempio "stupido" conosciamo il valore della 
dimensione dell'array a compile time e quindi possiamo fare l'errore dell'allocazione statica in stack, ma in generale
N e' una variabile he conosciamo solo a run-time e quindi dobbiamo per forza usare l'allocazione dinamica e quindi\
malloc.
*/

    // X: The first input vector. We allocate memory for 'N' doubles.
    double *X = malloc(sizeof(double) * N);
    if (X == NULL) { //if not enough dynamic memory available allocation would fail!
        perror("malloc for X failed");
        return 1;
    }

    // Y must be the same size of X
    double *Y = malloc(sizeof(double) * N);
    if (Y == NULL) { //if not enough dynamic memory available allocation would fail!
        perror("malloc for Y failed");
        free(Y); // Clean up previously allocated memory
        return 1;
    }

    /* Initialize our vectors with some special data.

    By using this simple initialization X, Y = i with i = 1, 2, ... , N we can use mathematics
    to check the correctness of our results with automatic tests, since
    D[i] = i*(a + 1) and
    sum(D) = a*sum(X) + sum(Y) = N*(N+1)/2*(a+1) (see https://en.wikipedia.org/wiki/Summation) 
    
    This is of little important now that the code is serial, but will be of crucial importance when 
    we will start to implement parallelization!
    */
    for (size_t i = 0; i < N; i++) {
        X[i] = i + 1.0; // X = [1.0, 2.0, 3.0, ..., N]
        Y[i] = i + 1.0; // Y = [1.0, 2.0, 3.0, ..., N]
    }

    // D must be allocated with the same size of X and Y
    double *D = malloc(sizeof(double) * N);
    if (D == NULL) { //if not enough dynamic memory available allocation would fail!
        perror("malloc for D failed");
        free(D); // Clean up previously allocated memory
        return 1;
    }

// --- Core Logic ---

    printf("## Arrays initialization **before** DAXPY ##\n");
    print_vector("X", N, X);
    print_vector("Y", N, Y);
    print_vector("D", N, D);
    printf("a = %f\n\n", a);

    // Perform the DAXPY operation.
    daxpy(N, a, X, Y, D);

// --- Outputs ---

    printf("## Output Array **after** DAXPY ##\n");
    print_vector("Result (D)", N, D);

// --- Cleanup ---

    // Free the memory we allocated to prevent memory leaks.
    free(X);
    free(Y);

    return 0;
}

/*
The daxpy function takes the number of elements 'N', the scalar 'a',
and pointers to the vectors 'X' and 'Y' as input. It then
performs the 'd = a*x + y' operation and stores the result into 'd'.
*/
void daxpy(size_t n, double a, double *x, double *y) {
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
 void print_vector(const char *name, size_t n, double *v) {
    printf("%s = [", name);
    for (int i = 0; i < n; i++) {
        printf(" %f", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}
