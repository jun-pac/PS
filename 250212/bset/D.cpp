
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

vc<pll> pos[N]; // x로 접근, h, idx;
pll idx_to_pos[N];
ll levt[N];

void Solve(){
    ll n,w;
    cin>>n>>w; // w is num of X .. Indep. problem
    rng(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        x--, y--;
        pos[x].pb({y,i});
    }
    rng(i,0,w-1) sort(all(pos[i]));
    int min_h=INF;
    rng(i,0,w-1){
        min_h=min(min_h, (int)pos[i].size()); // 최대 min_h개의 층만 제거됨.
        rng(j,0,(int)pos[i].size()-1){
            idx_to_pos[pos[i][j].se]={i,j};
        }
    }
    // 각 j층이 언제 제거되는지를 판단하면 게임 끝임.
    // 사실 맨 아래가 쌓이는지는 중요하지가 않은 것 아닌가?
    fill(levt,levt+min_h,0);
    rng(i,0,w-1){
        rng(j,0,min_h-1){
            // cout<<"X "<<i<<" Y "<<j<<" pos "<<pos[i][j].fi<<' '<<pos[i][j].se<<'\n';
            levt[j]=max(levt[j],pos[i][j].fi);
        }
    }


    int q;
    cin>>q;
    rng(i,0,q-1){
        int t,idx;
        cin>>t>>idx;
        idx--;
        int lev=idx_to_pos[idx].se;
        if(lev >= min_h){
            // 제거되지 않는 녀석임.
            cout<<"Yes\n";
        }
        else{
            if(t<=levt[lev]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
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

