
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

int tar[100], cur[4]; // 다음을 가리키는 곳
string s;

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1){
        cin>>tar[i];
        tar[i]--;
    }
    rng(i,0,3) cin>>cur[i];
    rng(i,0,3) cur[i]--;
    
    // cur가 가리키는 것은 어떤 함수그래프임
    // 사실 그래서 최대 n번이라서 그냥 n번을 해보면 된다.
    int last=0;
    rng(i,1,600000+n){
        rng(j,0,3) cur[j]=tar[cur[j]];
        if(s[cur[0]]=='T' && s[cur[1]]=='T' && s[cur[2]]=='P' && s[cur[3]]=='C'){
            last=i;
        }
    }
    if(last>n){
        cout<<"NeverEnds\n";
    }
    else{
        cout<<last<<'\n';
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

