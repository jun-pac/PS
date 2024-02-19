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

int datas[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int last=0;

        for(int i=0; i<n-1; i++){
            cin>>datas[i];
        }
        cout<<datas[0]<<' ';
        for(int i=0; i<n-1; i++){
            // ans[i+1]을 채워야 하고
            if(i==n-2) cout<<datas[i];
            else if(datas[i]<datas[i+1]){
                cout<<datas[i]<<' '<<datas[i+1]<<' ';
                i++;
            }
            else{
                cout<<datas[i+1]<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}