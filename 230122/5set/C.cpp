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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int f_one=-1, f_zero=-1;
        for(int i=0; i<n-1; i++){
            if(s[i]=='1'){
                f_one=max(f_one,i);
                if(f_zero==-1) cout<<1<<' ';
                else cout<<f_zero+2<<' ';
            }
            if(s[i]=='0'){
                f_zero=max(f_zero,i);
                if(f_one==-1) cout<<1<<' ';
                else cout<<f_one+2<<' ';
            }
        }   
        cout<<endl;
    }
    return 0;
}