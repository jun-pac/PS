
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

int rmx[N];
bool is_use[N];

void Solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mx=-1,mx_idx;
    gnr(i,n-1,0){
        rmx[i]=max((int)s[i],(i==n-1?-1:rmx[i+1]));
    }
    //rng(i,0,n-1) cout<<rmx[i]-'a'<<' '; cout<<'\n';
    vc<int> vv;
    fill(is_use,is_use+n,0);
    int mmm=0;
    rng(i,0,n-1){
        if(s[i]==rmx[i]){
            is_use[i]=1;
            vv.pb(s[i]);
        }
        if(s[i]==rmx[0]) mmm++;
    }
    sort(all(vv));
    //rng(i,0,vv.size()-1) cout<<vv[i]; cout<<endl;
    int cnt=0;
    rng(i,0,n-1){
        if(is_use[i]) s[i]=vv[cnt++];
    }
    bool flag=1;
    rng(i,0,n-2){
        if(s[i]>s[i+1]) flag=0;
    }
    if(!flag) cout<<-1<<'\n';
    else cout<<(int)vv.size()-mmm<<'\n';
    
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

