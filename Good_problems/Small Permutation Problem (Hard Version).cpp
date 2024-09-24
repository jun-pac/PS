
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

ll datas[N];
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
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(datas[n-1]==-1) datas[n-1]=n;
    if(datas[n-1]!=n || datas[0]>1){
        cout<<0<<'\n';
        return;
    } 
    bool flag=1;
    int lastidx=-1; // last non -1 idx
    rng(i,0,n-1){
        if(datas[i]!=-1){
            if(lastidx==-1){
                if(!(datas[i]<=i+1)) flag=0;
            }
            else{
                if(!(datas[i]<=i+1 && datas[lastidx]<=datas[i] && datas[i]<=datas[lastidx]+2*(i-lastidx))) flag=0;
            }
            lastidx=i;
        }
    }
    if(!flag){
        cout<<0<<'\n';
        return;
    }

    ll res=1;
    lastidx=-1; // datas[n-1]=n임은 보장이 되어있음.
    rng(i,0,n-1){
        if(datas[i]==-1) continue;
        int b=datas[i], a=(lastidx==-1?0:datas[lastidx]); // 총 b-a개를 선택해야 함
        //ll temp=nCr(i+1-a, b-a)*nCr(i+1-a, b-a)%MOD*fact[b-a]%MOD; // (i+1-a)*(i+1-a)의 box에서 b-a개를 우선 고른다.
        ll temp=0;
        rng(k,max(0,b-a-(i-lastidx)),min(b-a,min(i-lastidx,lastidx+1-a))){
            ll res1=nCr(lastidx+1-a,k)*nCr(i-lastidx,k)%MOD*fact[k]%MOD;
            ll res2=nCr(i-lastidx,b-a-k)*nCr(i+1-a-k,b-a-k)%MOD*fact[b-a-k]%MOD;
            temp=(temp+res1*res2)%MOD;
        }
        res=res*temp%MOD;
        lastidx=i;
    }

    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    fill_fact();
    while(t--){
        Solve();
    }
    return 0;
}

