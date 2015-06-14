#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int t, N, M, T, E, u, v, w, count;
	vector<vii> AdjList;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &N, &E, &T, &M);
		AdjList.assign(N, vii());
		for(int i=0; i<M; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u-1].push_back(ii(v-1, w));
		}
		vi dist(N, INF); dist[E-1] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, E-1));
		while(!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int j=0; j<(int)AdjList[u].size(); j++) {
				ii v = AdjList[u][j];
				if(dist[u] + v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		count = 0;
		for(int i=0; i<N; i++) {
			if(dist[i]<=T) count++;
		}
		printf("%d\n\n", count);
	}
	return 0;
}
