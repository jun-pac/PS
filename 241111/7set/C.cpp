
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
bool used[N];
void Solve(){
    int n;
    cin>>n;
    fill(used,used+n,0);
    if(n==6){
        cout<<7<<'\n';
        cout<<"1 2 4 6 5 3\n";
    }
    else if(n%2==0){
        int k=1;
        while(2*k<=n) k=k*2;
        cout<<2*k-1<<'\n';
        vc<int> res;
        res.pb(k);
        res.pb(k-1);
        res.pb(k-2);
        res.pb(3);
        res.pb(1);
        used[k-1]=used[k-2]=used[k-3]=used[2]=used[0]=1;
        rng(i,0,n-1) if(!used[i]) res.pb(i+1);
        reverse(all(res));
        rng(i,0,n-1) cout<<res[i]<<' ';
        cout<<'\n';
        // int ch=0;
        // rng(i,0,n-1){
        //     if(i%2==0) ch=ch&res[i];
        //     else ch=ch|res[i];
        // }
        // cout<<"deb "<<ch<<'\n';
    }
    else if(n==5){
        cout<<5<<'\n';
        cout<<"2 1 3 4 5\n";
    }
    else if(n==7){
        cout<<7<<'\n';
        cout<<"2 4 5 1 3 6 7\n";
    }
    else{
        // nÈ¦¼ö
        cout<<n<<'\n';
        n--;
        int k=1;
        while(2*k<=n) k=k*2;
        vc<int> res;
        res.pb(k);
        res.pb(k-1);
        res.pb(k-2);
        res.pb(3);
        res.pb(1);
        used[k-1]=used[k-2]=used[k-3]=used[2]=used[0]=1;
        rng(i,0,n-1) if(!used[i]) res.pb(i+1);
        reverse(all(res));
        rng(i,0,n-1) cout<<res[i]<<' ';
        cout<<n+1<<'\n';

        // int ch=0;
        // rng(i,0,n-1){
        //     if(i%2==0) ch=ch&res[i];
        //     else ch=ch|res[i];
        // }
        // cout<<"deb :"<<(ch&(n+1))<<'\n';
    }

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

