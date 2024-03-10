
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

#define N M030
#define MOD 998244353
#define INF 1000000007 
#define NUM_ALPHA 10
#define M 100

string datas[505];
int k;

class node{
public:
    node* next[NUM_ALPHA]={NULL,};
    char val; // 대부분 필요없다.
    int cnt=0, ccnt=0; // 여기서 끝나는 단어들의 개수
    node(){}
    node(char c){
        val=c; 
    }
};

class trie{
public:
    node* root= new node();
    trie(){}
    int is_s(string &s){
        return is_re(root, 0, s);
    }
    void insert_s(string &s){
        insert_re(root, 0, s);
    }
    void clear(){ // clear_all
        clear_re(root);
        for(int i=0; i<NUM_ALPHA; i++) root->next[i]=NULL;
    }

private: 
    int is_re(node *cur, int idx, string &s){
        if(idx==s.size()) return ((cur->cnt)); // 여기까지 왔으면 그냥 true해도 되지 않나? 처음에 들어올 때 때문인가
        if((cur->next[s[idx]-'0'])==NULL) return -1;
        return is_re(cur->next[s[idx]-'0'],idx+1,s);
    }
    void insert_re(node* cur, int idx, string &s){
        if(idx==s.size()){
            cur->cnt++;
            return;
        }
        //cur->cnt++;
        cur->ccnt++;
        if((cur->next[s[idx]-'0'])==NULL) cur->next[s[idx]-'0']=new node(s[idx]);
        insert_re(cur->next[s[idx]-'0'],idx+1,s);
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

trie tr;

void check_all_nine(string &res){
    bool is_all_k=1;
    rng(i,0,k-1) if(res[i]!='9') is_all_k=0;
    if(is_all_k){
        rng(i,0,k-1) res[i]='0';
    }
}

void add_mod_k(string &a, string &b){
    assert(a.size()==k);
    //string res;
    //res.resize(k,'0');
    int carry=0;
    int an=a.size();
    int bn=b.size();
    //assert(an<=k && bn<=k);

    rng(i,0,k-1){
        int temp=(i>=an?'0':a[k-1-i])-'0'+(i>=bn?'0':b[bn-1-i])-'0'+carry;    
        carry=temp/10;
        temp=temp%10;
        a[k-1-i]=(temp+'0');
    }
    //cout<<"tempres "<<res<<'\n';
    if(carry==0) check_all_nine(a);
    else{
        string c;
        c.pb('1');
        return add_mod_k(a,c);
    }
}

string mod_k(string &a){
    int an=a.size();
    if(an<=k){
        check_all_nine(a);
        return a;
    } 
    string res=a.substr(an-k,k);
    int last=an-k;
    int cur=max(0,an-2*k);
    while(true){
        //cout<<"cut : "<<cur<<' '<<last-1<<'\n';
        string b=a.substr(cur,last-cur);
        //cout<<"add "<<res<<' '<<b<<' ';
        add_mod_k(res,b);
        //cout<<res<<'\n';
        last=max(0,last-k);
        cur=max(0,cur-k);
        if(last==cur) break;
    }
    return res;
}

string sumM(string &a, string &b){
    string res;
    res.reserve(min(k,M));
    int carry=0;
    rng(i,0,min(k,M)-1){
        int temp=a[k-1-i]-'0'+b[k-1-i]-'0'+carry;    
        carry=temp/10;
        temp=temp%10;
        res.pb('9'-temp);
    }
    return res;
}

void Solve(){
    int n;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];

    int res=0;
    rng(i,0,n-1){
        datas[i]=mod_k(datas[i]);
        assert(datas[i].size()<=k);
        //cout<<"MOD K : "<<datas[i]<<'\n';
        //reverse(all(datas[i]));
    }
    string zerozero;

    rng(i,0,n-1){
        string temp=datas[i];
        reverse(all(temp));
        while(!temp.empty() && temp.back()=='0') temp.pop_back();
        tr.insert_s(temp);
        
        rng(j,i,n-1){
            string tempsum=sumM(datas[i],datas[j]);
            while(!tempsum.empty() && tempsum.back()=='0') tempsum.pop_back();
            bool is_all_nine=1;
            rng(t,0,(int)tempsum.size()-1) if(tempsum[t]!='9') is_all_nine=0;
            if(!(tr.is_s(tempsum)!=-1 || (is_all_nine && tr.is_s(zerozero)!=-1))) continue;

            string twosome=datas[j];
            add_mod_k(twosome,datas[i]);
            rng(i,0,k-1){
                twosome[i]=('9'+'0'-twosome[i]);
            }
            check_all_nine(twosome);
            reverse(all(twosome));
            while(!twosome.empty() && twosome.back()=='0') twosome.pop_back();
            //assert(kminus.size()<=k);
            //cout<<"target "<<i<<' '<<j<<' '<<twosome<<' '<<tr.is_s(twosome)<<'\n';
            res+=tr.is_s(twosome);
        }
    }
    cout<<res<<'\n';
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

