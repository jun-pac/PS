
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

queue<int> q;

void Solve(){
    int n;
    cin>>n;
    int win=0;
    // endl
    while(!q.empty()) q.pop();
    rng(i,0,(1<<n)-1) q.push(i+1);
    while(q.size()>=4){
        int a,b,c,d,res;
        a=q.front(); q.pop();
        b=q.front(); q.pop();
        c=q.front(); q.pop();
        d=q.front(); q.pop();
        cout<<"? "<<a<<' '<<c<<endl;
        cin>>res;
        if(res==0){
            cout<<"? "<<b<<' '<<d<<endl;
            cin>>res;
            win=(res==1?b:d);
        }
        else if(res==1){ // a>c
            cout<<"? "<<a<<' '<<d<<endl;
            cin>>res;
            win=(res==1?a:d);
        }
        else{
            cout<<"? "<<b<<' '<<c<<endl;
            cin>>res;
            win=(res==1?b:c);
        }
        q.push(win);
    }
    assert(q.size()==1 || q.size()==2);
    if(q.size()==2){
        int a=q.front(); q.pop();
        int b=q.front(); q.pop();
        int res;
        cout<<"? "<<a<<' '<<b<<endl;
        cin>>res;
        win=(res==1?a:b);
    }
    cout<<"! "<<win<<endl;
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