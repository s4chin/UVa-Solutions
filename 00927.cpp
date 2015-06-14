#include<cmath>
#include<cstdio>
 
using namespace std;
 
int C, T, coefs[30], d, k;
int seq[1000000];
 
int prep() {
    int sum = 0;
    seq[0] = sum;
    for(int i = 0;; i++) {
        sum = sum + i;
        if(sum >= 1000000) break;
        seq[sum] = i + 1;
    }
}
 
unsigned long long eval(int n, int i) {
    if(i == T) return 0;
    return coefs[i] * pow(n, i) + eval(n, i + 1);
}
 
int main() {
    prep();
    scanf("%d", &C);
    while(C--) {
        scanf("%d", &T); 
        T++;
        for(int i = 0; i < T; i++)
            scanf("%d", &coefs[i]);
        scanf("%d\n%d", &d, &k);
        int ind = (k - 1) / d;
        while(ind > 0 && seq[ind] == 0) ind--;
        printf("%llu\n", eval(seq[ind], 0));
    }
}
