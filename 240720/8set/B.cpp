
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


string s,t;

void Solve(){
    int n;
    cin>>n;
    cin>>s>>t;
    if(s[0]=='1'){
        cout<<"YES\n";
        return;
    }
    else{
        int fs=-1, ft=-1;
        rng(i,0,n-1){
            if(s[i]=='1'){
                fs=i;
                break;
            }
        }   
        rng(i,0,n-1){
            if(t[i]=='1'){
                ft=i;
                break;
            }
        }   
        if(fs==-1 && ft==-1){
            cout<<"YES\n";
        }
        else if(fs==-1){
            cout<<"NO\n";
        }
        else if(ft==-1){
            cout<<"YES\n";
        }
        else if(fs>ft){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
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

