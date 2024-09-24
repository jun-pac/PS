
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

int datas[N];
// 가장 작은 XOR이란 자고로, 앞에서 가장 많이 겹치는 형태여야 하고, 첫 1이 등장하는 시점이 최대한 뒤에.
// 사실 앞에서부터 가장 비슷한 것 찾기.
// 어 이거 완전 trie아닌가?

// K=001001101
// A와 합*체해서 K가 되는 값은 B=A^K
// 근데 이제 K'=000******, 001000***, 00100010**, 001001100 가 더 작아지는 후보임
// 최대 31가지만 확인하면 된다.
// 이런 것들이 있는지는 trie로 빠르게 확인가능.
// 이런 것들이 어디 있는지? 가장 가까운 게 어디인지?
// 사이에 있는지? 를 알아야 하는데 말이죠...
// Mo's로 trie에다가 넣고 빼는 방식이면 안되나?
// mx, mn은 알 수 있을지 몰라도 어떤 지점과 가장 가까운 게 어딘지는 모르는 게 당연하니까
// 이걸 small to large로? array를 맨들어서 upperbound, lowerbound로 되지 않나

// 이게 나와의 교점이 문제가 아니라, 그 사이에 다른 원소들이 말썽을 일으킬수가 있음.
// 그냥 각각의 원소에 대해서 XOR이 K'중 하나가 되는 가장 가까운 아이를 찾으면 될 듯

// 이건 사실 trie를 안쓰고 정렬해서 lower upper bound로 찾으면 되는거긴함
// 그리고 seg로 좌우 idx구하고. 아닌가 
// 근데 A^B in K' 이고 B^C in K'이면 A^C in K'임
// 
// 그니까 trie가 있으면 나보다 작거나 큰 값이 있는지 log n)^2만에 알 수 있음.
// 근데 생각해보니까 정렬이 돼있으면 이분탐색해서 할 수 있지 않나
// set으로 관리하면 어떤가

int merge_seg[4*10000];
int l_bound[N], r_bound[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        rng(j,0,n-1){
            int temp=datas[i]^datas[j];
            if(temp==k){

            }
            else if(temp<k){
                
            }
        }
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

