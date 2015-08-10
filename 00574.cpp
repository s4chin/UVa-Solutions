#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> A(0);
bool used[20];
vector<vector<int> > finlist;
map< vector<int>, bool > mp;

int btrack(int t, int sum, vector<int> temp, int pos) {
	if(sum == t) {
		if(!mp[temp]) {
			mp[temp] = true;
			finlist.push_back(temp);
		}
		return 0;
	}
	for(pos; pos < A.size(); pos++) {
		if(!used[pos]) {
			if(A[pos] <= (t-sum)) {
				temp.push_back(A[pos]);
				sum += A[pos];
				used[pos] = true;
				btrack(t, sum, temp, pos);
				sum -= A[pos];
				temp.pop_back();
				used[pos] = false;
			}
		}
	}
	return 0;
}


int main() {
	// your code goes here
	int t(0), n(0), j, x, i;
	while(1) {
		cin>>t;
		cin>>n;
		if(n == 0) break;
		printf("Sums of %d:\n",t);
		A.clear();
        for (i=0 ; i<n ; i++) {
            scanf("%d",&x);
            A.push_back(x);
            used[i] = false;
        }
        finlist.clear();
        vector<int> temp;
        temp.clear();
        mp.clear();
        btrack(t, 0, temp, 0);

        if (!finlist.size()) {
            printf("NONE\n");
        }
        for (i=0 ; i<finlist.size() ; i++) {
            for (j=0 ; j<finlist[i].size() ; j++) {
                if (!j) printf("%d",finlist[i][j]);
                else printf("+%d",finlist[i][j]);
            }
            printf("\n");
        }
	}
	return 0;
}