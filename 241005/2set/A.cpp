
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define pb push_back
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); 



bool digit_start(int idx, int n, string &s){
    return (idx==0)||((0<=s[idx]-'0' && s[idx]-'0'<=9)&&!(0<=s[idx-1]-'0' && s[idx-1]-'0'<=9));
}
bool digit_end(int idx, int n, string &s){
    return (idx==n-1)||((0<=s[idx]-'0' && s[idx]-'0'<=9)&&!(0<=s[idx+1]-'0' && s[idx+1]-'0'<=9));
}

string DFS(string s){
    //cout<<"s : "<<s<<'\n';
    int last=-1;
    bool flag=0; // 현재 X를 처리하고 있는지
    string res;
    string cur;
    int n=s.size();
    for(int i=0; i<=n-1; i++){
        if(s[i]=='('){
            int l=i, r=i;
            int cnt=0;
            while(r<n){
                cnt+=(s[r]=='('?1:(s[r]==')'?-1:0));
                if(cnt==0) break;
                r++;
            }
            i=r;
            //assert(r-l-1>0);
            cur="("+(r-l-1>0?DFS(s.substr(l+1,r-l-1)):"")+")";
        } 
        else if(digit_start(i,n,s)){
            int l=i, r=i;
            while(r<n){
                if(digit_end(r,n,s)) break;
                r++;
            }
            i=r;
            //assert(r-l-1>0);
            cur=s.substr(l,r-l+1);
        }
        else{
            if(s[i]=='*' && !flag){
                flag=1;
                res+="("+cur+"*";
            }
            else if(s[i]=='+' && flag){
                flag=0;
                res+=cur+")"+"+";
            }
            else if(s[i]=='*' && flag){
                res+=cur+"*";
            }
            else{
                res+=cur+"+";
            }
        }
    }
    if(flag) res+=cur+")";
    else res+=cur;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,p;
    string s;
    cin>>n>>p;
    cin>>s;
    string ans=DFS(s);
    cout<<ans.size()<<'\n';
    cout<<ans<<'\n';
    return 0;
}

