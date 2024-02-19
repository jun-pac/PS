
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

int datas[N];
ll rcost[N], lcost[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        if(i==0 || (datas[i]-datas[i-1]>=datas[i+1]-datas[i])){
            rcost[i]=(i==0?0:rcost[i-1])+1;
        }
        else rcost[i]=(i==0?0:rcost[i-1])+datas[i+1]-datas[i];
    }
    gnr(i,n-1,1){
        if(i==n-1 || (datas[i]-datas[i-1]<=datas[i+1]-datas[i])){
            lcost[i]=(i==n-1?0:lcost[i+1])+1;
        }
        else{
            lcost[i]=(i==0?0:lcost[i+1])+datas[i]-datas[i-1];
        }
    }
    int m;
    cin>>m;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(a<b){
            cout<<rcost[b-1]-(a==0?0:rcost[a-1])<<'\n';
        }
        else{
            swap(a,b);
            cout<<lcost[a+1]-(b==n-1?0:lcost[b+1])<<'\n';
        }
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

