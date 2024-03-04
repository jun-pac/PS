
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

string datas;
vc<int> edges[N];
int Pexp[N]; // S가 exposed
int Sexp[N]; // S가 expose되지않음... DP_non<=DP_exp+1

void DFS(int idx, int p){
    for(auto next : edges[idx]){
        if(next!=p) DFS(next,idx);
    }
    if(datas[idx]=='S'){
        ll res=0;
        for(auto next : edges[idx]){
            if(next==p) continue;
            if(datas[next]=='S') res+=Sexp[next];
            if(datas[next]=='P') res+=Pexp[next]+1;
            if(datas[next]=='C') res+=min(Sexp[next],Pexp[next]+1);
        }
        Sexp[idx]=res;
        Pexp[idx]=INF;
    }
    if(datas[idx]=='P'){
        ll res=0;
        for(auto next : edges[idx]){
            if(next==p) continue;
            if(datas[next]=='S') res+=Sexp[next]+1;
            if(datas[next]=='P') res+=Pexp[next];
            if(datas[next]=='C') res+=min(Sexp[next]+1,Pexp[next]);
        }
        Sexp[idx]=INF;
        Pexp[idx]=res;
    }
    if(datas[idx]=='C'){
        if(p!=-1 && edges[idx].size()==1){
            Pexp[idx]=0;
            Sexp[idx]=0;
        }
        else{
            // P를 모두 막고 Sexp가 되기
            ll res=0;
            for(auto next : edges[idx]){
                if(next==p) continue;
                if(datas[next]=='S') res+=Sexp[next];
                if(datas[next]=='P') res+=Pexp[next]+1;
                if(datas[next]=='C') res+=min(Sexp[next],Pexp[next]+1);
            }
            Sexp[idx]=res;
            
            // S를 모두 막고 Pexp가 되기
            res=0;
            for(auto next : edges[idx]){
                if(next==p) continue;
                if(datas[next]=='S') res+=Sexp[next]+1;
                if(datas[next]=='P') res+=Pexp[next];
                if(datas[next]=='C') res+=min(Sexp[next]+1,Pexp[next]);
            }
            Pexp[idx]=res;
        }
    }
    
    //cout<<"DP "<<idx+1<<' '<<datas[idx]<<' '<<Sexp[idx]<<' '<<Pexp[idx]<<'\n';
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,1,n-1){
        int a;
        cin>>a;
        a--;
        edges[a].pb(i);
        edges[i].pb(a);
    }
    cin>>datas;
    fill(Sexp,Sexp+n,INF);
    fill(Pexp,Pexp+n,INF);
    DFS(0,-1);
    cout<<min(Pexp[0],Sexp[0])<<'\n';
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

