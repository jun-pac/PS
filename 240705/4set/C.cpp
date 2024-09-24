
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

string s,cur,c;
int datas[N];
int fchan[N]; // 나를 처음으로 바꾼 idx

void Solve(){
    int n,m;
    cin>>n>>m;
    cin>>s;
    cur=s;
    rng(i,0,m-1) cin>>datas[i];
    rng(i,0,m-1) datas[i]--; // 각각 n-1이하
    cin>>c;

    sort(datas,datas+m);
    sort(c.begin(),c.end());
    int last=-1, cnt=0;
    rng(i,0,m-1){
        if(last!=datas[i]){
            last=datas[i];
            s[datas[i]]=c[cnt++];
        }
    }
    cout<<s<<'\n';

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

