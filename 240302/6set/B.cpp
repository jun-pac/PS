
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

string s;
int cnt[26];

void Solve(){
    cin>>s;
    int n=s.size();
    fill(cnt,cnt+26,0);
    rng(i,0,n-1) cnt[s[i]-'a']++;
    int val=0;
    rng(i,0,25) if(cnt[i]!=0) val++;
    
    bool flag=1;
    int temp=0;
    fill(cnt,cnt+26,0);
    rng(i,0,val-1){
        if(cnt[s[i]-'a']==0) temp++;
        cnt[s[i]-'a']++;
    }

    if(temp!=val){
        cout<<"NO\n";
    }
    else{
        rng(i,val,n-1){
            if(s[i]!=s[i-val]) flag=0;
        }
        cout<<(flag?"YES\n":"NO\n");
    }
    
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

