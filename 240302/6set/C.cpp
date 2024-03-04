
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

#define N 40030
#define MOD 1000000007
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

bool is_palin[N];
ll DP[N][500]; // DP[i][j] j번째 palin이하로 구성하는 경우임.
vc<int> palin;
int lasti=0;
int tens[6]={1,10,100,1000,10000,100000};

bool check(int num){
    int cnt=0;
    int temp=num;
    while(temp!=0){
        temp/=10;
        cnt++;
    }
    bool flag=1;
    rng(i,0,cnt-1){
        if(num/tens[i]%10!=num/tens[cnt-1-i]%10) flag=0;
    }
    return flag;
}

void Solve(){
    int n;
    cin>>n;
    if(lasti==0){
        DP[0][0]=1;
        rng(j,1,(int)palin.size()-1) DP[0][j]=(DP[0][j-1]+DP[0][j])%MOD;
        lasti++;
    }
    for(;lasti<=n; lasti++){
        rng(j,1,(int)palin.size()-1){
            if(palin[j]>lasti) break;
            DP[lasti][j]=DP[lasti-palin[j]][j];
        }
        rng(j,1,(int)palin.size()-1) DP[lasti][j]=(DP[lasti][j-1]+DP[lasti][j])%MOD;
    }
    //cout<<"idx "<<n<<' '<<upper_bound(all(palin),n)-palin.begin()<<'\n'; 
    //cout<<palin[upper_bound(all(palin),n)-palin.begin()-1]<<' '<<palin[upper_bound(all(palin),n)-palin.begin()]<<'\n';
    cout<<(DP[n][palin.size()-1]+MOD)%MOD<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng(i,0,N-1){
        if(check(i)) palin.pb(i);
    }
    //cout<<palin.size()<<'\n';
    //rng(i,0,499) cout<<i<<' '<<palin[i]<<'\n';
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

