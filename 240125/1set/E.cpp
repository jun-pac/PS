
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
    int h,w,xa,ya,xb,yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;
    if(xa>=xb){
        cout<<"Draw\n";
    }
    else if((xb-xa)%2==1){
        // alice의 공격
        if(abs(ya-yb)<=1) cout<<"Alice\n";
        else if(ya<yb && ya+(xb-xa+1)/2>=w) cout<<"Alice\n";
        else if(ya>yb && ya-((xb-xa+1)/2)<=1) cout<<"Alice\n";
        else cout<<"Draw\n";
    }
    else{
        // bob의 공격
        if(ya==yb) cout<<"Bob\n";
        else if(ya<yb && yb-(xb-xa)/2<=1) cout<<"Bob\n";
        else if(ya>yb && yb+((xb-xa)/2)>=w) cout<<"Bob\n";
        else cout<<"Draw\n";
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

