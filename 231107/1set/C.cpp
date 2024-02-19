// 
//./C<test

#include <bits/stdc++.h>
#define endl '\n'
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

#define MOD 998244353
ll fact[200020];

void fill_fact(int n){
    fact[0]=1;
    for(int i=1; i<=n; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

int rem[200040];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    fill_fact(200002);
    while(t--){
        string s;
        cin>>s;
        int n;
        n=s.size();
        int last=-1;
        int cnt=0;
        int temp=0;
        for(int i=0; i<n; i++){
            if(last==-1) last=0;
            else if(s[last]!=s[i]){
                if(i>last+1){
                    rem[cnt++]=i-last;
                    temp+=i-last-1;
                }
                last=i;
            }
        }
        if(n>last+1){
            temp+=n-last-1;
            rem[cnt++]=n-last;
        }
        ll res=fact[temp];
        for(int i=0; i<cnt; i++) res=(res*rem[i])%MOD;
        cout<<temp<<' '<<(res%MOD+MOD)%MOD<<endl;
    }
    return 0;
}