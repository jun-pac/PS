
#include <bits/stdc++.h>
using namespace std;
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
typedef long long ll;
#define N 1000030

ll d1[N], d2[N];
string datas;

void Solve(){
    int n;
    cin>>n;
    for(int i=0; i<=n-1; i++) cin>>d1[i];
    cin>>datas;
    for(int i=0; i<=n-1; i++) cin>>d2[i];
    ll res=d1[n-1]+1;
    for(int i=n-2; i>=0; i--){
        if(datas[i]=='*') res=cediv(res,d2[i]);
        else res-=d2[i];
        res=max(res,1LL);
        res+=d1[i];   
    }
    cout<<res<<'\n';
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

