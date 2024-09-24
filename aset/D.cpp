
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

pii datas[302];
int ys[302];
int DP[302][302][302]; // [minimum alive][minimum del][maximum unresolved death]. 
// mx unresolved death == n 인 경우는 없다는 뜻. 마지막에는 이 경우만 더해줘야 한다.

// minimum del 이상에는 누구도 살 수 없음
// maximum unresolved death 이상에는 누구 하나가 del을 하고 (살아)있어야 함
// minimum alive 이상에는 누구도 del을 할 수 없음 

// minimum del > maximum unresolved이 만족해야한다는 사실.
// minimum alive > maximum unresolved death 이어야 함

int mx[302][302], mn[302][302];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--, y--; 
        datas[i]={x,y};
        ys[x]=y;
    }
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    rng(i,0,n-1){
        mx[i][i]=ys[i];
        mn[i][i]=ys[i];
        rng(j,i+1,n-1){
            mx[i][j]=max(mx[i][j-1],ys[j]);
            mx[i][j]=min(mx[i][j-1],ys[j]);
        }
    }
    // 제거를 눌렀을 때와 그냥 살아있을 때 레이아웃이 같은 문제는 어떻게?
    // 하나라고 대각선방향으로 있는지? 가 중요한거 아님?
    
    // 0번째가 죽었다
    DP[n][n][ys[0]]=1;

    // 0번째가 버튼을 눌렀다.
    DP[ys[0]][ys[0]][n]=1; // 0이상에는 누군가 버튼을 눌러야 한다는 뜻인데 사실 unresolved death가 없으면 어떡해야하는지 모르겠네
    
    // 0번째가 버튼을 안눌렀고, 사는 경우에는 버튼을 누르는 것과 이게 다를 경우에만 카운트를 더해준다.
    if(!mx[1][n-1]<ys[0]){
        DP[ys[0]][n][n]=1;
    }
    // if((i==n-1 && mn[0][i-1]>ys[i]) || (mn[0][i-1]>ys[i] && mx[i+1][n-1]<ys[i]))

    // [minimum alive][minimum del][maximum unresolved death]. 
    rng(i,1,n-1){
        stack<array<int,4>> st;
        // i,ys[i]에서 del을 하는 경우
        // mndel, mnalive > ys[i]인 것만 유효하며,
        // mxunresolve < ys[i]일 경우 전부 해결된다.

        // 죽었을 경우
        // mndel이 ys[i]보다 작으면 death, 그렇지 않으면 unresolved가 된다.
        // mnalive가 이보다 작을 수 있다.
        // 
    }

    // 마지막에는 unresolved death가 없는 것만 취급한다. 
    ll res=0;

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

