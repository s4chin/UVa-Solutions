#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 1e6+7

vector<int> graph[105];
int C[105][105];
int F[105][105];
int P[105];
int M[105];

int BFS(int s, int t) {
	memset(P, -1, sizeof P);
	memset(M, 0, sizeof M);
	queue<int> Q;
	Q.push(s);
	P[s] = -2;
	M[s] =INF;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i=0; i<graph[u].size(); i++) {
			int to = graph[u][i];
			if(P[to] == -1) {
				if(C[u][to] - F[u][to] > 0) {
					P[to] = u;
					M[to] = min(M[u], C[u][to] - F[u][to]);
					if(to == t) {
						return M[t];
					}
					Q.push(to);
				}
			}
		}
	}
	return 0;
}

int edmondsKarp(int s, int t) {
	int maxFlow = 0;
	while(true) {
		int flow = BFS(s, t);
		if(flow == 0) break;
		maxFlow += flow;
		int v = t;
		while(v!=s) {
			int u = P[v];
			F[u][v] += flow;
			F[v][u] -= flow;
			v = u;
		}
	}
	return maxFlow;
}

int main() {
	int n, s, t, c, u, v, f, count = 1;
	while(true) {
		scanf("%d", &n);
		if(n==0)break;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				C[i][j] = 0;
				F[i][j] = 0;
			}
		for(int i=0; i<n; i++) {
			graph[i].clear();
		}
		scanf("%d%d%d", &s, &t, &c);
		for(int i=0; i<c; i++) {
			scanf("%d%d%d", &u, &v, &f);
			C[u-1][v-1] += f;
			C[v-1][u-1] += f;
			graph[u-1].push_back(v-1);
			graph[v-1].push_back(u-1);
		}
		int maxFlow = edmondsKarp(s-1, t-1);
		printf("Network %d\nThe bandwidth is %d.\n\n", count++,  maxFlow);
	}
	return 0;
}
