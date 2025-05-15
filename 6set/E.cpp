
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

array<ll,3> datas[10];
int n;
long double DP[5050][256]; // 남은 돈, 성공한 것
bool visited[5050][256];

long double get_DP(int x, int state){
    if(visited[x][state]) return DP[x][state];
    visited[x][state]=1;
    long double res=0;
    rng(i,0,n-1){
        if(!(state&(1<<i)) && datas[i][1]<=x){
            long double prob=(long double)datas[i][2]/100;
            int cost=datas[i][1];
            long double score=datas[i][0];
            res=max(res,get_DP(x-cost,state)*(1-prob)+(get_DP(x-cost,state+(1<<i))+score)*prob);
        }
    }
    return DP[x][state]=res;
}

void Solve(){
    int x;
    cin>>n>>x;
    rng(i,0,n-1){
        rng(j,0,2) cin>>datas[i][j]; // score, cost, Prob.
    }

    cout<<fixed;
    cout.precision(15);
    cout<<get_DP(x,0)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

