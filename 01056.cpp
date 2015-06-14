#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define INF 1e9

int fw[55][55];
map<string, int> pplIdx;

int main() {
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int count = 1, r, n, ans, idx;
	char n1[100], n2[100];
	string n1s, n2s;
	while(true) {
		scanf("%d%d", &n, &r);
		if(n==0 && r==0)
			break;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(i == j)
					fw[i][j] = 0;
				else fw[i][j] = INF;
			}
		ans = 0;
		pplIdx.clear();
		idx = 0;
		while(r--) {
			scanf("%s", n1);
			scanf("%s", n2);
			n1s = string(n1);
			n2s = string(n2);
			if(pplIdx.count(n1s) == 0)
				pplIdx[n1s] = idx++;
			if(pplIdx.count(n2s) == 0)
				pplIdx[n2s] = idx++;
			fw[pplIdx[n1s]][pplIdx[n2s]] = 1;
			fw[pplIdx[n2s]][pplIdx[n1s]] = 1;
		}
		for(int k=0; k<n; k++)
			for(int i=0; i < n; i++)
				for(int j=0; j<n; j++)
					fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(fw[i][j] > ans)
					ans = fw[i][j];
		printf("Network %d: ", count++);
		printf(ans<INF?"%d\n\n":"DISCONNECTED\n\n", ans);
	}
	return 0;
}
