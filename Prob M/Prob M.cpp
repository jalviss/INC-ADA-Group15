#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    
    if (m * n == k) {
        printf("0\n");
    }
    else if (k % n == 0 || k % m == 0) {
        printf("1\n");
    }
    else {
        if (m > n){
            long long int temp = m;
            m = n;
            n = temp;
        }

        int flag = 0;

        for(long long int i = 1; i < n; i++){
            if(k % i == 0 && floor(k / i) < m){
                printf("2\n");
                flag = 1;
                break;
            }
            long long int temp = n * m - k;   
            if(temp % i == 0 && floor(temp / i) < m){
                printf("2\n");
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("3\n");
        }
    }
    
    return 0;
}


