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

int datas[200020], tar[200020], order[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        //for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) cin>>datas[i];
        int end_cur=n-1;
        bool flag=1;
        for(int i=0; i<min(n,k); i++){
            if(datas[end_cur]>n){
                flag=false;
                break;
            }
            else end_cur=(end_cur-datas[end_cur]+n)%n;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

