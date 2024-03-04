
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

int child[N][2];
int val[N];
int datas[N];
int cnt=0;

long long fact[N], f_inv[N];

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    ll res=1;
    for(ll i=n; i>n-r; i--){
        res=(res*i)%MOD;
    }
    res=(res*f_inv[r])%MOD;
    return res;
}


void DFS(int idx){
    if(child[idx][0]!=-2) DFS(child[idx][0]);
    datas[cnt++]=val[idx];
    if(child[idx][1]!=-2) DFS(child[idx][1]);
}

void Solve(){
    ll n,c;
    cin>>n>>c;
    rng(i,0,n-1){
        cin>>child[i][0]>>child[i][1]>>val[i];
        child[i][0]--, child[i][1]--;
    }
    cnt=0;
    DFS(0);

    ll res=1;
    ll last=-1; // ¸¶Áö¸· val
    ll lval=1;
    rng(i,0,n-1){
        if(datas[i]!=-1){
            if(i!=last+1){
                int len=i-last-1;
                res=(res*nCr(len+datas[i]-lval,len))%MOD;
            }
            last=i;
            lval=datas[i];
        }
    }
    if(last!=n-1) res=(res*nCr(n-last-1+c-lval,n-last-1));
    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill_fact();
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

