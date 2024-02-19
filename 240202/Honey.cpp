
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

#define N 100100
#define MOD 998244353
#define INF 1000000007 

int ans[2000][2000];

void fill_hex(int n, int x, int y, int val){
    if(n==1){
        ans[x][y]=val;
        return;
    }
    rng(i,0,n-2) ans[x+i][y+i]=val++;
    rng(i,0,n-2) ans[x+n-1+2*i][y+n-1]=val++;
    rng(i,0,n-2) ans[x+3*n-3+i][y+n-1-i]=val++;
    rng(i,0,n-2) ans[x+4*n-4-i][y-i]=val++;
    rng(i,0,n-2) ans[x+3*n-3-2*i][y-n+1]=val++;
    rng(i,0,n-2) ans[x+n-1-i][y-n+1+i]=val++;
    fill_hex(n-1,x+2,y,val);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    fill_hex(n,0,n-1,1);   
    rng(i,0,n-1){
        int num=i+1;
        rng(j,0,num-1) cout<<ans[i][n-num+2*j]<<' ';
    }
    rng(i,n,3*n-4){
        if(i%2==n%2) rng(j,0,n-2) cout<<ans[i][1+2*j]<<' ';
        else rng(j,0,n-1) cout<<ans[i][2*j]<<' '; 
    }
    rng(i,3*n-3,4*n-4){
        int num=4*n-3-i;
        rng(j,0,num-1) cout<<ans[i][n-num+2*j]<<' ';
    }
    cout<<'\n';
    return 0;
}
