
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[100];
vc<int> ans;

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];

    if(n==2){
        if(datas[0]<=datas[1]){
            cout<<"Yes\n";
            cout<<0<<'\n';
        }
        else if(datas[0]>=datas[1]+k){
            cout<<"Yes\n";
            cout<<1<<'\n';
            cout<<1<<'\n';
        }
        else{
            cout<<"No\n";
        }
        return;
    }

    rng(i,1,n-2){
        // i, i+1±³È¯
        while(datas[i]<datas[i-1]){
            datas[i]+=k;
            datas[i+1]+=k;
            ans.pb(i);
            ans.pb(i);
            // cout<<'?'<<'\n';
        }
    }
    if(datas[n-2]<=datas[n-1]){
        // end
    }
    else if(datas[n-2]>=datas[n-1]+k){
        ans.pb(n-2);
        swap(datas[n-2],datas[n-1]);
        datas[n-2]+=k;
        while(datas[n-2]<datas[n-3]){
            ans.pb(n-2);
            ans.pb(n-2);
            datas[n-2]+=k;
            datas[n-1]+=k;
        }
    }
    else{
        ans.pb(n-2);
        swap(datas[n-2],datas[n-1]);
        datas[n-2]+=k;
        ans.pb(n-3);
        swap(datas[n-3],datas[n-2]);
        datas[n-3]+=k;
        while(datas[n-2]<datas[n-3]){
            ans.pb(n-2);
            ans.pb(n-2);
            datas[n-2]+=k;
            datas[n-1]+=k;
        }
    }

    cout<<"Yes\n";
    cout<<(int) ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1){
        cout<<ans[i]+1<<' ';
    }
    cout<<'\n';
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

