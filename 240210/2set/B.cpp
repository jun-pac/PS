
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

string datas[101];
pii dirs[4];

void Solve(){
    int n,m,k;
    dirs[0]={-1,0};
    dirs[1]={0,1};
    dirs[2]={1,0};
    dirs[3]={0,-1};
    
    cin>>n>>m>>k;   
    rng(i,0,n-1){
        datas[i].resize(m,'.');
    }
    pii pos={0,0};
    int dir=0;
    rng(i,0,k-1){
        if(datas[pos.fi][pos.se]=='.'){
            // turn right
            datas[pos.fi][pos.se]='#';
            dir=(dir+1)%4;
            pos.fi=pos.fi+dirs[dir].fi;
            pos.se=pos.se+dirs[dir].se;
            pos.fi=(pos.fi+n)%n;
            pos.se=(pos.se+m)%m;
        }
        else{
            datas[pos.fi][pos.se]='.';
            dir=(dir+3)%4;
            pos.fi=pos.fi+dirs[dir].fi;
            pos.se=pos.se+dirs[dir].se;
            pos.fi=(pos.fi+n)%n;
            pos.se=(pos.se+m)%m;
        }
    }
    rng(i,0,n-1){
        cout<<datas[i]<<'\n';
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

