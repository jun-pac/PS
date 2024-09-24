
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

int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }    
    int ans=0;
    int i=0;
    while(i<n){
        if(datas[i]==0){
            i++;
            continue;
        }
        if(datas[i]<=2){
            int j=i+1;
            while(j<n){
                if(datas[j]<=2){
                    break;
                }
                if(j+1<n && datas[j]<=4 && datas[j+1]<=4 && datas[j]!=0 && datas[j+1]!=0){
                    j+=2;
                }
                else{
                    break;
                }
            }
            if(j<n && datas[j]<=2){
                ans+=j-i;
                i=j+1;
            }
            else{
                ans+=min(n-1,j)-i+1;
                i=j+1;
            }
        }
        else{
            ans++;
            i++;
        }
    }
    cout<<ans<<'\n';
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

