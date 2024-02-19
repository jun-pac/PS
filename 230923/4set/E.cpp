// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}


#define MOD 998244353LL
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(ll i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

ll datas[200020];



class node{
public:
    node* next[2]={NULL,};
    ll val;
    ll cnt=0; // 여기서 끝나는 단어들의 개수
    node(){}
    node(ll c){
        val=c; 
    }
};

class trie{
public:
    node* root= new node();
    trie(){}
    void insert_s(ll s){
        insert_re(root, 0, s);
    }
    void clear(){ // clear_all
        clear_re(root);
        for(ll i=0; i<2; i++) root->next[i]=NULL;
    }
    ll DFS(){
        return DFS_re(root).fi;
    }
    ll DFS2(){
        return DFS2_re(root);
    }

private: 
    void insert_re(node* cur, ll idx, ll s){
        if(idx==31){
            cur->cnt++;
            return;
        }
        ll temp=(((1LL<<(30-idx))&s)==0?0:1);
        if((cur->next[temp])==NULL){
            cur->next[temp]=new node(temp);
        }
        insert_re(cur->next[temp],idx+1,s);
    }
    void clear_re(node* cur){
        for(ll i=0; i<2; i++){
            if((cur->next[i])!=NULL){
                clear_re(cur->next[i]);
                delete cur->next[i];
            }
        }
    }
    pair<ll,ll> DFS_re(node* cur){
        ll sz=cur->cnt;
        ll res=0;
        for(ll i=0; i<2; i++){
            if((cur->next[i])!=NULL){
                auto temp=DFS_re(cur->next[i]);
                sz+=temp.se;
                res+=temp.fi;
            }
        }
        //cout<<sz<<' '<<(cur->val)<<endl;
        if((cur->val)==1) res=(res+sz*sz)%MOD;
        return make_pair(res,sz);
    }
    ll DFS2_re(node* cur){
        ll res=0;
        for(ll i=0; i<2; i++){
            if((cur->next[i])!=NULL){
                ll temp=DFS2_re(cur->next[i]);
                res=(res+temp)%MOD;
            }
        }
        //cout<<sz<<' '<<(cur->val)<<endl;
        res=(res+(cur->cnt)*(cur->cnt))%MOD;
        return res;
    }
};
// 억측이 아닌가

trie tr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++){
            cin>>datas[i];
        }

        if(n==-1) cout<<1<<endl;
        else{
            // build trie;
            tr.clear();
            for(ll i=0; i<n; i++) tr.insert_s(datas[i]);

            ll res=n*n;
            // trie의 각 노드에서 subtree크기 만큼을 제곱해서 더한다.
            res+=tr.DFS();
            res+=(n*n-tr.DFS2())/2;
            ll k=ari_inv(n)%MOD;
            ll ans=((res*(k*k%MOD)%MOD)+MOD)%MOD;
            cout<<ans<<endl;
        }
    }
    return 0;
}