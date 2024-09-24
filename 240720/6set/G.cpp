
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
#define NUM_ALPHA 26

class node{
public:
    node* next[NUM_ALPHA]={NULL,};
    node* pphi; // parent of phi ; i.e. 최대 접미사의 가장 마지막 노드. 다음 원소는 직접 찾아야 함.
    int val; // 부모를 통해 찾아줘도 된다. // 0-based idx of character
    bool end_of_snippet=false; // End node of snippet. Propagated in BFS phase.
    int length_of_snippet; // Only valid of end of snippet is true. Propagated in BFS phase.
    int depth=0; // Actual length of the sequence
    int ori_idx;
    bool end=true; // All next pointers are NULL
    node(){}
    node(int v){
        val=v; 
    }
};

int ans[500050];

class aho_trie{
public:
    node* root= new node();
    aho_trie(){}
    bool is_s(string &s){
        return is_re(root, 0, s);
    }
    void insert_s(string &s, int ori_idx){
        insert_re(root, 0, s, ori_idx);
    }
    void clear(){ // clear_all
        clear_re(root);
        for(int i=0; i<NUM_ALPHA; i++) root->next[i]=NULL;
    }
    void get_phi(){
        queue<pair<node*,node*>> phi_q; // cur_pos, pphi
        phi_q.push({root,root});
        while(!phi_q.empty()){
            pair<node*,node*> temp=phi_q.front();
            phi_q.pop();
            node* cur=temp.first;
            node* ptar=temp.second;
            if(cur->depth>1){ // To prevent phi[self]=self
                while(ptar!=root && (ptar->next[cur->val]==NULL)) ptar=ptar->pphi;
                if(ptar->next[cur->val]!=NULL) ptar=ptar->next[cur->val];
            }
            cur->pphi=ptar;
            if(!cur->end_of_snippet && ptar->end_of_snippet){
                cur->end_of_snippet=true;
                cur->length_of_snippet=ptar->length_of_snippet;
            }

            for(int i=0; i<NUM_ALPHA; i++){
                if((cur->next[i])!=NULL){
                    phi_q.push({cur->next[i],ptar});
                }
            }
        }
    }
    void find_matching(string &s_ref){
        int n=s_ref.size();
        node* ptar=root;
        for(int i=0; i<n; i++){
            int cur=s_ref[i]-'a'; // transition function
            while(ptar!=root && ptar->next[cur]==NULL) ptar=ptar->pphi;
            if(ptar->next[cur]!=NULL){
                ptar=ptar->next[cur];
                if(ptar->end_of_snippet) ans[ptar->ori_idx]++;
            }
            //cout<<(char)(ptar->val+'a')<<' '<<ptar->cnt<<' '<<ptar->depth<<endl;
            //if(ptar->end_of_snippet) ans[ptar->ori_idx]++;
            if(ptar->end) ptar=ptar->pphi;
        }
    }

private: 
    bool is_re(node *cur, int idx, string &s){
        if(idx==s.size()) return (cur->end_of_snippet);
        if((cur->next[s[idx]-'a'])==NULL) return false;
        return is_re(cur->next[s[idx]-'a'],idx+1,s);
    }
    void insert_re(node* cur, int idx, string &s, int ori_idx){
        if(idx==s.size()){
            cur->end_of_snippet=true;
            cur->length_of_snippet=s.size();
            cur->ori_idx=ori_idx;
            return;
        }
        cur->end=false;
        if((cur->next[s[idx]-'a'])==NULL){
            cur->next[s[idx]-'a']=new node(s[idx]-'a');
            cur->next[s[idx]-'a']->depth=idx+1;
        }
        insert_re(cur->next[s[idx]-'a'],idx+1,s,ori_idx);
    }
    void clear_re(node* cur){
        for(int i=0; i<NUM_ALPHA; i++){
            if((cur->next[i])!=NULL){
                clear_re(cur->next[i]);
                delete cur->next[i];
            }
        }
    }
};

aho_trie aho;

void Solve(){ 
    string s,t;
    cin>>s;
    int q;
    cin>>q;
    rng(i,0,q-1){
        cin>>t;
        aho.insert_s(t,i);
    }
    aho.get_phi();
    aho.find_matching(s);
    rng(i,0,q-1) cout<<ans[i]<<'\n';
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

