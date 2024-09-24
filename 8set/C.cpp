
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


int ans[220];

void Solve(){
    int n;
    cin>>n;
    int l=100,r=100;
    int res;
    cout<<"? 0"<<endl;
    cin>>res;
    assert(res!=-1);
    if(res) ans[l]=0;
    else ans[l]=1;

    for(int i=1;i<=n-1;i++){
        cout<<"? ";
        cout<<0;
        rng(j,l,r) cout<<ans[j];
        cout<<endl;
        cin>>res;
        assert(res!=-1);
        if(res) ans[--l]=0;
        else{
            cout<<"? ";
            cout<<1;
            rng(j,l,r) cout<<ans[j];
            cout<<endl;
            cin>>res;
            assert(res!=-1);
            if(res) ans[--l]=1;
            else{
                // 얘는 이제 무조건 시작하는 녀석임.
                for(;i<=n-1;i++){
                    cout<<"? ";
                    rng(j,l,r) cout<<ans[j];
                    cout<<0;
                    cout<<endl;
                    cin>>res;
                    assert(res!=-1);
                    if(res) ans[++r]=0;
                    else ans[++r]=1;
                }
                break;
            }
        }
    }
    cout<<"! ";
    assert(r-l+1==n);
    rng(i,l,r) cout<<ans[i];
    cout<<endl;
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

