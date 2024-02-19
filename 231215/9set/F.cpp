
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

int datas[N]; 
int vals[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int st=0;
    bool dir=1, flag; // 1이 정방향
    // all same이거나 값이 2종류밖에 없으면 둘 다 가능한거.
    
    rng(i,0,n-1) vals[i]=datas[i];
    sort(vals,vals+n);
    int cnt=unique(vals,vals+n)-vals;
    //rng(i,0,cnt-1) cout<<vals[i]<<' '; cout<<'\n';
    if(cnt==1){
        cout<<0<<'\n';
        return;
    }

    int mn=INF;
    // 시계방향 st를 찾기.
    rng(i,0,n-1){
        if(datas[i]==vals[0]){
            st=i;
            break;
        }
    }
    while(datas[(st+n-1)%n]==vals[0]) st=(st+n-1)%n;
    flag=1;
    rng(i,0,n-2) if(datas[(st+i)%n]>datas[(st+i+1)%n]){
        flag=0;
        break;
    }
    if(flag) mn=min(mn,min((n-st)%n,2+st));

    // 반시계방향 st를 찾기.
    while(datas[(st+1)%n]==vals[0]) st=(st+1)%n;
    flag=1;
    rng(i,0,n-2) if(datas[(st+n-i)%n]>datas[(st+n-i-1)%n]){
        flag=0;
        break;
    }
    if(flag) mn=min(mn,min((st+1)%n+1,n-1-st+1));
    cout<<(mn==INF?-1:mn)<<'\n';
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

