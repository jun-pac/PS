
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

int datas[N];
int nums[11][N];
bool DP[22][N];

void Solve(){
    ll n;
    cin>>n;
    int res=0;
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
    }
    rng(j,0,9){
        rng(i,0,n-1){
            nums[j][i]=(i==0?0:nums[j][i-1])+(datas[i]==j);
        }
    }
    rng(k,1,21){
        int temp=0;
        if(k==1){
            fill(DP[k],DP[k]+n,1);
            temp+=n;
            res+=n;
            continue;
        }
        rng(i,k-1,n-1){
            if(!DP[k-1][i-1]) continue;
            bool flag=1;
            int val=datas[i];
            rng(j,i-k+2,i-1){
                int tar=2*datas[j]-val;
                if(tar<=9 && tar>=0){
                    // [i-k+1, j-1]에 tar가 있으면 망
                    if(nums[tar][j-1]-(i-k<0?0:nums[tar][i-k])>0){
                        flag=0;
                        break;
                    }
                }    
            }
            if(!flag) DP[k][i]=0;
            else{
                DP[k][i]=1;
                temp++;
            }
        }
        res+=temp;
        if(temp==0) break;
    }
    ll ans=(n*(n+1))/2;
    cout<<ans-res<<'\n';
    
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

