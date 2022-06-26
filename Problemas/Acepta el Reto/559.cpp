
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\inPared.txt","r",stdin);
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\outPared.txt","w",stdout);
    long long int rodillo, veces,x,y;
    while(scanf("%lld",&rodillo)==1 && rodillo!=0){
        scanf("%lld",&veces);
        vector<pair<long long int,long long int>> V;
        for(int i=0; i<veces;i++){
            scanf("%lld %lld",&x,&y);
            V.push_back({ x, -y});
            V.push_back(make_pair(x+rodillo, y));
        }
        sort(V.begin(),V.end());
        vector<pair<long long int,long long int> > skyline;
        multiset<long long int> leftWallHeight = { 0 };
        int top = 0;
        for (auto w : V) {
            //cout<<w.first<<" "<<w.second<<" "<<endl;
            if (w.second < 0)
                leftWallHeight.insert(-w.second);
            else
                leftWallHeight.erase(leftWallHeight.find(w.second));
            if (*leftWallHeight.rbegin() != top) {
                top = *leftWallHeight.rbegin();
                skyline.push_back(make_pair(w.first, top));
            }
        }
        long long int res = 0;
        int lastX = skyline[0].first, lastY= skyline[0].second;
        for (int i=1; i<skyline.size();i++) {
            res+=abs(skyline[i].first-lastX)*lastY;
            lastX = skyline[i].first;
            lastY = skyline[i].second;
        }
        printf("%lld\n",res);
    }
    return 0;
}
