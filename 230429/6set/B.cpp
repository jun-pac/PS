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
    string s;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        int min_idx=-1;
        int min_val=100;
        for(int i=0; i<n; i++){
            if(s[i]-'a'<=min_val){
                min_val=s[i]-'a';
                min_idx=i;
            }
        }
        cout<<s[min_idx];
        for(int i=0; i<min_idx; i++) cout<<s[i];
        for(int i=min_idx+1; i<n; i++) cout<<s[i];
        cout<<endl;
    }
    return 0;
}