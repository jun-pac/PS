
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int a[N], b[N];
int fmatch[N], lmatch[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,m-1) cin>>b[i];
    // ���� �ռ� match�� ���� match�� �ٸ��� Ȯ��
    int idx=0;
    rng(i,0,m-1){
        while(idx<n && b[i]!=a[idx]) idx++;
        if(idx==n){
            cout<<"No\n";
            return;
        }
        fmatch[i]=idx;
        idx++;
    }
    idx=n-1;
    gnr(i,m-1,0){
        while(idx>=0 && b[i]!=a[idx]) idx--;
        if(idx==-1){
            cout<<"No\n";
            return;
        }
        lmatch[i]=idx;
        idx--;
    }

    rng(i,0,m-1) if(fmatch[i]!=lmatch[i]){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

