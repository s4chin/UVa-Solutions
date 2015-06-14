#include <iostream>
#include <cstdio>
#include <algoithm>
using namespace std;

double fw[21][21];

int main() {
	int n;
	while(cin>>n) {
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i == j) {
					fw[i][j] = 1.0;
				}
				else {
					scanf("%lf", &rate);
					fw[i][j] = rate;
				}
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					fw[i][j] = max(fw[i][j], fw[i][k]*fw[k][j]);
		
	}
}
