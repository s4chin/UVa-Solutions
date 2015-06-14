#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define INF -1

vector<vector<int> > AdjList;
vector<bool> visited;
vector<int> color;

int main() {
	int n, l, u, v;
	while(true) {
		scanf("%d", &n);
		if(n==0) break;
		scanf("%d", &l);
		AdjList.assign(n, vector<int> ());
		color.assign(n, INF);
		visited.assign(n, false);
		queue<int> Q;
		for(int i=0; i<l; i++) {
			scanf("%d%d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		bool isBipartite = true;
		int s = 0;
		color[s] = 0;
		Q.push(s);
		while(!Q.empty() && isBipartite) {
			int k = Q.front();
			Q.pop();
			for(int i=0; i<(int)AdjList[k].size(); i++) {
				if(color[AdjList[k][i]] == INF) {
					color[AdjList[k][i]] = 1-color[k];
					Q.push(AdjList[k][i]);
				}
				else if(color[AdjList[k][i]] == color[k]) {
					isBipartite = false;
					break;
				}
			}
		}
		printf(isBipartite?"BICOLORABLE.\n":"NOT BICOLORABLE.\n");
	}
	return 0;
}
