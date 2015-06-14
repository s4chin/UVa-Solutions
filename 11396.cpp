#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define INF -1

vector<vector<int> > AdjList;

int main() {
	int n, u, v;
	while(true) {
		scanf("%d", &n);
		if(n==0)break;
		AdjList.assign(n, vector<int> ());
		while(true) {
			scanf("%d%d", &u, &v);
			if(u==0 && v==0)break;
			AdjList[u-1].push_back(v-1);
			AdjList[v-1].push_back(u-1);
		}
		vector<int> color(n, INF);
		queue<int> q;
		q.push(0);
		color[0] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite) {
			int k = q.front();
			q.pop();
			for(int i=0; i<(int)AdjList[k].size(); i++) {
				if(color[AdjList[k][i]] == INF) {
					color[AdjList[k][i]] = 1 - color[k];
					q.push(AdjList[k][i]);
				}
				else if(color[AdjList[k][i]] == color[k]) {
					isBipartite = false;
					break;
				}
			}
		}
		printf(isBipartite?"YES\n":"NO\n");
	}
	return 0;
}
