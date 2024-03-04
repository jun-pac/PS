
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 


int datas[N], DP[N], XOR[N];
set<pii> pos; // {XOR, idx}

void Solve(){
    int n;
    cin>>n;
    pos.clear();
    rng(i,0,n-1) cin>>datas[i];
    int temp=0;
    pos.insert({temp,-1});
    rng(i,0,n-1){
        temp=temp^datas[i];
        XOR[i]=temp;
        pos.insert({temp,i});
    }
    int res=0;
    DP[0]=(datas[0]==0?0:1);
    rng(i,1,n-1){
        if(datas[i]==0) DP[i]=DP[i-1];
        else{
            pii tar={XOR[i],i};
            auto it=pos.find(tar);
            if(it==pos.begin() || prev(it)->fi!=XOR[i]) DP[i]=DP[i-1]+1;
            else{
                int pred_idx=prev(it)->se;
                DP[i]=min(DP[i-1]+1,(pred_idx==-1?0:DP[pred_idx])+i-pred_idx-1);
            }
        }
    }
    cout<<DP[n-1]<<'\n';
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

