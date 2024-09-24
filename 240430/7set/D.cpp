
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int datas[N];
int gi[31][N];
int sum[31][N];
int igi[31][N];
int isum[31][N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(k,0,30){
        rng(i,0,n-1) gi[k][i]=((i==0?0:gi[k][i-1])+((datas[i]&(1<<k))!=0))%2;
    }
    rng(k,0,30){
        rng(i,0,n-1) sum[k][i]=((i==0?0:sum[k][i-1])+gi[k][i]);
    }
    rng(k,0,30){
        gnr(i,n-1,0) igi[k][i]=((i==n-1?0:igi[k][i+1])+((datas[i]&(1<<k))!=0))%2;
    }
    rng(k,0,30){
        gnr(i,n-1,0) isum[k][i]=((i==n-1?0:isum[k][i+1])+igi[k][i]);
    }
    ll res=0;
    rng(i,0,n-1){
        ll le,lo,re,ro;
        int idx=0;
        ll temp=datas[i];
        while(temp/2>0){
            idx++;
            temp/=2;
        }
        assert((1<<idx)&datas[i]);
        //cout<<"idx : "<<idx<<'\n';
        if(gi[idx][i]==0){
            ro=sum[idx][n-1]-sum[idx][i];
            re=n-1-i-ro;
        }
        else{
            re=sum[idx][n-1]-sum[idx][i];
            ro=n-1-i-re;
        }
        if(igi[idx][i]==0){
            lo=isum[idx][0]-isum[idx][i];
            le=i-lo;
        }
        else{
            le=isum[idx][0]-isum[idx][i];
            lo=i-le;
        }

        //cout<<le<<' '<<lo<<' '<<re<<' '<<ro<<'\n';
        res=(res+ro+lo+lo*re+le*ro);
    }
    cout<<res<<'\n';
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

