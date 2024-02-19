
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

#define N 300030
#define MOD 998244353
#define INF 1000000007 

void Solve(){
    string s;
    cin>>s;
    int a=0, b=0;
    int n=s.size();
    if(s[0]=='0'){
        cout<<-1<<'\n';
        return;
    }
    int idx=1; // ó������ 0�� �ƴ�,, [idx, n-1]�� b��
    while(idx<n && s[idx]=='0') idx++;
    if(idx==n){
        cout<<-1<<'\n';
        return;
    }
    rng(i,0,idx-1){
        a*=10;
        a+=s[i]-'0';
    }
    rng(i,idx,n-1){
        b*=10;
        b+=s[i]-'0';
    }
    if(a<b) cout<<a<<' '<<b<<'\n';
    else cout<<-1<<'\n';
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

