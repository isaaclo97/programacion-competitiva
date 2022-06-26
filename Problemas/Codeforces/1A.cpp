#include <iostream>
using namespace std;

int main() {
	long long int a,n,m;
	cin>>n>>m>>a;
	cout<< ((n+a-1)/a)*((m+a-1)/a) <<endl;
	return 0;
}
