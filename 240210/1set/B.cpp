
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
ll usum[N];
ll dsum[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,1,n-1){
        usum[i]=(i==0?0:usum[i-1])+(datas[i]>datas[i-1]?datas[i]-datas[i-1]:0);
        dsum[i]=(i==0?0:dsum[i-1])+(datas[i]<datas[i-1]?datas[i-1]-datas[i]:0);
    }
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(a<b){
            // down a+1 ... b
            cout<<dsum[b]-dsum[a]<<'\n';
        }
        else{
            // up b+1 ... a
            cout<<usum[a]-usum[b]<<'\n';
        }
    }
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

