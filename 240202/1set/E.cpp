
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 

int datas[N]; 

int DP[N], visited[N];
vc<int> divs[N];
int cur_mx=0;


int get_DP(int idx){
    if(visited[idx]==cur_mx) return DP[idx];
    int res=INF;
    if(divs[idx].size()==0) return DP[idx]=(idx>cur_mx?INF:idx);
    rng(i,0,(int)divs[idx].size()-1){
        if(divs[idx][i]>cur_mx) break;
        res=min(res,max(divs[idx][i],get_DP(idx/divs[idx][i])));
    }
    return DP[idx]=(res>cur_mx?INF:res);
}


// 36 같은게 문제가 됨. min을 4로 정해도 6,6일때 max가 최소임
// 

void Solve(){
    int n,mx;
    cin>>n>>mx;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) 
    int l,r;
    // 아 이거 ternary search?
    while(l<r){
        cur_mx=(l+r)>>1;
        if(check()) l
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(i,2,N-1){
        int j=2;
        while(i*j<N){
            j++;
            divs[i*j].pb(i);
        }
    }
    while(t--){
        Solve();
    }
    return 0;
}

