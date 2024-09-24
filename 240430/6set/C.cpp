
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

int last_row[1000], last_col[1000];
int datas[1000][1000];
array<int,3> ss[1004];

void Solve(){
    int n;
    cin>>n;
    int res=0, num=0;
    int temp=n;
    int cc=0;
    int cnt=0;
    fill(last_row,last_row+n,-1);
    fill(last_col,last_col+n,-1);
    rng(i,0,n-1){
        if(i%2==0){
            rng(j,0,n-i-1){
                last_row[j]=cnt++;
            }
        }
        else{
            rng(j,0,n-i-1){
                last_col[j]=cnt++;
            }
        }
    }
    rng(i,0,n-1){
        if(last_row[i]!=-1) ss[num++]={last_row[i],1,i+1};
        if(last_col[i]!=-1) ss[num++]={last_col[i],2,i+1};
    }
    sort(ss,ss+num);
    rng(i,0,num){
        if(ss[i][1]==1){
            rng(j,0,n-1) datas[ss[i][2]-1][j]=j+1;
        }
        else{
            rng(j,0,n-1) datas[j][ss[i][2]-1]=j+1;
        }
    }
    rng(i,0,n-1) rng(j,0,n-1) res+=datas[i][j];
    // rng(i,0,n-1){
    //     rng(j,0,n-1) cout<<datas[i][j]<<' ';
    //     cout<<'\n';
    // }
    cout<<res<<' '<<num<<'\n';

    rng(i,0,num-1){
        cout<<ss[i][1]<<' '<<ss[i][2]<<' ';
        rng(j,0,n-1) cout<<j+1<<' ';
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

