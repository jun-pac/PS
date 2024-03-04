
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

string datas[100];
string ori;
string res[100];

void get_res(int n, int idx, int off){
    if(n==1) res[off][off]=ori[idx];
    else{
        assert(n*n==ori.size()-idx);
        rng(i,0,n-1) res[off+0][off+i]=ori[idx++];
        rng(i,0,n-2) res[off+i+1][off+n-1]=ori[idx++];
        rng(i,0,n-2) res[off+n-1][off+n-2-i]=ori[idx++];
        rng(i,0,n-3) res[off+n-2-i][off+0]=ori[idx++];
        if(n!=2) get_res(n-2,idx,off+1);
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    //ori.resize(n*n);
    rng(i,0,2*n-2){
        if(i%2==0) rng(j,max(0,i-n+1),min(n-1,i)) ori.pb(datas[i-j][j]);
        else gnr(j,min(n-1,i),max(0,i-n+1)) ori.pb(datas[i-j][j]);
    }
    rng(i,0,n-1) res[i].resize(n);
    get_res(n,0,0);
    //cout<<ori.size()<<'\n';
    //cout<<ori<<'\n';
    rng(i,0,n-1) cout<<res[i]<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

