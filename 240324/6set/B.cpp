
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

string s, rev_s;
int two_con[N];
int three_con[N];
int sum_two[N], sum_three[N];
ll powp[N], powq[N], powu[N], powv[N];
ll p[N], rev_p[N];
ll q[N], rev_q[N];
ll u[N], rev_u[N];
ll v[N], rev_v[N];


bool check(int l,int r,int n){
    ll a=(p[r]-(l==0?0:p[l-1]))%MOD*powp[n-(l-1)]%MOD;
    ll b=(rev_p[n-1-l]-(n-1-r==0?0:rev_p[n-2-r]))%MOD*powp[r+2]%MOD;
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    if(a!=b) return false;
    a=(q[r]-(l==0?0:q[l-1]))%MOD*powq[n-(l-1)]%MOD;
    b=(rev_q[n-1-l]-(n-1-r==0?0:rev_q[n-2-r]))%MOD*powq[r+2]%MOD;
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    if(a!=b) return false;
    a=(u[r]-(l==0?0:u[l-1]))%MOD*powu[n-(l-1)]%MOD;
    b=(rev_u[n-1-l]-(n-1-r==0?0:rev_u[n-2-r]))%MOD*powu[r+2]%MOD;
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    if(a!=b) return false;
    a=(v[r]-(l==0?0:v[l-1]))%MOD*powv[n-(l-1)]%MOD;
    b=(rev_v[n-1-l]-(n-1-r==0?0:rev_v[n-2-r]))%MOD*powv[r+2]%MOD;
    a=(a+MOD)%MOD;
    b=(b+MOD)%MOD;
    if(a!=b) return false;
    return true;
}

void Solve(){
    int n,qq;
    cin>>n>>qq;
    cin>>s;
    rev_s.clear();
    rev_s.resize(s.size());
    rng(i,0,n-1) rev_s[i]=s[n-1-i];

    rng(i,0,n-1){
        p[i]=((i==0?0:p[i-1])+powp[i]*(s[i]-'a'))%MOD;
        q[i]=((i==0?0:q[i-1])+powq[i]*(s[i]-'a'))%MOD;
        u[i]=((i==0?0:u[i-1])+powu[i]*(s[i]-'a'))%MOD;
        v[i]=((i==0?0:v[i-1])+powv[i]*(s[i]-'a'))%MOD;
    }
    rng(i,0,n-1){
        rev_p[i]=((i==0?0:rev_p[i-1])+powp[i]*(rev_s[i]-'a'))%MOD;
        rev_q[i]=((i==0?0:rev_q[i-1])+powq[i]*(rev_s[i]-'a'))%MOD;
        rev_u[i]=((i==0?0:rev_u[i-1])+powu[i]*(rev_s[i]-'a'))%MOD;
        rev_v[i]=((i==0?0:rev_v[i-1])+powv[i]*(rev_s[i]-'a'))%MOD;
    }

    rng(i,1,n-1) two_con[i]=(s[i]!=s[i-1]);
    rng(i,2,n-1) three_con[i]=(!(s[i]==s[i-1] && s[i-1]==s[i-2]))&&(!(s[i]==s[i-2]));
    rng(i,1,n-1) sum_two[i]=sum_two[i-1]+two_con[i];
    rng(i,1,n-1) sum_three[i]=sum_three[i-1]+three_con[i];
    
    rng(i,0,qq-1){
        int l,r;
        cin>>l>>r;
        l--, r--;
        int num2=sum_two[r]-sum_two[l];
        int num3=sum_three[r]-sum_three[l+1];
        ll res=0;
        if(num2!=0){
            ll last=(r-l+1)/2*2;
            res+=(last/2)*((last/2)+1);
            if(last==r-l+1 && check(l,r,n)) res-=(r-l+1);
        }
        if(num3!=0){
            ll last=((r-l+1)%2==0?r-l:r-l+1);
            res+=(last/2+1)*(last/2+1)-1;
            if(last==r-l+1 && check(l,r,n)) res-=(r-l+1);
        }
        cout<<res<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng(i,0,N-1) powp[i]=(i==0?1:powp[i-1]*4999)%MOD;
    rng(i,0,N-1) powq[i]=(i==0?1:powq[i-1]*68769709)%MOD;
    rng(i,0,N-1) powu[i]=(i==0?1:powu[i-1]*423219)%MOD;
    rng(i,0,N-1) powv[i]=(i==0?1:powv[i-1]*687651)%MOD;
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

