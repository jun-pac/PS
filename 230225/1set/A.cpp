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

int datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++){
            if(datas[i]%2==1) cnt++;
        }
        if(cnt==0 || (cnt==2 && n==3)) cout<<"NO"<<endl;
        else if(cnt<=2){
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++){
                if(datas[i]%2==1){
                    cout<<i+1<<' ';
                    break;
                }
            }
            int temp=2;
            for(int i=0; i<n; i++){
                if(datas[i]%2==0 && temp>0){
                    cout<<i+1<<' ';
                    temp--;
                }
                if(temp==0) break;
            }
            cout<<endl;
        }
        else{
            cout<<"YES"<<endl;
            int temp=3;
            for(int i=0; i<n; i++){
                if(datas[i]%2==1 && temp>0){
                    cout<<i+1<<' ';
                    temp--;
                }
                if(temp==0)break;
            }
            cout<<endl;
        }
    }
    return 0;
}