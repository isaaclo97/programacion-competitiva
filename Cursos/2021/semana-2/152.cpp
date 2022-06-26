#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF && n != 0){
		map<int, int> m;
		
		for(int i=0; i<n; i++) {
			int ni; scanf("%d", &ni);
			if(m.count(ni) == 0){
				m[ni] = 1;
			} else{
				m[ni]++;
			}
		}
		
		int best_value = 0;
		int best_key;
		
		for(auto mi : m){
			int key = mi.first;
			int value = mi.second;
			if (value > best_value) {
				best_value = value;
				best_key = key;
			}
		}
		
		printf("%d\n", best_key);
		
	}
	return 0;
}
