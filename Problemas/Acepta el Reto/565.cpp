#include <bits/stdc++.h>
using namespace std;

struct clapsPQ{
    int seconds,minpeople;
    bool operator<(const clapsPQ &other)const{
        if(minpeople == other.minpeople)
            return seconds<other.seconds;
        return minpeople < other.minpeople;
    }
};

void updatePQ(priority_queue<clapsPQ> &pq, queue<clapsPQ> &q) {
    while (!q.empty()){
        pq.push(q.front());
        q.pop();
    }
}

//inline int getchar_unlocked() { return getchar(); }
inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main(){
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\565_2.in","r",stdin);
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\565_isaac.out","w",stdout);
    int people;
    fastInput(people);
    while(people!=0){
        priority_queue<clapsPQ> pq;
        int oneperson=0;
        for(int i=0; i<people;i++) {
            int seconds, minpeople;
            fastInput(seconds);
            fastInput(minpeople);
            if(minpeople==1)
                oneperson = max(oneperson,seconds);
            else
                pq.push({seconds,minpeople});
        }
        queue<clapsPQ> q;
        int minValue = oneperson;
        int maxValue = oneperson;
        while(!pq.empty()){
            //Quedarse con solo los que puedan mejorar el tiempo
            while (!pq.empty()){
                clapsPQ actual=pq.top();
                pq.pop();
                if(actual.seconds>minValue)
                    q.push(actual);
            }
            updatePQ(pq, q);
            //Coger el mejor tiempo
            if(!pq.empty())
                minValue=pq.top().seconds;
            bool flag = true;
            int size = pq.size();
            for (int i = 0; i <size; i++) {
                clapsPQ actual=pq.top();
                minValue=min(actual.seconds,minValue);
                int aplauden = pq.size()+q.size();
                if(actual.minpeople<=aplauden){
                    if(flag)
                        maxValue=actual.seconds;
                    q.push(actual);
                    maxValue=min(actual.seconds,maxValue);
                    flag = false;
                }
                //Eliminamos todos os que no podrán aplaudir
                pq.pop();
            }
            updatePQ(pq, q);
            oneperson=max(oneperson,maxValue);
        }
        printf("%d\n",oneperson);
        fastInput(people);
    }
    return 0;
}