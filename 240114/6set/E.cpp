
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

ll cnt1[30], cnt2[30];
ll cnt3[900];
void Solve(){
    int n;
    string s;
    cin>>n;
    fill(cnt1,cnt1+30,0);
    fill(cnt2,cnt2+30,0);
    fill(cnt3,cnt3+900,0);

    rng(i,0,n-1){
        cin>>s;
        cnt1[s[0]-'a']++;
        cnt2[s[1]-'a']++;
        cnt3[(s[0]-'a')*30+(s[1]-'a')]++;
    }
    ll res=0;
    rng(i,0,29) res+=(cnt1[i]*(cnt1[i]-1))/2;
    rng(i,0,29) res+=(cnt2[i]*(cnt2[i]-1))/2;
    rng(i,0,30*30-1) res-=(cnt3[i]*(cnt3[i]-1));
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

