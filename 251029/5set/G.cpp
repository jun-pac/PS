
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

string s;
ll numlb[N], sumlb[N];
ll numrb[N], sumrb[N];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1){
        numlb[i]=(i==0?0:numlb[i-1])+(s[i]=='<');
        sumlb[i]=(i==0?0:sumlb[i-1])+(s[i]=='<'?i:0);
        numrb[i]=(i==0?0:numrb[i-1])+(s[i]=='>');
        sumrb[i]=(i==0?0:sumrb[i-1])+(s[i]=='>'?i:0);
    }
 
    ll lres=0, rres=0;
    rng(i,0,n-1){
        ll leftb=numlb[n-1]-numlb[i]; // # of '<' in the right side
        ll rightb=(i==0?0:numrb[i-1]); // # of '>' in the left side
        // cout<<"lr "<<leftb<<' '<<rightb<<'\n';

        if(s[i]=='>'){
            if(leftb==0){
                rres=n-i;
                lres=0;
            }
            else if(leftb<=rightb){
                // escape to the right side
                // find the position of the leftb-th '>' from the i position
                ll tarnum=(i==0?0:numrb[i-1])-leftb+1;
                ll endpos=lower_bound(numrb, numrb+n, tarnum)-numrb;
                // cout<<'i'<<' '<<endpos<<' '<<s[i]<<'\n';
                rres=(sumlb[n-1]-sumlb[i] - leftb*i)*2+(n-i);
                assert(leftb==((i==0?0:numrb[i-1])-(endpos==0?0:numrb[endpos-1])));
                lres=(i*leftb-((i==0?0:sumrb[i-1])-(endpos==0?0:sumrb[endpos-1])))*2;
            }
            else{
                // escape to the left side
                // >'>'< < <<
                ll tarnum=numlb[i]+rightb+1;
                // cout<<"tar "<<tarnum<<'\n';
                ll endpos = lower_bound(numlb, numlb+n, tarnum)-numlb;
                // cout<<i<<' '<<endpos<<' '<<s[i]<<'\n';
                rres = (sumlb[endpos]-sumlb[i]-(rightb+1)*i)*2;
                assert(rightb==(i==0?0:numrb[i-1]));
                lres = (i*rightb-(i==0?0:sumrb[i-1]))*2 + i+1;

                // cout<<"ree "<<rres<<' '<<lres<<'\n';
            }
        }
        else{
            if(rightb==0){
                rres=0;
                lres=i+1;
            }
            else if(leftb<rightb){
                // escape to the right side
                // find the position of the leftb-th '>' from the i position
                ll tarnum=(i==0?0:numrb[i-1])-(leftb+1)+1;
                ll endpos=lower_bound(numrb, numrb+n, tarnum)-numrb;
                // cout<<'i'<<' '<<i<<' '<<endpos<<' '<<s[i]<<'\n';
                rres=(sumlb[n-1]-sumlb[i] - (leftb)*i)*2+(n-i);
                // cout<<"rrs "<<rres<<'\n';
                assert(leftb+1==((i==0?0:numrb[i-1])-(endpos==0?0:numrb[endpos-1])));
                lres=(i*(leftb+1)-((i==0?0:sumrb[i-1])-(endpos==0?0:sumrb[endpos-1])))*2;
            }
            else{
                // escape to the left side
                // >'>'< < <<
                ll tarnum=numlb[i]+rightb;
                // cout<<"tar "<<tarnum<<'\n';
                ll endpos = lower_bound(numlb, numlb+n, tarnum)-numlb;
                // cout<<i<<' '<<endpos<<' '<<s[i]<<'\n';
                rres = (sumlb[endpos]-sumlb[i]-(rightb)*i)*2;
                assert(rightb==(i==0?0:numrb[i-1]));
                lres = (i*rightb-(i==0?0:sumrb[i-1]))*2 + i+1;

                // cout<<"ree "<<rres<<' '<<lres<<'\n';
            }
        }
        cout<<rres+lres<<' ';

        
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

