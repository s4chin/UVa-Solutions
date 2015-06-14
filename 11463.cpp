#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1e9

int fw[105][105];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int t, n, r, u, v, max, count = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &r);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(i == j)
					fw[i][j] = 0;
				else fw[i][j] = INF;
			}
		max = 0;
		while(r--) {
			scanf("%d%d", &u, &v);
			fw[u][v] = 1;
			fw[v][u] = 1;
		}
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					fw[i][j] = min(fw[i][k] + fw[k][j], fw[i][j]);
		scanf("%d%d", &u, &v);
		for(int i=0; i<n; i++)
			if(max < fw[u][i] + fw[i][v])
				max = fw[u][i] + fw[i][v];
		printf("Case %d: ", count++);
		printf("%d\n", max);
	}
	return 0;
}
