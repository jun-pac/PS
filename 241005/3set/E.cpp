
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

// edge가 영향을 주고받는 과정에서 cyclic한게 없음. 그냥 아무렇게나 짜도 위상정렬처럼 될거같음
priority_queue<pll> newt[N];
ll mxnewt[N];
vc<array<ll,5>> es;
ll ans[N];

void Solve(){
    ll n,m,x1;
    cin>>n>>m>>x1;
    rng(i,0,m-1){
        int a,b,s,t; // a,b는 idx임.
        cin>>a>>b>>s>>t;
        a--, b--;
        es.push_back({s,t,a,b,i});
    }
    fill(mxnewt,mxnewt+n,-1);
    sort(es.begin(),es.end());
    rng(i,0,m-1){
        int a,b,s,t;
        s=es[i][0], t=es[i][1];
        a=es[i][2], b=es[i][3];
        int idx=es[i][4];
        if(idx==0){
            ans[idx]=x1;
            newt[b].push({-t,t+x1});
            continue;
        }
        // a쪽에서 s보다 작은 애들을 전부 넣자
        while(!newt[a].empty()){
            pll temp=newt[a].top();
            if(-temp.fi<=s){
                newt[a].pop();
                mxnewt[a]=max(mxnewt[a],temp.se);
            }
            else break;
        }
        ans[idx]=max(mxnewt[a]-s,0LL);
        newt[b].push({-t,t+ans[idx]});

    }
    rng(i,1,m-1) cout<<ans[i]<<' ';
    cout<<'\n';
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

