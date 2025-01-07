// 7z x name.zip
// ./A < name.txt > output

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll powt[19];

ll numd(ll num){
    ll cnt=0;
    while(num!=0){
        cnt++;
        num/=10;
    }
    return cnt;
}

ll count_num(ll a, ll b, ll m){
    ll res=0;
    ll bitnum=numd(a);
    if(bitnum%2==0) return 0;
    rng(i,1,9-bitnum/2){
        ll val=(i+bitnum/2)*powt[bitnum/2];
        rng(j,1,bitnum/2){
            val+=(i+bitnum/2-j)*(powt[bitnum/2-j]+powt[bitnum/2+j]);
        }
        //cout<<"abm "<<a<<' '<<b<<' '<<m<<' '<<val<<'\n';
        if(a<=val && val<=b && val%m==0) res++;
    }
    return res;
}

void Solve(int tt){
    rng(i,0,18) powt[i]=(i==0?1:powt[i-1]*10);
    ll a,b,m;
    cin>>a>>b>>m;
    //cout<<a<<' '<<b<<' '<<m<<'\n';
    ll res=0;
    if(a==0){
        a++;
        b=max(b,1LL);   
    }
    while(numd(a)!=numd(b)){
        //cout<<"ab "<<a<<' '<<powt[numd(a)]-1<<' '<<b<<' '<<numd(a)<<' '<<numd(b)<<'\n';
        res+=count_num(a,powt[numd(a)]-1,m);
        a=powt[numd(a)];
    }
    res+=count_num(a,b,m);
    
    cout<<"Case #"<<tt<<": "<<res<<'\n';   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

