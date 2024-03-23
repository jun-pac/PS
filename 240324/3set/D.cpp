
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

string tar;
vc<string> s[100];
vc<pii> pos[100]; // matching위치, segment의 길이
int cur_num=1;
int DP[1000], tDP[1000]; // i-1까지 채우는데 최소의 비용임

void Solve(){
    cin>>tar; // 길이 100
    int m=tar.size();
    int n;
    cin>>n;
    rng(i,0,n-1){ // 100
        int a;
        cin>>a;
        rng(j,0,a-1){ // 10
            string temp;
            cin>>temp; // 길이 10
            s[i].pb(temp);
            rng(k,0,m-(int)temp.size()){
                bool flag=1;
                rng(u,0,(int)temp.size()-1){
                    if(tar[k+u]!=temp[u]){
                        flag=0;
                        break;
                    }
                }
                if(flag) pos[i].pb({k,temp.size()});
            }
        }
    }

    fill(DP,DP+m+1,INF);
    DP[0]=0;
    rng(i,0,n-1){
        fill(tDP,tDP+m+1,INF);
        for(auto temp : pos[i]){
            int idx=temp.fi, len=temp.se;
            assert(idx+len<=m);
            tDP[idx+len]=min(tDP[idx+len],DP[idx]+1);
        }
        rng(j,0,m){
            DP[j]=min(DP[j],tDP[j]);
        }
    }
    cout<<(DP[m]==INF?(-1):DP[m])<<'\n';
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

