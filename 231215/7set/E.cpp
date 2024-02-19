
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 

string ss[N];

#define NUM_ALPHA 26

class node{
public:
    node* next[NUM_ALPHA]={NULL,};
    char val; // 대부분 필요없다.
    int cnt=0; // 여기서 끝나는 단어들의 개수
    node(){}
    node(char c){
        val=c; 
    }
};


class trie{
public:
    node* root= new node();
    trie(){}
    bool is_s(string &s){
        return is_re(root, 0, s);
    }
    void insert_s(string &s){
        insert_re(root, 0, s);
    }
    ll get_s(string &s){
        return get_re(root,0,s,s.size());
    }

private: 
    bool is_re(node *cur, int idx, string &s){
        if(idx==s.size()) return ((cur->cnt)>=1); // 여기까지 왔으면 그냥 true해도 되지 않나? 처음에 들어올 때 때문인가
        if((cur->next[s[idx]-'a'])==NULL) return false;
        return is_re(cur->next[s[idx]-'a'],idx+1,s);
    }
    void insert_re(node* cur, int idx, string &s){
        if(idx==s.size()){
            return;
        }
        if((cur->next[s[idx]-'a'])==NULL) cur->next[s[idx]-'a']=new node(s[idx]);
        cur->next[s[idx]-'a']->cnt++;
        insert_re(cur->next[s[idx]-'a'],idx+1,s);
    }
    ll get_re(node* cur, int idx, string &s, int n){
        ll res=0;
        if(idx==s.size()) return res;
        if((cur->next[s[n-1-idx]-'a'])==NULL) return res;
        res=res+(ll)(cur->next[s[n-1-idx]-'a']->cnt);
        res+=get_re(cur->next[s[n-1-idx]-'a'],idx+1,s,n);
        return res;
    }
};

trie tr;

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>ss[i];
    rng(i,0,n-1) tr.insert_s(ss[i]);
    ll res=0;
    rng(i,0,n-1) res+=ss[i].size();
    res=res*2*n;

    ll ddec=0;
    rng(i,0,n-1) ddec+=tr.get_s(ss[i]);
    cout<<res-ddec*2<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}
