
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

void Solve(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int nums=0, numt=0;
    rng(i,0,n-1) nums+=(s[i]=='A');
    rng(i,0,n-1) numt+=(t[i]=='A');
    if(numt==n){
        cout<<(nums==n?0:-1)<<'\n';
        return;
    }
    if(numt==0){
        cout<<(nums==0?0:-1)<<'\n';
        return;
    }

    int fa=0, lb=n-1; // in T
    bool flag=1;
    while(fa<n && t[fa]=='B'){
        if(s[fa]=='A') flag=0;
        fa++;
    }
    // fa는 처음으로 t에서 A가 나오는 위치
    while(lb>=0 && t[lb]=='A'){
        if(s[lb]=='B') flag=0;
        lb--;
    }

    //cout<<"f l "<<fa<<' '<<lb<<'\n';
    if(!flag){
        cout<<-1<<'\n';
        return;
    }
    assert(fa<n && lb>=0);
    int diffa=0, diffb=0, AB=0;
    int bcnt=0;
    rng(i,fa,lb){
        if(s[i]!=t[i]){
            if(s[i]=='A') diffa++;
            else diffb++;

            if(s[i]=='B'){
                bcnt++;
            }
            else if(bcnt>0 && s[i]=='A'){
                AB++;
                bcnt--;
            }
        }
    }
    // if(diffa==AB && diffb==AB){
    //     cout<<diffa+diffb-AB+(s[lb]=='A')+(s[fa]=='B')-(s[fa]=='B' && s[lb]=='A')<<'\n';
    // }
    // else if(diffa==AB && diffb>AB){
    //     cout<<diffa+diffb-AB+(s[fa]=='B')<<'\n';
    // }
    // else if(diffa>AB && diffb==AB){
    //     cout<<diffa+diffb-AB+(s[lb]=='A')<<'\n';
    // }
    // else{
    //     cout<<diffa+diffb-AB<<'\n';
    // }
    cout<<diffa+diffb-AB<<'\n';
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

