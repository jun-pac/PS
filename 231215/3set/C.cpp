
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

string s, l, r;
int DP[300030][10]; //당신 포함 가장 가까이있는 i값을 찾아라. 없으면 -1

void Solve(){
    cin>>s;
    int n; // (n<=10)
    cin>>n;
    cin>>l;
    cin>>r;
    int m=s.size();
    gnr(i,m-1,0){
        rng(j,0,9) DP[i][j]=(i==m-1?-1:DP[i+1][j]);
        DP[i][s[i]-'0']=i;
    }
    // rng(i,0,9){
    //     rng(j,0,m-1) cout<<DP[j][i]<<' ';
    //     cout<<'\n';
    // }
    // matching자체는 greedy임. m seg의 앞에서부터 등장하면? 지운다.
    // 그렇다면 언제나 best solution이 정해짐. l_i <= a_i <= r_i중에서 a_i는 가장 뒤에서 가능한 매칭이 나오는.

    int cur=0; // 현재 매칭의 지시점 // 가장 멀리 보낼 수 있는데로 집중하세요
    rng(i,0,n-1){
        int mxcur=cur;
        //cout<<"idx "<<i<<'\n';
        if(cur>=m){
            //cout<<"this?"<<'\n';
            cout<<"YES"<<'\n';
            return;
        }
        for(int j=l[i]-'0'; j<=r[i]-'0'; j++){
            //cout<<j<<' ';
            if(DP[cur][j]==-1){
                //cout<<"here? "<<cur<<' '<<j<<'\n';
                cout<<"YES"<<'\n';
                return;
            }
            mxcur=max(mxcur,DP[cur][j]+1);
        }
        cur=mxcur;
    }
    cout<<"NO"<<'\n';
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

