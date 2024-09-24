
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

int a[2][1000];
int pri[2][1000];
int ans[2][1000];


void Solve(int tt){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>a[0][i];
    rng(i,0,m-1) cin>>a[1][i];
    gnr(i,n-1,0){
        if(a[0][i]==0) pri[0][i]=(i==n-1?n+m:pri[0][i+1]-1);
        else pri[0][i]=a[0][i];
    }
    gnr(i,m-1,0){
        if(a[1][i]==0) pri[1][i]=(i==m-1?n+m:pri[1][i+1]-1);
        else pri[1][i]=a[1][i];
    }
    // rng(i,0,n-1) cout<<pri[0][i]<<' ';
    // cout<<'\n';
    // rng(i,0,m-1) cout<<pri[1][i]<<' ';
    // cout<<'\n'; 
    int cur=1;
    int aidx=0, bidx=0;
    while(aidx<n && bidx<m){
        if(a[0][aidx]==cur){
            cur++;
            aidx++;
        }
        else if(a[1][bidx]==cur){
            cur++;
            bidx++;
        }
        else{
            if(a[0][aidx]!=0){
                a[1][bidx]=cur;
                cur++;
                bidx++;
            }
            else if(a[1][bidx]!=0){
                a[0][aidx]=cur;
                cur++;
                aidx++;
            }
            else if(pri[0][aidx]<pri[1][bidx]){
                //cout<<"hello "<<aidx<<' '<<bidx<<' '<<cur<<'\n';
                a[0][aidx]=cur;
                cur++;
                aidx++;
            }
            else{
                a[1][bidx]=cur;
                cur++;
                bidx++;
            }
        }
    }
    while(aidx<n){
        if(a[0][aidx]==cur){
            cur++;
            aidx++;
        }
        else{
            a[0][aidx]=cur;
            cur++;
            aidx++;
        }
    }
    while(bidx<m){
        if(a[1][bidx]==cur){
            cur++;
            bidx++;
        }
        else{
            a[1][bidx]=cur;
            cur++;
            bidx++;
        }
    }
    rng(i,0,n-1) cout<<a[0][i]<<' ';
    cout<<'\n';
    rng(i,0,m-1){
        cout<<a[1][i]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

