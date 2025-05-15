
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N], seconds[N];
ll n,m,k;

ll get_x(ll x){
    if(x<=2*m-1) return datas[x-1];
    if(x<=4*m-1){
        // x/2
        return seconds[x/2-m];
    }
    ll cnt=2;
    ll temp=x/4;
    ll mul=4;
    while(temp>=2*m){
        cnt++;
        mul*=2;
        temp/=2;
    }
    // cout<<"cnt mul "<<cnt<<' '<<mul<<'\n';
    if(cnt%2==0){
        // 4m 8m-1
        ll idx=x-mul*m;
        assert(idx/mul<m);
        ll val=seconds[idx/mul]^k; // a
        ll r=idx%mul;
        // cout<<"idx/mul idx%mul "<<idx<<' '<<idx/mul<<' '<<r<<'\n';

        // [0, mul * m - 1]
        mul/=4;
        while(cnt>2){
            ll group=r/mul;
            r%=mul;
            if(group==1 || group==3) val=0;
            else if(group==2) val=k;
            cnt-=2;
            mul/=4;
        }
        // cout<<"MUL CNT "<<mul<<' '<<cnt<<'\n';
        assert(mul==1);
        assert(r<=3);
        if(r<=1) return val;
        else return k;
    }
    else{
        // 8m  16m-1
        ll idx=x-mul*m;
        assert(idx/mul<m);
        ll val=seconds[idx/mul]; // a
        ll r=idx%mul;
        // cout<<"idx/mul idx%mul "<<idx/mul<<' '<<r<<'\n';

        // [0, mul * m - 1]
        mul/=4;
        while(cnt>1){
            ll group=r/mul;
            r%=mul;
            if(group==1 || group==3) val=k;
            else if(group==2) val=0;
            cnt-=2;
            mul/=4;
        }
        // cout<<"MUL CNT "<<mul<<' '<<cnt<<'\n';
        // assert(mul==1);
        assert(r<=1);
        return val;
    }
}

void Solve(){
    ll l,r;
    cin>>n>>l>>r;
    rng(i,0,n-1) cin>>datas[i];
    m=(n+1)/2;
    if(n%2==0){
        datas[n]=0;
        rng(i,0,n/2-1) datas[n]=datas[n]^datas[i];
        n++;
        m++;
    }
    // n==2*m-1
    assert(n==2*m-1);
    // cout<<"n m l: "<<n<<' '<<m<<' '<<l<<'\n';
    seconds[0]=0;
    rng(i,1,m) seconds[0]=seconds[0]^datas[i-1];
    rng(i,1,m-1) seconds[i]=seconds[i-1]^datas[m-1+i];
    // cout<<"SEC "; rng(i,0,m-1) cout<<seconds[i]<<' ';
    // cout<<'\n';
    k=seconds[m-1];
    cout<<get_x(l)<<'\n';

    // ll cur=datas[n-1];
    rng(i,n,68-1){
        datas[i]=0;
        rng(j,0,(i+1)/2-1) datas[i]=datas[i]^datas[j];
    }
    // // cout<<"54 "<<get_x(54)<<'\n';
    // rng(i,0,68) cout<<i+1<<' '<<datas[i]<<' '<<get_x(i+1)<<'\n';
    // cout<<"Actual: "<<datas[l-1]<<"\n";
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

