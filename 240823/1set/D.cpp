
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

void Solve(){
    int n;
    cin>>n;
    if(n>=6){
        cout<<4<<'\n';
        rng(i,0,n-1){
            cout<<(i%4)+1<<' ';
        }
        cout<<'\n';
        return;
    }
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
    }
    else if(n==2){
        cout<<2<<'\n';
        cout<<"1 2"<<'\n';
    }
    else if(n==3){
        cout<<2<<'\n';
        cout<<"1 2 2"<<'\n';
    }
    else if(n==4){
        cout<<3<<'\n';
        cout<<"1 2 2 3"<<'\n';
    }
    else if(n==5){
        cout<<3<<'\n';
        cout<<"1 2 2 3 3"<<'\n';
    }
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

