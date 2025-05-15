
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

pii datas[N];
vc<int> child[N];
ll n,m;
long long fact[N], f_inv[N];
#define MAX_DIGIT 62

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

ll catalan(ll n){
    if(n<=1) return 1;
    return nCr(2*n,n)*ari_inv(n+1)%MOD;
}

ll DFS(int idx){
    if(child[idx].size()==0){
        ll len=-datas[idx].se-datas[idx].fi;
        // cout<<"DPSD "<<idx<<' '<<datas[idx].fi<<' '<<datas[idx].se<<' '<<len<<' '<<catalan(len-1)<<'\n';
        return catalan(len);
    }
    ll len=-datas[idx].se-datas[idx].fi;
    ll res=1;
    for(auto next: child[idx]){
        len=len-(-datas[next].se-datas[next].fi);
    }
    // cout<<"DP "<<idx<<' '<<len<<' '<<catalan(len)<<'\n';
    res=catalan(len);
    for(auto next: child[idx]){
        res=res*DFS(next)%MOD;   
    }
    return res;
}


void Solve(){
    // rng(k,1,10) cout<<catalan(k)<<'\n';
    cin>>n>>m;
    rng(i,0,m-1){
        cin>>datas[i].fi>>datas[i].se;
        datas[i].se=-datas[i].se;
    }
    sort(datas,datas+m);
    datas[m]={1,-n};
    m++;
    sort(datas,datas+m);
    // cout<<"debug"<<endl;
    // rng(i,0,m-1) cout<<datas[i].fi<<' '<<datas[i].se<<endl;

    rng(i,0,m-1) child[i].clear();
    int cnt=0;
    stack<int> st;
    st.push(0);
    rng(i,1,m-1){
        while(!st.empty() && (-datas[st.top()].se<-datas[i].se)){
            st.pop();
        }
        // cout<<"top "<<st.top()<<'\n';
        child[st.top()].pb(i);
        // cout<<datas[st.top()].fi<<' '<<-datas[st.top()].se<<" is bigger than "<<datas[i].fi<<' '<<-datas[i].se<<'\n';
        st.push(i);
    }
    cout<<(DFS(0)%MOD+MOD)%MOD<<'\n';
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

