
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll gcd(ll x, ll y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

ll datas[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    
    if(datas[0]==datas[n-1]){
        cout<<0<<'\n';
        return;
    }
    ll gd=datas[1]-datas[0];
    rng(i,0,n-2){
        gd=gcd(gd,datas[i+1]-datas[i]);
    }

    if(k<datas[0]){
        gd=gcd(gd,datas[0]-k);
        ll res=0;
        rng(i,0,n-1){
            res+=(datas[i]-k)/gd-1;
        }
        cout<<res<<'\n';
    }
    else if(k>datas[n-1]){
        gd=gcd(gd,k-datas[n-1]);
        ll res=0;
        rng(i,0,n-1){
            res+=(k-datas[i])/gd-1;
        }
        cout<<res<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

