
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

string s,t; // target
vc<int> spos, tpos; // counter of 01 10' position,, based on first element 

void Solve(){
    int n;
    cin>>n;
    cin>>s>>t;
    // 좌우의 state가 다를 때, 나의 state를 바꿀 수 있음.
    // 1-group, 0-group
    bool flag=1;
    int scnt=0, tcnt=0;
    spos.clear(), tpos.clear();
    rng(i,0,n-2) if(s[i]!=s[i+1]) spos.pb(i);
    rng(i,0,n-2) if(t[i]!=t[i+1]) tpos.pb(i);
    if(spos.size()!=tpos.size() || s[0]!=t[0]){
        cout<<-1<<'\n';
        return;
    }
    ll res=0;
    rng(i,0,(int)spos.size()-1){
        res+=abs(spos[i]-tpos[i]);
    }
    cout<<res<<'\n';

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

