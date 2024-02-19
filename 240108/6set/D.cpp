
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

void Solve(){
    int t,m;
    int n;
    cin>>t>>m>>n;
    if(t==1){
        unordered_map<ll,int> mp, mp1;
        rng(i,0,n-1){
            mp[i]=i;
        }
        rng(i,0,n-1){
            mp[i]++;
        }
        rng(i,0,n-1){
            mp.erase(i);
        }
        if(m==1){
            ll sum=0;
            rng(i,0,n-1){
                mp[i]=i;
                sum+=mp.size();
            }
            rng(i,0,n-1){
                if(mp.find(i)==mp.end()) sum--;
            }
            for(auto [k,v] : mp){
                sum+=k+v;
            }
        }
        if(m==2){
            rng(i,0,n-1) mp[(ll)i*i]++;
        }
        if(m==3){
            rng(i,0,n-1) mp[i]=i;
            rng(i,0,n-1) mp1[i]=i;
            rng(i,0,n-1) swap(mp,mp1);
        }
    }
    if(t==2){
        map<int,int> mp, mp1;
        cin>>t>>n;
        rng(i,0,n-1){
            mp[i]=i;
        }
        rng(i,0,n-1){
            mp[i]++;
        }
        rng(i,0,n-1){
            mp.erase(i);
        }
        if(m==1){
            ll sum=0;
            rng(i,0,n-1){
                mp[i]=i;
                sum+=mp.size();
            }
            rng(i,0,n-1){
                if(mp.find(i)==mp.end()) sum--;
            }
            for(auto [k,v] : mp){
                sum+=k+v;
            }
        }
        if(m==2){
            rng(i,0,n-1) mp[(ll)i*i]++;        
        }
        if(m==3){
            rng(i,0,n-1) mp[i]=i;
            rng(i,0,n-1) mp1[i]=i;
            rng(i,0,n-1) swap(mp,mp1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

