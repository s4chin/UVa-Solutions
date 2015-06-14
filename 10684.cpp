#include <cstdio>
#include <iostream>
using namespace std;

int a[10005];

int main() {
	int n, ans, sum;
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		ans = 0; sum = 0;
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		for(int i=0; i<n; i++) {
			sum+=a[i];
			ans = max(ans, sum);
			if(sum<0) sum = 0;
		}
		if(ans>0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}
