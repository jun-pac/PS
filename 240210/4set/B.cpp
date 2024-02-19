
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

int datas[N]; // 사실 이건 mapping임
bool visited[N];
ll cnt[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    bool flag=1;
    rng(i,0,n-1){
        if(datas[i]<i) flag=0;
        if(datas[datas[i]]!=datas[i]) flag=0;
    }
    if(!flag){
        cout<<0<<'\n';
        return;
    }
    fill(visited,visited+n,0);
    fill(cnt,cnt+n,0);
    ll res=1;
    ll cur=0;
    rng(i,0,n-1){
        if(cnt[datas[i]]==0) cur++;
        cnt[datas[i]]++;

        if(datas[i]==i){
            res=(res*cur)%MOD;
            cur--;
        }
    }
    assert(cur==0);
    cout<<(res+MOD)%MOD<<'\n';

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

