
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[501][501];
bool visited[501][501];
pii dir[4];

void Solve(){
    ll h,w,x;
    cin>>h>>w>>x;
    ll p,q;
    cin>>p>>q;
    p--,q--;
    rng(i,0,h-1){
        rng(j,0,w-1) cin>>datas[i][j];
    }
    ll cur=datas[p][q];
    
    priority_queue<pair<ll,pii>> pq;
    visited[p][q]=1;
    rng(k,0,3){
        int ni=p+dir[k].fi;
        int nj=q+dir[k].se;
        if(!visited[ni][nj] && 0<=ni && ni<h && 0<=nj && nj<w){
            visited[ni][nj]=1;
            pq.push({-datas[ni][nj],{ni,nj}});
        }
    }
    while(!pq.empty()){
        auto temp=pq.top();
        p=temp.se.fi;
        q=temp.se.se;
        ll val=-temp.fi;
        pq.pop();
        if(val<=cur/x && !(cur%x==0 && val==cur/x)){
            cur+=val;
            rng(k,0,3){
                int ni=p+dir[k].fi;
                int nj=q+dir[k].se;
                if(!visited[ni][nj] && 0<=ni && ni<h && 0<=nj && nj<w){
                    visited[ni][nj]=1;
                    pq.push({-datas[ni][nj],{ni,nj}});
                }
            }
        }
    }
    cout<<cur<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    dir[0]={0,1};
    dir[1]={1,0};
    dir[2]={0,-1};
    dir[3]={-1,0};
    while(t--){
        Solve();
    }
    return 0;
}

