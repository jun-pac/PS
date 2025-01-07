
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 1000010
#define MOD 998244353
#define INF 1000000007 

pair<double,double> datas[N];

void Solve(int tt){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    double mx=datas[0].se, mn=datas[0].fi;
    rng(i,0,n-1){
        mx=min(mx,datas[i].se/(i+1));
        mn=max(mn,datas[i].fi/(i+1));
    }
    cout<<"Case #"<<tt<<": ";
    if(mx>=mn){
        cout<<fixed;
        cout.precision(12);
        cout<<1/mx<<'\n';
    }
    else cout<<-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

