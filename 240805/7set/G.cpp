
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

string s;
char dir[]={'L','U','R','D'};
int cton[26];
string ns; // new s
vc<pii> ans;

void Solve(){
    cin>>s;
    int n=s.size();
    if(s[n-1]=='L'||s[n-1]=='R'){
        int last=n-1;
        while(last>=0){
            if(s[last]=='L'||s[last]=='R') last--;
            else break;
        }
        int num=n-1-(last+1)+1;
        if(num>=3){
            cout<<"impossible\n";
            return;
        }
    }
    else if(s[n-1]=='U'||s[n-1]=='D'){
        int last=n-1;
        while(last>=0){
            if(s[last]=='U'||s[last]=='D') last--;
            else break;
        }
        int num=n-1-(last+1)+1;
        if(num>=3){
            cout<<"impossible\n";
            return;
        }
    }
    
    rng(i,1,n-1){
        //cout<<s[i]<<' '<<cton[s[i]]<<'\n';
        if(cton[s[(i-1)]-'A']%2!=cton[s[i]-'A']%2){
            ns.pb(s[i-1]);
        }
    }
    ns.pb(s[n-1]);
    int m=ns.size();
    //cout<<"p1 "<<ns<<'\n';
    reverse(ns.begin(),ns.end());
    //cout<<"p2 "<<ns<<'\n';
    rng(i,0,m-1) ns[i]=dir[(cton[ns[i]-'A']+2)%4];
    //cout<<"p3 "<<ns<<'\n';
    //ans.pb({0,0});
    pii last={0,0};
    rng(i,0,m-2){
        if(ns[i]=='L'){
            ans.pb({-(1<<(i+1)),last.se+(ns[i+1]=='D'?1:-1)});
            last={-(1<<(i+1)),last.se+(ns[i+1]=='D'?1:-1)};
        }
        if(ns[i]=='R'){
            ans.pb({(1<<(i+1)),last.se+(ns[i+1]=='D'?1:-1)});
            last={(1<<(i+1)),last.se+(ns[i+1]=='D'?1:-1)};
        }
        if(ns[i]=='D'){
            ans.pb({last.fi+(ns[i+1]=='L'?1:-1),-(1<<(i+1))});
            last={last.fi+(ns[i+1]=='L'?1:-1),-(1<<(i+1))};
        }
        if(ns[i]=='U'){
            ans.pb({last.fi+(ns[i+1]=='L'?1:-1),(1<<(i+1))});
            last={last.fi+(ns[i+1]=='L'?1:-1),(1<<(i+1))};
        }
    }
    int i=m-1;
    if(ns[i]=='L'){
        ans.pb({-(1<<(i+1)),last.se});
        last={-(1<<(i+1)),last.se};
    }
    if(ns[i]=='R'){
        ans.pb({(1<<(i+1)),last.se});
        last={(1<<(i+1)),last.se};
    }
    if(ns[i]=='D'){
        ans.pb({last.fi,-(1<<(i+1))});
        last={last.fi,-(1<<(i+1))};
    }
    if(ns[i]=='U'){
        ans.pb({last.fi,(1<<(i+1))});
        last={last.fi,(1<<(i+1))};
    }
    reverse(ans.begin(), ans.end());
    int cnt=0;
    for(auto temp : ans){
        cout<<temp.fi<<' '<<temp.se<<'\n';
        if(cnt==0) cout<<ans.size()-1<<'\n';
        cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    cton['L'-'A']=0;
    cton['U'-'A']=1;
    cton['R'-'A']=2;
    cton['D'-'A']=3;

    while(t--){
        Solve();
    }
    return 0;
}

