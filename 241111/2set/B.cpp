
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 10000010
#define MOD 998244353
#define INF 1000000007 

vc<int> prime;
bool is_prime[N];
int mn_p[N];

void Solve(int tt){
    int n;
    cin>>n;
    // mn_p 중 n이하인 것의 개수
    int pos=upper_bound(mn_p,mn_p+N,n)-mn_p;
    //rng(i,0,pos-1) cout<<mn_p[i]<<'\n';
    cout<<"Case #"<<tt<<": "<<pos<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(is_prime,is_prime+N,1);
    is_prime[1]=is_prime[0]=0;
    prime.pb(2);
    
    for(int i=3; i<N; i+=2){
        if(is_prime[i]){
            prime.pb(i);
            for(int j=3; i*j<N; j+=2){
                is_prime[i*j]=0;
            }
        }
    }
    mn_p[0]=INF;
    for(int i=1; i<N; i++){
        if((i!=2 && i%2==0) || !is_prime[i]){
            mn_p[i]=INF;
            continue;
        }
        if(i%2==1){
            if(is_prime[i+2]){
                mn_p[i]=i+2;
            }
        }
        else{
            for(auto j:prime){
                if(j==2) continue;
                if(i+j>=N) break;
                if((i+j)%2==1 && is_prime[i+j]){
                    mn_p[i]=i+j;
                    break;
                }
            }
        }
        if(mn_p[i]==0) mn_p[i]=INF;
        //if(mn_p[i]<=7) cout<<i<<' '<<mn_p[i]<<'\n';
    }
    sort(mn_p,mn_p+N);

    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

