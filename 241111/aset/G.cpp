
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
#define MAX_DIGIT 62

#define INF 1000000007 
int p[N];
vc<int> child[N];
ll sum[N];
ll datas[N]; // prob


// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

ll DFS(int idx){
    ll res=datas[idx];
    for(int next:  child[idx]){
        res+=DFS(next);
    }
    return sum[idx]=res;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n) child[i].clear();
    p[0]=-1;
    rng(i,1,n){
        cin>>p[i];
        child[p[i]].pb(i);
    }
    rng(i,1,n) cin>>datas[i];
    datas[0]=0;
    DFS(0);
    // {sum, idx}를 넣는 것으로
    priority_queue<pll> pq;
    pq.push({0,0});
    ll res=0;
    ll cnt=0;
    while(!pq.empty()){
        pll temp=pq.top();
        pq.pop();
        res=(res+cnt*datas[temp.se])%MOD;
        //cout<<cnt<<' '<<temp.fi<<' '<<res<<'\n';
        for(int next: child[temp.se]){
            pq.push({datas[next],next});
        }
        cnt++;
    }
    res=res%MOD;
    //cout<<"res "<<res<<'\n';
    res=res*ari_inv(sum[0]);
    cout<<(res%MOD+MOD)%MOD<<'\n';
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

