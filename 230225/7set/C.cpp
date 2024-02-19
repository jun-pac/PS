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
        for(int i=0; i<n; i++){
            cin>>datas[i];
            datas[i]--;
        }
        int l=0, r=n-1;
        int mn=0, mx=n-1;
        bool flag=false;
        while(l<r){
            if(datas[l]!=mn && datas[l]!=mx && datas[r]!=mn && datas[r]!=mx){
                flag=true;
                cout<<l+1<<' '<<r+1<<endl;
                break;
            }
            else if((datas[l]==mn || datas[l]==mx) && (datas[r]==mn || datas[r]==mx)){
                mn++, mx--;
                l++, r--;
            }
            else if(datas[l]==mn || datas[l]==mx){
                if(datas[l]==mn) mn++;
                else mx--;
                l++;
            }
            else{
                if(datas[r]==mn) mn++;
                else mx--;
                r--;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}