
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

ll DP1[1000][1000], DP2[1000][1000]; // i개의 step이 남았는데, j개의 operation을 더 할 수 있는
ll arbi1[1000][1000], arbi2[1000][1000];
ll n,k,p;


ll get_arbi(int a, int b){
    if(arbi1[a][b]!=-1) return arbi1[a][b];
    if(a==0 || b==0) return arbi1[a][b]=1;
    ll res=0;
    rng(k,0,b){
        // k개를 아래로 보낼거임
        if(arbi2[a][k]!=-1) res=(res+arbi2[a][k])%p;
        else{
            ll temp=0;
            rng(j,0,k){
                temp=(temp+get_arbi(a-1,j)*get_arbi(a-1,k-j))%p;
            }
            arbi2[a][k]=temp;
            res=(res+temp)%p;
        }
    }
    return arbi1[a][b]=res;
}


ll get_DP(int a, int b){
    if(DP1[a][b]!=-1) return DP1[a][b];
    if(a==0) return DP1[a][b]=1;
    // b를 나눠야 함.
    ll res=0;
    rng(k,1,b){ // 아래로 내려보낼게 k임
        if(DP2[a][k]!=-1) res=(res+DP2[a][k])%p;
        else{
            ll temp=0;
            rng(i,0,(k-1)/2){
                temp=(temp+get_DP(a-1,k-i)*get_arbi(a-1,i))%p;
            }
            DP2[a][k]=temp;
            res=(res+temp)%p;
        }
    }
    return DP1[a][b]=res;
}


void Solve(){    
    cin>>n>>k>>p;
    rng(i,0,n) fill(DP1[i],DP1[i]+k+1,-1);
    rng(i,0,n) fill(DP2[i],DP2[i]+k+1,-1);
    rng(i,0,n) fill(arbi1[i],arbi1[i]+k+1,-1);
    rng(i,0,n) fill(arbi2[i],arbi2[i]+k+1,-1);
    ll res=get_DP(n-1,k);
    // 2^(n-1)가지를 곱해야 한다.
    rng(i,0,n-2) res=(res*2)%p;
    cout<<(res%p+p)%p<<'\n';
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

