
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

double datas[N];

void Solve(int tt){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    double l=datas[n-1]/2;
    double temp=M_PI;
    //cout<<"T "<<temp<<'\n';
    rng(i,0,n-2) temp+=2*asin(datas[i]/2/l);
    if(temp<=2*M_PI){
        // 이러면 이제
        double r=10000000000;
        while(abs(r-l)>0.00000001){
            double mid=(l+r)/2;
            double theta=2*asin(datas[n-1]/2/mid);
            rng(i,0,n-2) theta-=2*asin(datas[i]/2/mid);
            if(theta>0) l=mid;
            else r=mid;
        }
        cout<<fixed;
        cout.precision(12);
        cout<<l<<'\n';
        return;
    }
    double r=0;
    rng(i,0,n-1) r+=datas[i]/2;
    while(abs(r-l)>0.00000001){
        double mid=(l+r)/2;
        double theta=0;
        rng(i,0,n-1) theta+=2*asin(datas[i]/2/mid);
        //cout<<"temp "<<theta<<'\n';
        if(theta>2*M_PI){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed;
    cout.precision(12);
    cout<<r<<'\n';
    //cout<<"Case #"<<tt+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

