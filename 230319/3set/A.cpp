// 
//./A<test

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

char comp[16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    comp[0]='F', comp[1]='B', comp[2]='F', comp[3]='F';
    comp[4]='B', comp[5]='F', comp[6]='F', comp[7]='B';
    for(int i=8; i<16; i++) comp[i]=comp[i-8];
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool flag=false;
        for(int i=0; i<8; i++){
            bool temp=true;
            for(int j=0; j<n; j++){
                if(comp[(i+j)%8]!=s[j]) temp=false;
            }
            if(temp){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}