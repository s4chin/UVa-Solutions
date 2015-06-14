#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

char ins[50000];
char map[105][105];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int n, m, s, starti, startj, row, col, count;
	while(true) {
		count = 0;
		scanf("%d%d%d", &n, &m, &s);
		if(n == 0 && m == 0 && s == 0)
			break;
		for(int i=0; i<n; i++)
			scanf("%s", map[i]);
		scanf("%s", ins);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(map[i][j] == 'N' || map[i][j] == 'S' || 
				map[i][j] == 'L' || map[i][j] == 'O') {
					starti = i;
					startj = j;
					break;
				}
		if(map[starti][startj] == 'N') {
			row = -1; col = 0;
		}
		if(map[starti][startj] == 'S') {
			row = 1; col = 0;
		}
		if(map[starti][startj] == 'L') {
			row = 0; col = 1;
		}
		if(map[starti][startj] == 'O') {
			row = 0; col = -1;
		}
		for(int i=0; i<s; i++)
		{
			if(ins[i] == 'F') {
				if((starti + row) >=0 && (starti + row) <n && (startj + col) >=0
				 && (startj + col) <m && map[starti+row][startj+col]!='#') {
					starti = starti+row;
					startj = startj+col;
					if(map[starti][startj]=='*') {
						count++;
						map[starti][startj] = '.';
					}
				}
			}
			else if(ins[i] == 'D') {
				if(row == -1 && col == 0) {
					row = 0; col = 1;
				}
				else if(row == 1 && col == 0) {
					row = 0; col = -1;
				}
				else if(row == 0 && col == 1) {
					row = 1; col = 0;
				}
				else if(row == 0 && col == -1) {
					row = -1; col = 0;
				}
			}
			else if(ins[i] == 'E') {
				if(row == -1 && col == 0) {
					row = 0; col = -1;
				}
				else if(row == 1 && col == 0) {
					row = 0; col = 1;
				}
				else if(row == 0 && col == 1) {
					row = -1; col = 0;
				}
				else if(row == 0 && col == -1) {
					row = 1; col = 0;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
