
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

bool colocc[N], rowocc[N];
map<ll,ll> cnts;
array<int,3> qs[N];

void Solve(){
    ll h,w,m;
    cin>>h>>w>>m;
    rng(i,0,m-1){
        cin>>qs[i][0]>>qs[i][1]>>qs[i][2];
    }
    int rowcnt=0, colcnt=0;
    ll nnz=0;
    gnr(i,m-1,0){
        ll t=qs[i][0],pos=qs[i][1]-1,color=qs[i][2];
        if(t==1){
            if(rowocc[pos]==0){
                rowcnt++;
                rowocc[pos]=1;
                if(w-colcnt!=0) cnts[color]+=w-colcnt;
                if(color!=0) nnz+=w-colcnt;
            }
        }
        else{
            if(colocc[pos]==0){
                colcnt++;
                colocc[pos]=1;
                if(h-rowcnt) cnts[color]+=h-rowcnt;
                if(color!=0) nnz+=h-rowcnt;
            }
        }
    }
    if(nnz!=h*w) cnts[0]=h*w-nnz;
    cout<<cnts.size()<<'\n';
    for(auto [k,v]:cnts){
        cout<<k<<' '<<v<<'\n';
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

