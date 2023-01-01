#include <bits/stdc++.h>
using namespace std;

struct cosa{
    long long int start;
    long long int end;
    long long int repetition;
    bool operator<(const cosa &other)const{
        if(start==other.start) return end>other.end;
        return start > other.start;
    }
};

int main(){
    long long int normal,repetida,tiempo;
    while(scanf("%lld %lld %lld",&normal,&repetida,&tiempo)==3){
        priority_queue<cosa> pq; tiempo--;
        long long int start,end,repetition;
        while(normal--){
            scanf("%lld %lld",&start,&end); pq.push(cosa{start,min(tiempo,end-1),-1});
        }
        while(repetida--){
            scanf("%lld %lld %lld",&start,&end,&repetition); pq.push(cosa{start,min(tiempo,end-1),repetition});
        }
        bool flag = false;
        long long int curEnd = -1;
        while(pq.size()!=0){
            cosa cur = pq.top(); pq.pop();
            //cout<<cur.start<<" "<<cur.end<<endl;
            if(curEnd>=cur.start) { //posible WA
                flag=true;
                break;
            }
            curEnd = cur.end; //posible WA
            if(cur.repetition!=-1){
                if(pq.size()!=0 && (cur.start+cur.repetition)<=tiempo)
                    pq.push(cosa{cur.start+cur.repetition,min(tiempo,cur.end+cur.repetition),cur.repetition}); //posible wa si excediendo se repite
            }
        }
        if(flag) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}