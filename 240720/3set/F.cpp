
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 
ll primes[]={29, 31, 37, 41, 43, 47, 53, 59};
double epsilon=0.0000001;

long long gcd(long long x, long long y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    ll n;
    cin>>n;
    ll res=1; // 1Àº ÀÏ´Ü µÊ.
    rng(i,1,(1<<22)-1){
        ll lcmval=1;
        bool flag=1;
        int cnt=0;
        rng(j,0,21){
            if(i&(1<<j)){
                cnt++;
                lcmval=lcmval/gcd(j+2,lcmval)*(j+2);
                if(lcmval>=60){
                    flag=0;
                    break;
                }
            }   
        }
        if(!flag) continue;
        long double dd=1;
        dd=dd/lcmval;
        ll num=(long long)(powl(n,dd)+epsilon);
        // numÀ» dd¹ø °öÇßÀ» ¶§
        //assert(pow(num,lcmval)<=n);
        ull cur=1;
        bool tflag=1;
        rng(i,0,lcmval-1){
            cur=cur*num;
            if(cur>n){
                tflag=0;
                break;
            }
        }
        if(!tflag) num--;
        tflag=1;
        cur=1;
        rng(i,0,lcmval-1){
            cur=cur*(num+1);
            if(cur>n){
                tflag=0;
                break;
            }
        }
        if(!tflag) num++;
        
        // if(tflag){
        //     num=num+1;
        //     //cout<<"this happen? "<<num<<' '<<cur<<'\n';
        // }
        if(cnt%2==0){
            res-=num-1;
        }
        else{
            res+=num-1;
        }
    }
    rng(i,0,2){
        ll cur=1;
        rng(j,0,primes[i]-1) cur=cur*3;
        if(cur<=n) res++;
    }
    rng(i,0,7){
        ll cur=1;
        rng(j,0,primes[i]-1) cur=cur*2;
        if(cur<=n) res++;
    }
    cout<<res<<'\n';
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

