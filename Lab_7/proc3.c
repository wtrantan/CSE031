#include<stdio.h>

int bar(int a, int b, int c) {
    return (b - a) << (c);
}

int foo(int m, int n, int o) {
    int p = bar(m + o, n + o, m + n); //(1+3,2+3,1+2) = (4,5,3)
    int q = bar(m - o, n - m, n + n); //(1-3,2-1,2+2) = (-2,1, 4)
    printf("p + q: %d\n", p + q);
    return p + q;
}

int main() {
    int x = 1, y = 2, z = 3;
    z = x + y + z + foo(x, y, z);
    printf("%d\n", z);
    return 0;
}
