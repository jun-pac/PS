
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

string mp[101];
bool visited[101][101]; // 

void Solve(){
    int h,w,x,y;
    cin>>h>>w>>x>>y;
    rng(i,0,h-1) cin>>mp[i];
    x--, y--;
    string t;
    cin>>t;
    int n=t.size();
    int cnt=0;
    rng(i,0,n-1){
        int nx, ny;
        if(t[i]=='U'){
            nx=x-1;
            ny=y;
        }
        if(t[i]=='D'){
            nx=x+1;
            ny=y;
        }
        if(t[i]=='L'){
            nx=x;
            ny=y-1;
        }
        if(t[i]=='R'){
            nx=x;
            ny=y+1;
        }
        if(0<=nx && nx<h && 0<=ny && ny<w && mp[nx][ny]!='#'){
            x=nx, y=ny;
            if(mp[nx][ny]=='@' && !visited[nx][ny]){
                visited[nx][ny]=1;
                cnt++;
            }
        }
    }
    cout<<x+1<<' '<<y+1<<' '<<cnt<<'\n';
} 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

