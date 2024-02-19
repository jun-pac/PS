
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

string datas[N];
int n,m,k;
vc<int> DP[N];
vc<int> vert[N], diag[N]; 
int t;

int get_mx(){
    int res=0;
    int cur=0;
    rng(i,0,min(n-1,k)){
        rng(j,0,min(m-1,k-i)){
            cur+=(datas[i][j]=='#');
        }
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            vert[i][j]=(i==0?0:vert[i-1][j])+(datas[i][j]=='#');
        }
    }
    rng(i,0,n-1){
        rng(j,0,m-1){
            diag[i][j]=((i==0||j==m-1)?0:diag[i-1][j+1])+(datas[i][j]=='#');
        }
    }
    int rowcur=cur;
    rng(i,0,n-1){
        rng(j,0,m-1){
            res=max(res,cur);
            if(j==m-1) continue;
            int temp=(n-1<i+k?i+k-n+1:0);
            cur-=(vert[min(i+k,n-1)][j]-(i==0?0:vert[i-1][j]));
            cur+=((j+1+temp<m?diag[i+k-temp][j+1+temp]:0)-((i==0||j+k+2>=m)?0:diag[i-1][j+k+2])); 
        }   
        if(i==n-1) break;
        cur=rowcur;
        rng(j,0,min(m-1,k)){
            cur-=(datas[i][j]=='#');
        }
        gnr(j,min(m-1,k),0){
            if(i+1-j+k>=n) break;
            cur+=(datas[i+1-j+k][j]=='#');
        }
        rowcur=cur;
    }
    return res;
}

void Solve(){
    cin>>n>>m>>k;
    rng(i,0,n-1) DP[i].resize(m);
    rng(i,0,n-1) vert[i].resize(m);
    rng(i,0,n-1) diag[i].resize(m);
    
    int q,w,e,r;
    //rng(i,0,n-1) datas[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    int res=get_mx();
    q=get_mx();
    rng(i,0,n-1) reverse(all(datas[i]));
    res=max(res,get_mx());
    w=get_mx();
    reverse(datas,datas+n);
    res=max(res,get_mx());
    e=get_mx();
    rng(i,0,n-1) reverse(all(datas[i]));
    res=max(res,get_mx());
    r=get_mx();
    cout<<res<<'\n';
    // if(t==1000-22 && res==12){
    //     reverse(datas,datas+n);
    //     cout<<n<<' '<<m<<' '<<k<<'\n';
    //     rng(i,0,n-1){
    //         cout<<datas[i]<<'\n';
    //     }
    //     cout<<"ans : "<<q<<' '<<w<<' '<<e<<' '<<r<<'\n';
    // }
    //cout<<"ans : "<<q<<' '<<w<<' '<<e<<' '<<r<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

