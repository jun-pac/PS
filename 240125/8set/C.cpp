
#include <bits/stdc++.h>
using namespace std;
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

ll datas[N];
ll oddmx[N];
ll evenmx[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    ll mx=datas[0];
    rng(i,0,n-1) mx=max(mx,datas[i]);
    if(mx<=0){
        cout<<mx<<'\n';
        return;
    }
    mx=0;
    rng(i,0,n-1){
        if(i%2==0){
            evenmx[i]=(i==0?0:evenmx[i-2])+max(0LL,datas[i]);
            mx=max(mx,evenmx[i]);
        }
        if(i%2==1){
            oddmx[i]=(i==1?0:oddmx[i-2])+max(0LL,datas[i]);
            mx=max(mx,oddmx[i]);
        }
    }
    // 결국 가장 큰 원소를 만들면 되는건데..
    ll res=0;
    cout<<mx<<'\n';

    
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

