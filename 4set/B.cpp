
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

int getcnt(ll x){
    int cnt=0;
    ll temp=x;
    while(temp!=0){
        temp=temp/10;
        cnt++;
    }
    return cnt;
}
void Solve(){
    ll x;
    cin>>x;
    int cnt=getcnt(x);
    assert(cnt<=8);
    // cout<<"Cnt "<<cnt<<'\n';
    if(cnt%2==1){
        cout<<x<<0<<'\n';
    }
    else if(cnt<=4){
        cout<<x;
        rng(i,0,cnt-1) cout<<0;
        cout<<endl;
    }
    else if(cnt==6){
        cout<<x<<0<<0<<'\n';
    }
    else{
        if(getcnt(2*x)!=cnt) cout<<2*x<<'\n';
        else if(getcnt(8*x)!=cnt) cout<<2*x<<'\n';
        else cout<<26*x<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // rng(k,1,100){
    //     cout<<k<<' '<<(1000000000+k)%(k+1)<<'\n';
    // }

    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

