#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;

int a[15], s, d, last_5, year;

bool foo(int month) {
	if(month>=5) {
		last_5 = accumulate(a+month-5, a+month, 0);
		if(last_5>0) return false;
	}
	if(month == 12) {
		year = accumulate(a, a+12, 0);
		if(year<=0) {
			printf("Deficit\n");
		}
		else {
			printf("%d\n", year);
		}
		return true;
	}
	a[month] = s;
	if(!foo(month+1)) {
		a[month] = -d;
		return foo(month+1);
	}
	return true;
}

int main() {
	while(cin>>s) {
		cin>>d;
		foo(0);
	}
	return 0;
}
