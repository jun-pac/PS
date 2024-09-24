
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

string s;

void Solve(){
    int n,k;
    cin>>n>>k;
    int num=n/k;
    cin>>s;
    int cnt1=0, cnt0=0;
    rng(i,0,n-1){
        if(s[i]=='1') cnt1++;
        else cnt0++;
    }
    if(num%2==0){
        if(cnt1!=cnt0){
            cout<<-1<<'\n';
            return;
        }
    }
    else{
        if(abs(cnt1-cnt0)!=k){
            cout<<-1<<'\n';
            return;
        }
    }
    char cur=s[0];
    int last=0,p=-1;
    rng(i,0,n-1){
        if(s[i]==cur){
            if(i-last+1>k){
                p=i;
                break;
            }
        }
        else{
            if(i-last!=k){
                p=i;
                break;
            }
            last=i;
            cur=s[i];
        }
    }
    if(p==-1){
        cout<<n<<'\n';
        return;
    }
    int rp=p;
    while(rp+1<n && s[rp+1]==s[p]) rp++;
    p=rp-k+1;
    if(p<=0){
        cout<<-1<<'\n';
        return;
    }
    bool flag=1;
    last=p;
    cur=s[p];
    gnr(i,p-1,0) s.push_back(s[i]);
    rng(i,p,p+n-1){
        if(s[i]==cur){
            if(i-last+1>k){
                flag=0;
                break;
            }
        }
        else{
            if(i-last!=k){
                flag=0;
                break;
            }
            last=i;
            cur=s[i];
        }
    }
    if(flag){
        cout<<p<<'\n';
    }
    else{
        cout<<-1<<'\n';
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

