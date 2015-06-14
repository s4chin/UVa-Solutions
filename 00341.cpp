#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1e9

int fw[15][15], p[15][15], n, d, r, source, destination, neighbor, number(0);

void printPath(int i, int j) {
	if(i!=j) printPath(i, p[i][j]);
	printf(" %d", j);
}

int main() {
	while(true) {
		scanf("%d", &n);
		if(n==0) break;
		else {
			number++;
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					fw[i][j] = INF;
			for(int i=1; i<=n; i++) {
				scanf("%d", &r);
				if(r==0)continue;
				for(int j=1; j<=r; j++) {
					scanf("%d%d", &neighbor, &d);
					fw[i][neighbor] = d;
				}
			}
			scanf("%d%d", &source, &destination);
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					p[i][j] = i;
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					for(int k=1; k<=n; k++)
						if(fw[i][k] + fw[k][j] < fw[i][j]) {
							fw[i][j] = fw[i][k] + fw[k][j];
							p[i][j] = p[k][j];
						}
			printf("Case %d: Path = ", number);
			printPath(source, destination);
			printf("; %d second delay\n", fw[source][destination]);
		}
	}
	return 0;
}
