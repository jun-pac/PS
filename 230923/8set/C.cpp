// 
//./C<test

#include <bits/stdc++.h>
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

int datas[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int vacan=-1, large=0;
        for(int i=0; i<n; i++){
            if(datas[i]!=i && vacan==-1){
                vacan=i;
            }    
            else if(datas[i]!=i) break;
        }
        if(vacan==-1) vacan=n;
        
        int y;
        while(true){
            cout<<vacan<<endl;
            cin>>y;
            if(y==-1) break;
            else if(y==-2) return 0;
            vacan=y;
        }
    }
    return 0;
}