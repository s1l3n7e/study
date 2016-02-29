#include <stdio.h>

int fac(int num) {
    if (num < 2)
        return 1;
    else return num * fac(num - 1);
}

void main() {
    int i = 0;
    double eps = 0, result = 2, instance = 10;
    scanf("%lf", &eps);

    for (i = 2; instance >= eps; i++)
    {
        instance = 1.0/fac(i);
        result += instance;
    }

    printf("%lf", result);
}