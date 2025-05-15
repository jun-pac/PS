
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

stack<int> s1,s2,s3;

void Solve(){
    string s;
    cin>>s;
    int n=s.size();
    s1.push(-1);
    s2.push(-1);
    s3.push(-1);
    bool flag=1;
    rng(i,0,n-1){
        if(s[i]=='('){
            s1.push(i);
        }
        else if(s[i]==')'){
            if(s1.size()==1 || !(s1.top()>s2.top() && s1.top()>s3.top())){
                flag=0;
                break;
            } 
            s1.pop();
        }
        else if(s[i]=='['){
            s2.push(i);
        }
        else if(s[i]==']'){
            if(s2.size()==1 || !(s2.top()>s1.top() && s2.top()>s3.top())){
                flag=0;
                break;
            } 
            s2.pop();
        }
        else if(s[i]=='<'){
            s3.push(i);
        }
        else if(s[i]=='>'){
            if(s3.size()==1 || !(s3.top()>s2.top() && s3.top()>s1.top())){
                flag=0;
                break;
            } 
            s3.pop();
        }
    }
    if(flag && (s1.size()==1 && s2.size()==1 && s3.size()==1)) cout<<"Yes\n";
    else cout<<"No\n";

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

