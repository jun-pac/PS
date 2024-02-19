// 
//./B<test

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0, r=n/2-1;
        //cout<<"r "<<r<<endl;
        while(l<=r && s[l]==s[n-1-l]) l++;
        // s[l]부터는 우측과 다름
        if(l>r){
            cout<<"YES"<<endl;
            continue;
        }
        while(l<=r && s[l]!=s[n-1-l]) l++;
        if(l>r){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag=true;
        for(int i=l; i<=r; i++) if(s[i]!=s[n-1-i]) flag=false;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}