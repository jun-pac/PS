
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i+n]=datas[i];
    int start=-1;
    rng(i,0,n-1) if(datas[i]==0){
        start=i;
        break;
    }
    if(start==-1){
        cout<<"Yes\n";
        return;
    }
    bool allzero=1;
    rng(i,0,n-1) if(datas[i]==1) allzero=0;
    if(allzero){
        if(n%4==0) cout<<"Yes\n";
        else cout<<"No\n";
        return;
    }
    if(n%4==0){
        cout<<"Yes\n";
        return;
    }





    else if(start==0){
        start=n;
        while(start>0 && datas[start-1]==0) start--;
    }
    if(start==n) start=0;
    
    rng(i,0,n-1){
        if(datas[(i+start)%n]==1 && datas[(i+start+1)%n]==1){
            cout<<"Yes\n";
            return;
        }
    }
    
    vc<int> numzero;
    int lastone=start-1;
    bool flag=0;
    rng(i,0,n-1){
        if(datas[(start+i)%n]==1){
            numzero.pb(start+i-lastone-1);
            if((start+i-lastone-1)%2==0) flag=1;
            lastone==start+i;
        }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

