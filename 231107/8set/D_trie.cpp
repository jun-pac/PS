// 
//./D<test

#include <bits/stdc++.h>
//#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int a[200020], b[200020];

#define NUM_ALPHA 2

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
    int find_mx(string &s){
        return find_mx_re(root, 0, s);
    }

private: 
    bool is_re(node *cur, int idx, string &s){
        if(idx==s.size()) return ((cur->cnt)>=1); // 여기까지 왔으면 그냥 true해도 되지 않나? 처음에 들어올 때 때문인가
        if((cur->next[s[idx]-'0'])==NULL) return false;
        return is_re(cur->next[s[idx]-'0'],idx+1,s);
    }
    void insert_re(node* cur, int idx, string &s){
        if(idx==s.size()){
            cur->cnt++;
            return;
        }
        if((cur->next[s[idx]-'0'])==NULL) cur->next[s[idx]-'0']=new node(s[idx]);
        insert_re(cur->next[s[idx]-'0'],idx+1,s);
    }
    int find_mx_re(node* cur, int idx, string &s){
        if(idx==s.size()) return 0;
        int res=0;
        if(cur->next['1'-s[idx]]==NULL) return find_mx_re(cur->next[s[idx]-'0'],idx+1,s);
        else return (1<<(19-idx))+find_mx_re(cur->next['1'-s[idx]],idx+1,s);
    }
};

trie tr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++) cin>>a[i];
    for(int i=0; i<n; i++) b[i]=(i==0?0:a[i-1]^b[i-1]);
    for(int i=0; i<n; i++){
        string temp;
        int num=b[i];
        for(int j=0; j<20; j++){
            temp.push_back(num%2+'0');
            num/=2;
        }
        reverse(temp.begin(), temp.end());
        tr.insert_s(temp);
    }
    for(int i=0; i<n; i++){
        // trie에서 i랑 비볐을 때 가장 커지는 애를 찾아서 뙇!
        string temp;
        int num=i;
        for(int j=0; j<20; j++){
            temp.push_back(num%2+'0');
            num/=2;
        }
        reverse(temp.begin(), temp.end());
        int mx=tr.find_mx(temp);
        if(mx<n){
            for(int j=0; j<n; j++) cout<<(i^b[j])<<' ';
            cout<<endl;
            break;
        }
    }
    return 0;
}