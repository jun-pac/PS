
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

set<int> ans;

void Solve(){
    ans.clear();
    int pos,num;
    cin>>pos>>num; //pos>num이다. 이 조건은 왜 필요함?
    // 아 pos==num이면 무한히 많은 거대한 k들이 가능한고로...
    // pos는 1 based 
    // k >= num && k < pos
    
    
    // 인생은 오르막길
    int c1=pos-num; // c1의 약수 중 num이상인 것의 개수
    int cnt1=0;
    for(int i=1; i<=sqrt(c1)+1; i++){
        if(c1%i!=0) continue;
        int temp=i;
        if(temp%2==0 && (temp+2)/2>=num && ans.find((temp+2)/2)==ans.end()) ans.insert((temp+2)/2);
        temp=c1/i;
        if(temp%2==0 && (temp+2)/2>=num && ans.find((temp+2)/2)==ans.end()) ans.insert((temp+2)/2);
    }

    // 인생은 내리막길
    int c2=pos+(num-2); // 여기서 얻는 k는 num보다 커야 함.
    int cnt2=0;
    for(int i=1; i<=sqrt(c2)+1; i++){
        if(c2%i!=0) continue;
        int temp=i;
        if(temp%2==0 && (temp+2)/2>num && ans.find((temp+2)/2)==ans.end()) ans.insert((temp+2)/2);
        temp=c2/i;
        if(temp%2==0 && (temp+2)/2>num && ans.find((temp+2)/2)==ans.end()) ans.insert((temp+2)/2);
    }

    cout<<ans.size()<<'\n';
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

