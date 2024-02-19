// 
//./C<test.txt

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

string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        cin>>s;
        int res=0;
        int fg=0;
        while(s[fg]!='g') fg++;
        int bg=n+fg;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='g'){
                bg=i;
            }
            if(s[i]==c) umax(res,bg-i);
        }
        cout<<res<<endl;
    }
    return 0;
}