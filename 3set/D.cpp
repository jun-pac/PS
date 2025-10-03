
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


void Solve(){
    double p,r,y;
    cin>>p>>r>>y;
    double ap=abs(p), ar=abs(r), ay=abs(y);
    double k, pp, rp;
    if(ap>ar){
        if(ap-ar >= ay){
            k=ap/2;
            pp=0;
            rp=y;
        }
        else{
            double arp = (ay+ap-ar)/2;
            double app = (ay-ap+ar)/2;
            if(y<0) pp=-app, rp=-arp;
            else pp=app, rp=arp; 
        }
    }
    else{
        if(ar-ap >= ay){
            k=ar/2;
            rp=0;
            pp=y;
        }
        else{
            double arp = (ay+ap-ar)/2;
            double app = (ay-ap+ar)/2;
            if(y<0) pp=-app, rp=-arp;
            else pp=app, rp=arp;
        }
    }
    cout<<fixed;
    cout.precision(12);
    cout<<(r+rp)/2<<' '<<(p+pp)/2<<' '<<(rp-r)/2<<' '<<(pp-p)/2<<'\n';
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

