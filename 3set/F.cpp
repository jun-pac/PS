
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

int datas[N];
int grundy[N];

void Solve(){
    int n,mx=0;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    mx=datas[n-1];
    grundy[1]=0;
    rng(i,2,mx){
        vc<int> temp;
        int j=1;
        while(j*j<=i && j!=i){
            if(i%j==0){
                temp.pb(grundy[j]);
                temp.pb(grundy[i/j]);
            }
            j++;
        } 
        sort(temp.begin(),temp.end());
        int idx=0;
        int num=0;
        while(idx<temp.size()){
            if(temp[idx]<num) idx++;
            else if(temp[idx]==num){
                idx++; num++;
            }
            else break;
        }
        grundy[i]=num;
        //cout<<"grundy "<<i<<' '<<num<<'\n';
    }
    int ans=0;
    rng(i,0,n-1) ans=ans^grundy[datas[i]];
    if(ans==0) cout<<"Bruno\n";
    else cout<<"Anna\n";
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

