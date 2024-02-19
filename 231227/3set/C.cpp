
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

int cnt[35], temp[35];

void Solve(){
    int n,a,b;
    cin>>n;
    rng(i,0,n-1){
        cin>>a>>b;
        if(a==1){
            cnt[b]++;
            // rng(j,b,30){
            //     if(cnt[j]>=3){
            //         cnt[j]-=2;
            //         cnt[j+1]++;
            //     }
            // }
        }   
        else{
            // b를 만들 수 있느냐?
            rng(j,0,30) temp[j]=cnt[j]; 
            gnr(j,30,0){
                if(temp[j]==0) continue;
                while(temp[j]!=0 && (1<<j)<=b){
                    temp[j]--;
                    b-=(1<<j);
                }
            }
            if(b==0) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    
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

