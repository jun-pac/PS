// 
//./A<test.txt

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
        int a,b;
        cin>>a>>b;
        int last=(a<b?0:1);
        while(a!=0 || b!=0){
            if(last==0 && b!=0){
                cout<<1;
                b--;
                last=1;
            }
            else if(last==1 && a!=0){
                cout<<0;
                a--;
                last=0;
            }
            else if(a>0){
                cout<<0;
                a--;
            }
            else{
                cout<<1;
                b--;
            }
        }
        cout<<endl;
    }
    return 0;
}