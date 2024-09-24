
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

#define N 3003
#define MOD 998244353
#define INF 1000000007 

// 모든 가능한 edges의 swap에 대해서 phi{deg(idx)}가 해가 된다.
vc<int> edges[N];
ll up[N], no[N]; // 위로 올리는 노브가 있느냐 없느냐의 문제임 
ll DP[N], temp[N]; 
ll fact[N];

void DFS(int idx, int p){
    //cout<<"hell DP "<<idx+1<<' '<<p+1<<endl;
    if(p!=-1 && edges[idx].size()==1){ // leaf
        up[idx]=1;
        no[idx]=1;
        return;
    }
    for(auto next : edges[idx]){
        if(next==p)continue;
        DFS(next, idx);
    }

    int cnt;
    DP[0]=0;
    bool ff=1;
    for(auto next : edges[idx]){
        if(next==p) continue;
        //cout<<"next : "<<no[next]<<' '<<up[next]<<endl;
        if(ff){
            DP[0]=no[next];
            DP[1]=up[next];
            cnt=1;
            ff=0;
            continue;
        }
        rng(i,0,cnt) temp[i]=DP[i];
        rng(i,0,cnt) DP[i]=temp[i]*no[next]%MOD;
        DP[cnt+1]=0;
        rng(i,0,cnt) DP[i+1]=(DP[i+1]+temp[i]*up[next])%MOD;
        cnt++;
    }
    //cout<<"DP : "; rng(i,0,cnt) cout<<DP[i]<<' '; cout<<endl;
    // 0~cnt를 모두 쓴다.
    ll noval=0, upval=0;
    rng(i,0,cnt){
        noval=(noval+fact[i]*DP[i])%MOD;
        upval=(upval+(fact[i+1])*DP[i])%MOD;
    }
    no[idx]=noval;
    up[idx]=upval;
    //cout<<"idx no up "<<idx+1<<' '<<noval<<' '<<upval<<'\n';
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n+1) fact[i]=(i==0?1:fact[i-1]*i)%MOD;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS(0,-1);
    //rng(i,0,n-1) cout<<no[i]<<' '; cout<<endl;
    //rng(i,0,n-1) cout<<up[i]<<' '; cout<<endl;
    cout<<(no[0]+MOD)%MOD<<'\n';
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

