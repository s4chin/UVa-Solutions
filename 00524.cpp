#include <iostream>
#include <cstdio>
using namespace std;

int bar[]={3,5,7,11,13,17,19,23,29,31,37};
int a[20], n, count = 1, boom;

bool isPrime(int num) {
	for(int i=0; i<11; i++) {
		if(num == bar[i]) return true;
	}
	return false;
}

bool allowed(int index, int num) {
	for(int i=0; i<index; i++) {
		if(num == a[i]) return false;
	}
	return isPrime(num+a[index-1]);
}

void foo(int index) {
	if(index == n) {
		if(isPrime(a[index-1]+1)) {
			if(boom>1) printf("\n");
			for(int i=0; i<n; i++) printf("%d ", a[i]);
			boom++;
		}
	}
	else {
		for(int i=2; i<=n; i++) {
			if(allowed(index, i)) {
				a[index] = i;
				foo(index+1);
			}
		}
	}
}

int main() {
	//freopen("output.txt", "w", stdout);
	while(cin>>n) {
		boom = 1;
		if(count>1) printf("\n\n");
		printf("Case %d:\n", count++);
		if(n == 1) {
			printf("1");
			continue;
		}
		a[0] = 1;
		foo(1);
	}
	return 0;
}
