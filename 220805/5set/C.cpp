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

int a[200020], b[200020];
unordered_map<int,int> mxa, mxb;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        mxa.clear(), mxb.clear();
        //for(int i=0; i<10; i++) cout<<mxa[i]<<' ';
        //cout<<endl;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        int last=a[0], cnt=1;
        for(int i=1; i<n; i++){
            if(a[i]!=last){
                if(mxa[last]<cnt){
                    mxa[last]=cnt;
                    //cout<<"Inserted : "<<last<<' '<<cnt<<endl;
                }
                last=a[i];
                cnt=1;
            }
            else cnt++;
        }
        if(mxa[last]<cnt){
            //cout<<"Inserted : "<<last<<' '<<cnt<<endl;
            mxa[last]=cnt;
        }

        last=b[0], cnt=1;
        for(int i=1; i<n; i++){
            if(b[i]!=last){
                if(mxb[last]<cnt) mxb[last]=cnt;
                last=b[i];
                cnt=1;
            }
            else cnt++;
        }
        if(mxb[last]<cnt) mxb[last]=cnt;

        int res=0;
        for(int i=0; i<n; i++){
            res=max(res,mxa[a[i]]+mxb[a[i]]);
            res=max(res,mxa[b[i]]+mxb[b[i]]);
        }
        cout<<res<<endl;
    }
    return 0;
}