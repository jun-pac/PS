
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

#define N 3000
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int level[N];
vc<int> lev_idx[N];
vc<int> ans;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n) lev_idx[i].clear();
    ans.clear();
    int mx=0, mx_idx;
    rng(i,0,n-1){
        cout<<"? "<<i+1<<' '<<n<<' ';
        rng(j,0,n-1) cout<<j+1<<' ';
        cout<<endl;
        int res;
        cin>>res;
        level[i]=res;
        lev_idx[res].pb(i);
        if(mx<res) mx_idx=i;
        mx=max(mx,res);
    }
    int remain_n=n-lev_idx[mx].size();
    ans.pb(mx_idx);

    gnr(l,mx-1,1){
        remain_n-=lev_idx[l].size();
        for(auto i: lev_idx[l]){
            cout<<"? "<<mx_idx+1<<' '<<remain_n+ans.size()+1<<' ';
            for(auto j: ans){
                cout<<j+1<<' ';
            }
            cout<<i+1<<' ';
            rng(j,0,n-1) if(level[j]<l) cout<<j+1<<' ';
            cout<<endl;
            
            int res;
            cin>>res;
            if(res==mx){
                ans.pb(i);
                break;
            }
        }
    }

    cout<<"! "<<mx<<' ';
    for(auto i: ans) cout<<i+1<<' ';
    cout<<endl;


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

