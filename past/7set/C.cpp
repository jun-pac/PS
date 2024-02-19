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

int fin[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        string s;
        cin>>n;
        for(int i=0; i<n; i++) cin>>fin[i];
        for(int i=0; i<n; i++){
            int u_cnt=0;
            cin>>k;
            cin>>s;
            for(int j=0; j<k; j++) u_cnt+=(s[j]=='U'?1:-1);
            cout<<(fin[i]-u_cnt+100)%10<<' ';
        }
        cout<<endl;
        
    }
    return 0;
}