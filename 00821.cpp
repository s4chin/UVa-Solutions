#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1e6

int fw[105][105];

int main() {
	int a, b, count = 1, n;
	while(1) {
		n = 0;
		scanf("%d%d",&a, &b);
		if(a==0 && b==0)
			break;
		for(int i=0; i<105; i++) for(int j=0; j<105; j++) fw[i][j] = INF;
		for(int i=0; i<105; i++) fw[i][i] = 0;
		while(true) {
			fw[a-1][b-1] = 1;
			n = max(n, max(a, b));
			scanf("%d%d", &a, &b);
			if(a==0 && b==0)
				break;
		}
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
		double ans = 0, nans = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(fw[i][j]!=INF && i!=j) {
					ans += fw[i][j];
					nans++;
				}
			}
		printf("Case %d: average length between pages = %.3lf clicks\n", count++, ans / nans);
	}
	return 0;
}
