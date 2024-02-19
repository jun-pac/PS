
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
int backz[N], num[N];
priority_queue<int> pq;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        cin>>datas[i];
        int temp=datas[i];
        num[i]=0;
        while(temp!=0){
            num[i]++;
            temp/=10;
        }
        temp=datas[i];
        backz[i]=0;
        while(temp%10==0){
            backz[i]++;
            temp/=10;
        }
        //cout<<datas[i]<<' '<<num[i]<<' '<<backz[i]<<'\n';
    }
    // 합쳐서 m자리보다 커야 sasha승리구나
    // 그럼 0을 최대한 적게 제거
    // anna가 먼저 하는데 anna입장에서는 가장 많이 0을 제거하는게 맞음.

    int tnum=0;
    rng(i,0,n-1) tnum+=num[i];
    //while(!pq.empty()) pq.pop();
    //rng(i,0,n-1) pq.push(-backz[i]);
    sort(backz,backz+n);
    reverse(backz,backz+n);
    int ssc=0;
    rng(i,0,n-1){
        if(i%2==0) ssc+=backz[i];
    }
    if(tnum-ssc>m) cout<<"Sasha\n";
    else cout<<"Anna\n";
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

