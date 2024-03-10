#include <stdio.h>
#include <math.h>

float f(float x, float y) {
    return y + exp(x);
}

int main() {
    float x0, y0, xn, h, yn, k1, k2;
    int i, n;

    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    h = (xn - x0) / n;

    printf("\nx0\ty0\tyn\n");
    for (i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h, y0 + k1);
        
        yn = y0 + (k1 + k2) / 2;
        
        printf("%0.4f\t%0.4f\t%0.4f\n", x0, y0, yn);
        x0 += h;
        y0 = yn;
    }

    printf("\nValue of y at x = %0.2f is %0.3f", xn, yn);

    return 0;
}