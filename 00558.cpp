#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	int n, m, c, x, y, t;
	vector<vii> AdjList;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &m);
		vi dist(n, INF); dist[0] = 0;
		AdjList.assign(n, vii());
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &x, &y, &t);
			AdjList[x].push_back(ii(y, t));
		}
		for(int i=0; i<n-1; i++)
			for(int u=0; u<n; u++)
				for(int j=0; j<(int)AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
		bool hasNegativeCycle = false;
		for(int u=0; u<n; u++)
			for(int j=0; j<(int)AdjList[u].size(); j++) {
				ii v = AdjList[u][j];
				if(dist[v.first] > dist[u] + v.second)
					hasNegativeCycle = true;
			}
		printf(hasNegativeCycle?"possible\n":"not possible\n");
	}
	return 0;
}
