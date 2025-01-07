
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

pll datas[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) cin>>datas[i].se;
    // 똑같은 idx로 k개를 고를건데, b는 더하는 거고 a는 max임
    sort(datas,datas+n);
    // 일단 datas의 뒤의 원소가 지금 중요한거같은데
    // 사실 a단에서는 가장 마지막 원소가 정해지면, 그 다음부터는 그냥 b값최소화임. -> queue에서 k개만 유지
    // min값을 유지하므로 max q
    ll bsum=0;
    rng(i,0,k-1) bsum+=datas[i].se;
    priority_queue<ll> bq;
    rng(i,0,k-1) bq.push(datas[i].se);
    ll amx=datas[k-1].fi;
    ll mn=amx*bsum;
    rng(i,k,n-1){
        amx=datas[i].fi;
        bsum-=bq.top();
        bq.pop();
        bsum+=datas[i].se;
        bq.push(datas[i].se);
        // 무조건 마지막은 포함하는거임ㅇㅇ
        mn=min(mn,amx*bsum);
    }
    cout<<mn<<'\n';

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

