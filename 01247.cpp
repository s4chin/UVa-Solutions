#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define INF 1e9

map<string, int> pplIdx;
int par[30][30];

void printPath(int i, int j) {
	string key;
	if(i!=j) {
		printPath(i, par[i][j]);
		cout<<" ";
	}
	map<string, int>::const_iterator it;	
	for (it = pplIdx.begin(); it != pplIdx.end(); ++it)
	{
		if (it->second == j)
		{
			key = it->first;
			break;
		}
	}
	cout<<key;
}

int main() {
	int s, p, t, d, idx = 0;
	int fw[30][30];
	char n1[10], n2[10];
	string n1s, n2s;
	for(int i=0; i<30; i++) {
		for(int j=0; j<30; j++) {
			if(i==j) fw[i][j] = 0;
			else fw[i][j] = INF;
		}
	}
	scanf("%d%d", &s, &p);
	while(p--) {
		scanf("%s", n1);
		scanf("%s", n2);
		scanf("%d" ,&d);
		n1s = string(n1);
		n2s = string(n2);
		if(pplIdx.count(n1s) == 0)
			pplIdx[n1s] = idx++;
		if(pplIdx.count(n2s) == 0)
			pplIdx[n2s] = idx++;
		fw[pplIdx[n1s]][pplIdx[n2s]] = d;
		fw[pplIdx[n2s]][pplIdx[n1s]] = d;
	}
	for(int i=0; i<30; i++)
		for(int j=0; j<30; j++)
			par[i][j] = i;
	for(int k=0; k<s; k++)
		for(int i=0; i<s; i++)
			for(int j=0; j<s; j++)
				if(fw[i][j]>fw[i][k] + fw[k][j]) {
					fw[i][j] = fw[i][k] + fw[k][j];
					par[i][j] = par[k][j];
				}
	scanf("%d", &t);
	while(t--) {
		scanf("%s", n1);
		scanf("%s", n2);
		n1s = string(n1);
		n2s = string(n2);
		printPath(pplIdx[n1s], pplIdx[n2s]);
		printf("\n");
	}
	return 0;
}
