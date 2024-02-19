
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

int datas[5050];
ll num0[5050], num1[5050];
ll DP[5050][5050]; // DP[i][j]는 i까지 essential이 j개였을 때 non-essential을 배치하는 총 가짓수
ll mpow[5050];

void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    ll cnt1=0, cnt0=0, last1=-1; // cnt0은 마지막 1앞에만 센다
    rng(i,0,n-1){
        if(datas[i]==1){
            last1=i;
            cnt1++;
        }
    }
    rng(i,0,n) mpow[i]=(i==0?1:mpow[i-1]*m)%MOD;
    if(last1==-1){
        cout<<mpow[n]<<'\n';
        return;
    }
    
    rng(i,0,n-1) num0[i]=(i==0?0:num0[i-1])+(datas[i]==0); 
    rng(i,0,n-1) num1[i]=(i==0?0:num1[i-1])+(datas[i]==1); 
    rng(i,0,last1) if(datas[i]==0) cnt0++;
    assert(cnt0+cnt1-1==last1 && datas[last1]==1 && num0[n-1]+num1[n-1]==n);

    if(cnt1+cnt0<m){
        cout<<(mpow[num0[n-1]]+MOD)%MOD<<'\n';
        return;
    }
    if(cnt1-1>m){
        // 10가
        cout<<0<<'\n';
        return;
    }
    if(m==0 && datas[0]==0){
        // 나눠야 하는 케이스인가? // 0가지
        cout<<0<<'\n';
        return;
    }
    if(m==0){
        // 2가지
        cout<<1<<'\n';
        return;
    }
    
    // DP[i][j] : i까지 essen이 j개
    if(datas[0]==0){
        DP[0][0]=0;
        DP[0][1]=m;
    }
    else DP[0][0]=1;
    rng(i,1,last1){
        rng(j,0,min(m-num1[i]+1,num0[i])){
            if(datas[i]==1) DP[i][j]=DP[i-1][j];
            else{
                ll temp=0;
                temp+=DP[i-1][j]*(j+num1[i])%MOD;// i번째가 inessen
                if(j!=0){
                    assert(m-num1[i]-j+1>=0);
                    temp+=DP[i-1][j-1]*(m-num1[i]-(j-1))%MOD;// 내가 essen
                }
                DP[i][j]=temp%MOD;
            }
            //cout<<"DP : "<<i<<' '<<j<<' '<<DP[i][j]<<'\n'; // i까지 j개의 essential
        }
        ll sum=0;
        rng(j,0,min(m-num1[i]+1,num0[i])) sum=(sum+DP[i][j])%MOD;
        if(num0[i]<2000) assert(((sum-mpow[num0[i]])%MOD+MOD)%MOD==0);
    }

    ll res=1;
    rng(i,0,last1){
        if(datas[i]==1 && m+1<=i){
            assert(res>=DP[i][m+2-num1[i]]);
            res=(res-(DP[i][m+2-num1[i]]))%MOD;
        }
        else if(datas[i]==0) res=(res*m)%MOD;
    }
    
    //assert(0);
    res=(res*mpow[num0[n-1]-num0[last1]])%MOD;
    cout<<(res+MOD)%MOD<<'\n';   
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

