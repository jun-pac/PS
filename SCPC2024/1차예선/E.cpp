
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

#define N 50030
#define MOD 998244353
#define INF 1000000007 
int sqrtN=200;

class Query{
public:
    int idx, s, e;
    bool operator < (Query &x){
        if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

unordered_map<ll,ll> mp; // {°ª, °³¼ö}
ll cnt; 
ll ans[N];
ll datas[N];
Query qs[N];

void go(int idx){
    ll val=datas[idx];
    if(val<=1) return;
    while(mp[val]==val-1){
        mp[val]=0;
        val=val*val;
        cnt++;
    }
    mp[val]++;
}

void back(int idx){
    ll val=datas[idx];
    if(val<=1) return;
    while(mp[val]==0){
        mp[val]=val-1;
        val=val*val;
        cnt--;
    }
    mp[val]--;
}

void Solve(int tt){
    int n,q;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    cin>>q;
    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        qs[i].s=a;
        qs[i].e=b;
        qs[i].idx=i;
    }
    sort(qs,qs+q);
    mp.clear();

    cnt=0;
    int s = qs[0].s, e = qs[0].e;
    for(int i=s; i<=e; i++) go(i);
    ans[qs[0].idx]=cnt;

    for(int i=1; i<q; i++){
        while(s > qs[i].s) go(--s);
        while(e < qs[i].e) go(++e);
        while(s < qs[i].s) back(s++);
		while(e > qs[i].e) back(e--);
        ans[qs[i].idx]=cnt;
    }

    cout<<"Case #"<<tt+1<<'\n';
    rng(i,0,q-1) cout<<ans[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

