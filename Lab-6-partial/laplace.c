#include <stdio.h>
#include <math.h>

#define NX 4   // Number of grid points in x direction
#define NY 4   // Number of grid points in y direction
#define MAX_ITER 10000 // Maximum number of iterations
#define TOLERANCE 1e-5 // Tolerance for convergence

int main() {
    double dx = 1.0;
    double dy = 1.0;
    double h = dx * dy;

    double u[NX][NY]; // Solution array
    double u_old[NX][NY]; // Previous solution array

    // Initialize boundary conditions
   double boundaries[NX][NY] = {
        {1000, 1000, 1000, 1000},
        {2000, 0, 0, 500},
        {2000, 0, 0, 0},
        {100, 500, 0, 0}
    };

    // Copy boundary conditions to solution array
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            u[i][j] = boundaries[i][j];
            u_old[i][j] = u[i][j];
        }
    }

    // Iterative solution using finite difference method
    int iter = 0;
    double error = 1.0;
    while (iter < MAX_ITER && error > TOLERANCE) {
        error = 0.0;
        // Jacobi iteration
        for (int i = 1; i < NX - 1; i++) {
            for (int j = 1; j < NY - 1; j++) {
                u_old[i][j] = u[i][j];
                u[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1]);
                error += fabs(u[i][j] - u_old[i][j]);
            }
        }
        error /= (NX - 2) * (NY - 2); // Normalize error
        iter++;
    }

    // Print the values of u1, u2, u3, u4
    printf("u1 at (1,1) = %.2f\n", u[1][1]);
    printf("u3 at (2,1) = %.2f\n", u[2][1]);
    printf("u2 at (1,2) = %.2f\n", u[1][2]);
    printf("u4 at (2,2) = %.2f\n", u[2][2]);

    return 0;
}
