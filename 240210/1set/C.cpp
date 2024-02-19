
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

string s;

void Solve(){
    cin>>s;
    int n=s.size();
    int op=0, cl=0;
    rng(i,0,n-1){
        if(s[i]=='(') op++;
        else if(s[i]==')') cl++;
    } 
    int qs=n-op-cl;
    if(n%2==1){
        cout<<"NO\n";
        return;
    }
    int numo=(qs-op+cl)/2; // ?중에서 open의 개수
    if(numo<0 || numo>qs){
        cout<<"NO\n";
        return;
    }

    int cnt=0;
    int cur=0;
    bool flag=1;
    rng(i,0,n-1){
        if(s[i]=='(') cur++;
        else if(s[i]==')') cur--;
        else{
            if(cnt<numo) cur++;
            else cur--;
            cnt++;
        }
        if(cur<0) flag=0;
    }
    if(!flag){
        cout<<"NO\n";
        return;
    }
    if(numo==0 || numo==qs){
        cout<<"YES\n";
        return;
    }

    flag=0;
    cur=0;
    cnt=0;
    rng(i,0,n-1){
        if(s[i]=='(') cur++;
        else if(s[i]==')') cur--;
        else{
            if(cnt==numo-1) cur--;
            else if(cnt==numo) cur++;
            else if(cnt<numo) cur++;
            else cur--;
            cnt++;
        }
        if(cur<0) flag=1;
    }
    cout<<(flag?"YES\n":"NO\n");
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

