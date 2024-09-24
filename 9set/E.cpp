
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

int parent[N];
vc<int> top10[N];

int find_root(int idx){
    if(idx==parent[idx]) return idx;
    return parent[idx]=find_root(parent[idx]);
}



void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) parent[i]=i;
    rng(i,0,n-1) top10[i].pb(i);
    rng(i,0,q-1){
        int c,a,b;
        cin>>c>>a>>b;
        if(c==1){
            a--, b--;
            int ra=find_root(a);
            int rb=find_root(b);
            if(ra==rb) continue;
            else{
                vc<int> temp;
                rng(j,0,(int)top10[ra].size()-1) temp.pb(top10[ra][j]);
                rng(j,0,(int)top10[rb].size()-1) temp.pb(top10[rb][j]);
                sort(all(temp));
                reverse(all(temp));
                if(temp.size()>10){
                    int sz=temp.size();
                    rng(j,10,sz-1) temp.pop_back();
                }
                top10[ra]=temp;  
                parent[rb]=ra;
            }
        }
        else{
            a--; // b°³
            int ra=find_root(a);
            if(top10[ra].size()<b) cout<<-1<<'\n';
            else{
                cout<<top10[ra][b-1]+1<<' ';
                cout<<'\n';
            }
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

