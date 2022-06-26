/*
//C++ WITHOUD BIGINTEGER
#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int arr[105];
    while(scanf("%d",&arr[0])==1)
    {
        int n=0,k=0;
        long long int mxV=-INF;
        while(scanf("%d",&n)==1 && n!=-999999) { k++; arr[k]=n; }
        if(k==0) printf("%d\n",arr[k]);
        else
        {
            k++;
            for(int i=0;i<k;i++)
            {
                long long int sum=1;
                for(int j=i;j<k;j++)
                {
                    sum=sum*arr[j];
                    if(mxV<sum)mxV=sum;
                }
            }
            printf("%lld\n",mxV);
        }
    }
    return 0;
}
*/
import java.math.*;
import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        BigInteger [] a = new BigInteger [107];
        while (ob.hasNext()) {
            int n = 0 ;
            while(true){
                int x = ob.nextInt();
                if( x == -999999)break;
                a[ n++ ] = BigInteger.valueOf(x);
            }
            BigInteger Ans = BigInteger.valueOf(-999999);
            for( int i = 0 ; i < n ; i++){
                BigInteger ret = a[i];
                Ans = Ans.max(ret);
                for( int j = i + 1 ; j < n ; j++ ){
                    ret = ret.multiply(a[j]);
                    Ans = Ans.max(ret);
                }
            }
            System.out.println(Ans);
            
        }
    }
    
}
