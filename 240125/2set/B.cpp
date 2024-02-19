
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

ll datas[N];

void Solve(){
    ll n,k,b,s;
    cin>>n>>k>>b>>s; // ���� s. b�� k�� ���� ����� ��
    // b*k<=s<b*k+(k-1)*n
    fill(datas,datas+n,0);
    if(b*k<=s && s<=b*k+(k-1)*n){
        ll res=s-b*k;
        datas[0]=b*k;
        rng(i,0,n-1){
            if(res>=k){
                datas[i]+=k-1;
                res-=k-1;
            }
            else{
                datas[i]+=res;
                res=0;
            }
            if(res==0) break;
        }
        rng(i,0,n-1) cout<<datas[i]<<' '; cout<<'\n';
    }
    else cout<<-1<<'\n';
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

