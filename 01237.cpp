#include<cstdio>
 
using namespace std;
 
int T, D, L[20000], H[20000], Q, P;
char M[20000][30];
 
int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &D);
        for(int i = 0; i < D; i++)
            scanf("%s %d %d", M[i], &L[i], &H[i]);
 
        scanf("%d", &Q);
        for(int i = 0; i < Q; i++) {
            scanf("%d", &P);
            int ind = -1;
            for(int j = 0; j < D; j++) {
                if(P >= L[j] && P <= H[j]) {
                    if(ind < 0)
                        ind = j;
                    else {
                        ind = -1;
                        break;
                    }
                }
            }
            if(ind < 0)
                printf("UNDETERMINED\n");
            else
                printf("%s\n", M[ind]); 
        }
        if(T) printf("\n");
    }
    return 0;
}
