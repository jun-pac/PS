// 
//./D<test

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

int datas[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        sort(datas,datas+n);
        // 0이 존재하면 -> 0 아닌애 개수
        // 0이 없지만 같은 애 존재하면 -> n
        // 0이 없고, 모두 다름 -> n+1
        int cnt=0;
        bool flag=false;
        for(int i=0; i<n; i++){
            if(datas[i]!=0) cnt++;
            if(i!=0 && datas[i]==datas[i-1]) flag=true;
        }
        if(datas[0]==0) cout<<cnt<<endl;
        else if(flag) cout<<cnt<<endl;
        else cout<<cnt+1<<endl;
    }
    return 0;
}