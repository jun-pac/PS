
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

string s;

int cnt[20];
bool DP[2<<18];
bool visited[2<<18];
int c;

void DFS(int idx){
    if(visited[idx]) return;
    visited[idx]=1;
    rng(j,0,c-1){
        if(idx & (1<<j)){
            DP[idx-(1<<j)]=DP[idx-(1<<j)]|DP[idx];
            if(!visited[idx-(1<<j)]) DFS(idx-(1<<j));
        }
    }
}

void Solve(){
    int n,k;
    cin>>n>>c>>k;
    cin>>s;
    // c<=18
    // 'A'+c-1까지 있는거임 지금 
    fill(cnt,cnt+20,0);
    fill(DP,DP+(1<<c),0);
    rng(i,0,k-1) cnt[s[i]-'A']++;
    rng(i,k,n){
        int temp=0;
        rng(j,0,c-1){
            if(cnt[j]==0) temp+=(1<<j);
        }
        DP[temp]=1;
        if(i==n) break;
        cnt[s[i]-'A']++;
        cnt[s[i-k]-'A']--;
    }
    fill(cnt,cnt+20,0);
    cnt[s[n-1]-'A']++;
    int temp=0;
    rng(j,0,c-1){
        if(cnt[j]==0) temp+=(1<<j);
    }
    DP[temp]=1;

    //temp의 부분집합에 해당하는 것도 다 안되는거임
    fill(visited,visited+(1<<c),0);
    DFS((1<<c)-1);
    // 1인 애들은 다 안됨
    int mn=c;
    rng(i,1,(1<<c)-1){
        if(!DP[i]){
            int cnt=0;
            rng(j,0,c-1){
                if(i&(1<<j)) cnt++;
            }
            mn=min(mn,cnt);
        }
    }
    cout<<mn<<'\n';
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

