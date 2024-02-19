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
        string s;
        cin>>n;
        cin>>s;
        char last=s[0];
        int l_idx=0;
        int mx=1;
        int i=1;
        while(i<n+1){
            while(i<n+1 && s[i]==last) i++;
            mx=max(mx,i-l_idx);
            l_idx=i;
            last=s[i];
        }
        cout<<mx+1<<endl;
    }
    return 0;
}