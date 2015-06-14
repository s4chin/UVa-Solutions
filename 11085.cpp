#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int count, row[8], mat[100][8], num = 1, bar[8];

bool place(int r, int c) {
	for(int prev = 0; prev < c; prev++)
		if(r == row[prev] || abs(row[prev]-r) == abs(prev-c))
			return false;
	return true;
}

void backtrack(int c) {
	if(c==8) {
		for(int i=0; i<8; i++)
			mat[count][i] = row[i]+1;
		count++;
	}
	for(int r=0; r<8; r++)
		if(place(r, c)) {
			row[c] = r;
			backtrack(c+1);
		}
}

int main() {
	memset(mat, 0, sizeof mat);
	memset(row, 0, sizeof row);
	backtrack(0);
	while(cin>>bar[0]) {
		int sol = 1000000;
		for(int i=1; i<=7; i++) scanf("%d", bar+i);
		for(int i=0; i<count; i++) {
			int ans = 0;
			for(int j=0; j<8; j++) {
				ans += mat[i][j]==bar[j]?0:1;
			}
			sol = min(sol, ans);
		}
		printf("Case %d: %d\n", num++, sol);
	}
	return 0;
}
