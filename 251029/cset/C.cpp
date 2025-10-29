
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

int amb[N];
string s;
set<pii> st;

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1) amb[i]=(i==0?0:amb[i-1])+(s[i]=='a'?1:-1);
    if(amb[n-1]==0){
        cout<<0<<'\n';
        return;
    }
    st.clear();
    // rng(i,0,n-1){
    //     st.insert({amb[i],i});
    // }
    ll tot=amb[n-1];
    int mn=n;
    gnr(i,n-1,0){
        auto tempp=st.lower_bound({amb[i]+tot,-1});
        if(tempp!=st.end() && (tempp->fi)==amb[i]+tot) mn=min(mn,(tempp->se) - i);
        st.insert({amb[i],i});
    }
    auto temp = st.lower_bound({tot,-1});
    if(temp!=st.end() && (temp->fi)==tot)  mn=min(mn,(temp->se)+1);

    if(mn==n) cout<<-1<<'\n';
    else cout<<mn<<'\n';
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

