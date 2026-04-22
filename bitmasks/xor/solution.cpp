/**
 *    @author tapan
 *    @copyright 2026 tapan. all rights reserved.
 **/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod=998244353;

int cnt(int n,int r){
    return n/4+(n%4>=r?1:0);
}

int range(int a,int b,int r){
    return cnt(b,r)-(a>0?cnt(a-1,r):0);
}

bool checker(int n,int x){
    int c=0,l,r;
    for(l=1;l<=x;l++){
        int xr=0;
        for(r=l;r<=n;r++){
            xr^=r;
            if(r>=x && xr==0){
                c++;
            }
        }
    }
    int ans=find(n,x);
    return (c==ans);
}

int find(int n,int x){
    int cntl=range(0,x-1,3)+1;
    int cntr=range(x,n,3);

    int cntll=range(0,x-1,1);
    int cntrr=range(x,n,1);

    int ans=0;
    ans += (cntl%mod)*(cntr%mod)%mod;
    ans %= mod;
    ans += (cntll%mod)*(cntrr%mod)%mod;
    ans %= mod;
    return ans;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int i,n,x;
        cin>>n>>x;
        int result=find(n,x);
        cout<<result<<endl;
        //test
        // for(i=1; i<=1000; i++){
        //     if(!checker(i,i/2)){
        //         cout<<"WRONG "<<i<<endl;
        //     }
        // }
    }				
    return 0;  
}