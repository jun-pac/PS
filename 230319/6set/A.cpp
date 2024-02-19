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

pair<int,string> ss[50];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<2*n-2; i++){
            cin>>ss[i].se;
            ss[i].fi=ss[i].se.size();
        }
        sort(ss,ss+2*n-2); // 1,1,2,2, ... ,n-1,n-1
        bool flag=true;
        int mid1, mid2;
        mid1=(n-1)/2*2,mid2=(n-1)/2*2+1;
        for(int i=0; i<ss[mid1].fi; i++) if(ss[mid1].se[i]!=ss[mid2].se[ss[mid2].fi-1-i]) flag=false;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;       

    }
    return 0;
}