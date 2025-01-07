
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

string s;
string res, mxres;

void Solve(){
    cin>>s;
    int n;
    n=s.size();
    int l1,r1,l2,r2;
    int idx=0; 
    while(idx<n && s[idx]=='0') idx++;
    if(idx==n){
        // any 
        cout<<1<<' '<<1<<' '<<1<<' '<<1<<endl;
        return;
    }
    l1=idx, r1=n-1;

    // idx+1 부터 n까지 중, 처음으로 0이 나오면 그걸 1로 바꿔야 함.
    int cur=idx+1;
    int len=-1;
    while(cur<n){
        if(s[cur]=='1'){
            cur++;
        }
        else{
            // 애초에 idx가 1이라서 무조건 바꿀 수는 있음. -> 길이 fix
            len = n-1-cur+1;
            break;
        }
    }
    if(len==-1){
        // 1이 없었다
        l2=r2=0;
        cout<<l1+1<<' '<<r1+1<<' '<<l2+1<<' '<<r2+1<<endl; // all 1이어도 하나는 희생해야 함.
        return;
    }
    // len이 정해짐. s[l2]='1'이고 그 중에서도 가장 값이 큰 것을 찾아야 함.
    
    mxres.clear(); // 아래 len개만 비교하면 됨.
    rng(i,0,len-1) mxres.pb((s[cur+i]==s[idx+i]?'0':'1'));
    int mxl=idx;
    rng(j,idx,n-len){
        res.clear();
        rng(i,0,len-1) res.pb((s[cur+i]==s[j+i]?'0':'1'));
        // cout<<mxres<<' '<<res<<' '<<(res>mxres)<<endl;
        if(res>mxres){
            swap(res,mxres);
            mxl=j;
        }
        
    }
    cout<<l1+1<<' '<<r1+1<<' '<<mxl+1<<' '<<mxl+len<<endl;
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

