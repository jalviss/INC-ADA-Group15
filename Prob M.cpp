#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    
    if (m * n == k) {
        printf("0\n");
        return 0;
    }
    if (k % m == 0 || k % n == 0) {
        printf("1\n");
        return 0;
    }
    for (long long int j = 1; j < m; j++) {
        long long int temp = k - j * n;
        if ((temp < 0 && temp % j == 0) || (temp > 0 && temp % (m - j) == 0)) {
            printf("2\n");
            return 0;
        }
    }
    
    printf("3\n");
    
    return 0;
}


