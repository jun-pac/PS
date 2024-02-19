
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

map<ll,ll> DP[N]; // 예를 들면 {color, num} -> violation을 안하고 담을 수 있는 개수임
int datas[N];
int n;
vc<int> edges[N];
ll res;

void DFS(int idx, int p){
    for(auto next:edges[idx]){
        if(next==p) continue;
        DFS(next,idx);
        res=(res+DP[next][datas[idx]])%MOD;
        if(DP[next].size()>DP[idx].size()) swap(DP[next], DP[idx]);
    }
    if(idx!=0 && edges[idx].size()==1){ // leaf
        DP[idx][datas[idx]]=1;
        return;
    }

    //cout<<"IDX "<<idx+1<<'\n';
    for(auto next : edges[idx]){
        if(next==p) continue;
        //cout<<"NXT "<<next+1<<'\n';
        for(auto [col,val] : DP[next]){
            //cout<<"next's "<<col<<' '<<val<<'\n';
            if(DP[idx][col]==0){
                DP[idx][col]=val;
            }
            else{
                ll ori=DP[idx][col];
                DP[idx][col]=((ori+1)*(val+1)-1)%MOD;
                res=(res+ori*val)%MOD;
            }
        }
    }
    DP[idx][datas[idx]]++; // 하나를 넣는 것은 추가적인 combination을 만들지 않음. res의 영향은 이미 고려
    // for(auto [col,val] : DP[idx]){
    //     cout<<"["<<col<<' '<<val<<"] ";
    // }
    // cout<<'\n';
    // 이제 나머지 케이스는 모두 idx를 지나지만 홀로 포함하지는 않는 것이다.
    // 근데 이게 2개 이상을 뽑는 것으로 개수가 있었을 텐데 한 개 있는걸로 이렇게 해도 되는가?
    // 결국 위에서 원하는 것은 위에서 내려다볼때 violation (부모 자손관계에서 둘 다 선택)없이 1개 이상 뽑는 combination임
    // 이건 다 곱해야 하는 게 맞다. 
    // 1개 이상을 뽑는거다 알겠나
    // (1개 이상 + 1)*(1개 이상 + 1)* ... *()을 하면 어떻게 되는거죠
    // 그러면 나머지는 다 좋은데 1과 (sum)(1개 이상)들은 더 올라가면 안되는 것. 
    // 이거 그냥 map을 썼어야 하네
    // 그때그때 merge를 하는 방법은 어떨까요?
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b), edges[b].pb(a);
    }
    res=0;
    DFS(0,-1);
    cout<<((res+n)%MOD+MOD)%MOD<<'\n';
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

