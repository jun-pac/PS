
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

#define N 3000
#define MOD 998244353
#define INF 1000000007 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int a[N], b[N];
map<int,int> mp;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    int acnt=0, bcnt=0;
    rng(i,0,n-1) if(a[i]==-1) acnt++;
    rng(i,0,n-1) if(b[i]==-1) bcnt++;   
    sort(a,a+n);
    sort(b,b+n);

    int as=0;
    while(as<n && a[as]==-1) as++;

    int bs=0;
    while(bs<n && b[bs]==-1) bs++;

    int tmx=max(a[n-1],b[n-1]);
    // a[0], b[0]의 역할은 뭔가 다름.

    // 모든 -1을 마음대로 지정해도 절대로 불가능한지는 어떻게 알죠
    // -1의 개수가 n-1개 이상이면 다 맞출 수 있음
    if(acnt+bcnt>=n-1){
        cout<<"Yes\n";
        return;
    }

    int num=n-(acnt+bcnt);
    int alast=as, blast=bs;
    int mx=-1;
    rng(i,as,n-1){
        blast=bs;
        if(i==n-1 || a[i]!=a[i+1]){
            rng(j,bs,n-1){
                if(j==n-1 || b[j]!=b[j+1]){
                    // cout<<a[i]<<' '<<b[j]<<' '<<i<<' '<<j<<' '<<alast<<' '<<blast<<'\n';
                    int anum=i-alast+1;
                    int bnum=j-blast+1;
                    blast=j+1;
                    mp[a[i]+b[j]]+=min(anum,bnum);
                    // cout<<a[i]<<' '<<b[j]<<' '<<mp[a[i]+b[j]]<<'\n';
                }
            }
            alast=i+1;
        }
    }

    for(auto temp: mp){
        if((temp.se)>=num) mx=max(mx,(temp.fi));
    }

    if(mx==-1){
        cout<<"No\n";
        return;
    }

    // tar가 나옴 tar는 클 수록 좋다.
    // tar가 크면 큰 것들이 tar를 만드는 데 쓰이고, 작은 원소들만 남는다.
    // -1이 작은 원소들과 더해지면 좋은 것이다.
    // -1이 작은 원소들과 더해지고 남으면 

    // tar를 만들고 남은 원소들 중 tar보다 큰 것이 없어야 함.
    // 그냥 tar보다 큰 것이 없어야 함
    if(tmx>mx){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
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

