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

string datas[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        int res=1;
        for(int i=1; i<n; i++){
            bool flag=false;
            for(int j=0; j<k; j++){
                if(datas[0][j]!=datas[i][j]) flag=true;
            }
            if(!flag) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}