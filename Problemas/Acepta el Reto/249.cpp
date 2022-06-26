#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
		int burro,sacos;
		cin>>burro>>sacos;
		vector<int> bu;
		for(int i=0;i<sacos;i++)
		{
			int num; cin>>num;
			bu.push_back(num);
		}
		sort(bu.begin(),bu.end());
		int res = 0;
		for(int i=0;i<sacos-1;i++)
		{
			//cout<<bu[i]<<" "<<bu[i+1]<<endl;
			if(bu[i]==bu[i+1]) {res++;  i++;}
		}
		cout<<min(res,burro)<<endl;
	}
	return 0;
}
