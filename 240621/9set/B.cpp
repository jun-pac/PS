
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

ll datas[32];

void Solve(){
    ll n;
    cin>>n;
    bool flag=0;
    int idx=0, l11=-1;
    gnr(i,31,0){
        datas[i]=(((1<<i)&n)?1:0);
    }
    gnr(i,30,0){
        if(datas[i]==1){
            if(!flag) idx=i;
            flag=1;
        }
        if(datas[i]==0 && (i!=0&&datas[i-1]==0)){
            if(l11!=-1){
                datas[idx+1]=1;
                rng(j,l11,idx){
                    if(datas[j]==0) datas[j]=-1;
                    else datas[j]=0;
                }
                datas[l11]=-1;
            }
            flag=0;
            l11=-1;
        }
        if(datas[i]==1 && (i!=0 && datas[i-1]==1)){
            l11=i-1;
        }
    }
    if(l11!=-1){
        datas[idx+1]=1;
        rng(j,l11,idx){
            if(datas[j]==0) datas[j]=-1;
            else datas[j]=0;
        }
        datas[l11]=-1;
    }
    cout<<32<<'\n';
    rng(i,0,31) cout<<datas[i]<<' ';
    cout<<'\n';
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

