
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

ll DP[N];
ll pred[N];
pll mxbyc[30]; // mx val, idx

void Solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    fill(DP,DP+n,-1);
    fill(pred,pred+n,-1);
    fill(mxbyc,mxbyc+26,make_pair(-1,-1));

    rng(i,1,n-1){
        if(s[0]==s[i]){
            DP[i]=1;
            pred[i]=-1;
        }
        pll temp=mxbyc[s[i]-'a'];
        if(temp.fi!=-1 && DP[i]<1+temp.fi){
            DP[i]=1+temp.fi;
            pred[i]=temp.se;
        }

        if(DP[i-1]!=-1) mxbyc[s[i]-'a']=max(mxbyc[s[i]-'a'],{DP[i-1],i-1});
    }
    if(DP[n-1]!=-1){
        cout<<DP[n-1]<<'\n';
        int idx=n-1;
        vc<int> ans;
        while(idx>=0){
            ans.pb(idx-pred[idx]);
            idx=pred[idx];
        }
        reverse(all(ans));
        for(auto k:ans) cout<<k<<' ';
        cout<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

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

