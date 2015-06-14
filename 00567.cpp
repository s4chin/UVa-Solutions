#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1000

int fw[25][25];

int main() {
	int count = 1, n, c, t, a, b;
	while(cin>>n) {
		for(int i=0; i<25; i++) for(int j=0; j<25; j++) fw[i][j] = INF;
		for(int i=0; i<25; i++) fw[i][i] = 0;
		for(int i=0; i<n; i++) {
			scanf("%d", &c);
			fw[0][c-1] = 1;
			fw[c-1][0] = 1;
		}
		for(int i=1; i<=18; i++) {
			scanf("%d", &n);
			for(int j=0; j<n; j++) {
				scanf("%d", &c);
				fw[i][c-1] = 1;
				fw[c-1][i] = 1;
			}
		}
		for(int k=0; k<20; k++)
			for(int i=0; i<20; i++)
				for(int j=0; j<20; j++)
					fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
		scanf("%d", &t);
		printf("Test Set #%d:\n", count++);
		while(t--) {
			scanf("%d%d", &a, &b);
			printf("%d to %d: %d\n", a, b, fw[a-1][b-1]);
		}
		printf("\n");
	}
	return 0;
}
