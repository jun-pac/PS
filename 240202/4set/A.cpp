// 500 1000 1500 1750 2500 3000
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

string s;
string temp;
int cnt[26];

void Solve(){
    int n,k,m;
    cin>>n>>k>>m;
    cin>>s;
    temp.clear();
    bool flag=1;
    int cur=0;
    fill(cnt,cnt+k,0);
    rng(i,0,m-1){
        if(s[i]-'a'<k && cnt[s[i]-'a']==0){
            temp.pb(s[i]);
            cnt[s[i]-'a']++;
            cur++;
            //cout<<cur<<' '<<s[i]<<'\n';
            if(cur==k){
                fill(cnt,cnt+k,0);
                cur=0;
            }
        }
    }
    int prt=0;
    rng(i,0,k-1){
        if(cnt[i]==0){
            prt=i; break;
        }
    }
    if(temp.size()>=n*k) cout<<"YES\n";
    else{
        cout<<"NO\n";
        rng(i,0,n-1){
            // i*k+k-1
            if(i*k+k-1>=temp.size()){
                cout<<(char)(prt+'a');
            }
            else cout<<temp[i*k+k-1];
        }
        cout<<'\n';
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

