
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;

ll cnt[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,x,sum=0;
    cin>>n>>m;
    cnt[sum]++;
    rng(i,0,n-1){
        cin>>x;
        sum+=x;
        sum%=m;
        cnt[sum]++;
    }
    ll res=0;
    rng(i,0,m){
        res+=(cnt[i]*(cnt[i]-1))/2;
    }
    cout<<res<<'\n';
}

