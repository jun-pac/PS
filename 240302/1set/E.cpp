
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

string datas[2];
int DP[N][4]; // i까지 스왑했을 때 마지막 상태를 layout_j로 만들기 위한 최소의 제거의 개수

void Solve(){
    int n;
    cin>>n;
    rng(i,0,1) cin>>datas[i];
    // 최대로 남길 수 있는 1의 개수를 구하는 문제.
    // 좋은 layout이 어떤 것인지 잘 생각해보자.
    int num1=0;
    rng(i,0,1) rng(j,0,n-1) if(datas[i][j]=='1') num1++;
    if(num1==0){
        cout<<0<<'\n';
        return;
    }

    rng(i,0,3) fill(DP[i],DP[i]+n,INF); // 불가능하면 INF죠
    if(datas[0][0]=='0' && datas[1][0]=='0') DP[0][0]=0;
    else if(datas[0][0]=='0' && datas[1][0]=='1'){
        DP[0][1]=0;
        DP[0][0]=1;
    }
    else if(datas[0][0]=='1' && datas[1][0]=='0'){
        DP[0][0]=0;
    }
    else if(datas[0][0]=='1' && datas[1][0]=='1'){
        DP[0][3]=0;
        DP[0][0]=1;
        DP[0][1]=1;
    }

    rng(i,1,n-1){
        if(datas[0][i]=='0' && datas[1][i]=='0'){
            DP[i][0]=DP[i-1][0];
            DP[i][1]=DP[i-1][1];
            DP[i][2]=DP[i-1][2];
            DP[i][3]=DP[i-1][3];
        }
        else if(datas[0][i]=='0' && datas[1][i]=='1'){
            //DP[i][1]=0;
            //DP[i][0]=1;
            DP[i][0]=DP[i-1][0]+1; // 그냥 제거하면 됨.
            DP[i][1]=min(DP[i-1][0],min(DP[i-1][1],DP;
            DP[i][2]=DP[i-1][2];
            DP[i][3]=DP[i-1][3];
        }
        else if(datas[0][i]=='1' && datas[1][i]=='0'){
            DP[i][0]=0;
        }
        else if(datas[0][i]=='1' && datas[1][i]=='1'){
            DP[i][3]=0;
            DP[i][0]=1;
            DP[i][1]=1;
        }
    }
    
    cout<<num1-min(min(DP[n-1][0],DP[n-1][1]),min(DP[n-1][2],DP[n-1][3]))<<'\n';
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

