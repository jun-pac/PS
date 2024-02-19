
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
int C[200];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    // CV나 CVC
    C['a']=0, C['b']=1, C['c']=1, C['d']=1, C['e']=0;
    //cout<<"idx "<<n<<'\n';
    int i=0;
    while(i<n){
        // s[i] : C, s[i+1] : V가 보장이 되었다고 생각하자
        if(i+2>=n){
            //cout<<i<<' '<<i+1<<'\n';
            cout<<s.substr(i,2);
            i+=2;
        }
        else if(i+3>=n){
            // s[i+2]가 존재하면 C임
            //cout<<i<<' '<<i+2<<'\n';
            cout<<s.substr(i,3);
            i+=3;
        }
        else if(C[s[i+3]]==1){
            // CVCC
            //cout<<i<<' '<<i+2<<'\n';
            cout<<s.substr(i,3)<<'.';
            i+=3;
        }
        else{
            // CVCV
            //cout<<i<<' '<<i+1<<'\n';
            cout<<s.substr(i,2)<<'.';
            i+=2;
        }
    } 
    cout<<'\n';

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

