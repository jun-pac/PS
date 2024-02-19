// 
//./D<test.txt

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

int datas[100000];
#define INF 1000000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,res=1000000;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        int kk=k;
        int bucket_sz=100;

        int s,e=datas[n-1]/kk;
        int l=0, r=e;
        bool flag;
        while(l!=r){
            flag=true;
            int mid=(l+r)>>1;
            s=e-mid;
            for(int i=0; i<n-1; i++){
                if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s) || datas[i]/(e+1)>=k){
                    flag=false;
                    break;
                }
            }
            if(flag) r=mid;
            else l=mid+1;
        }
        res=min(res,l);
        l=0, r=res;
        s=datas[n-1]/kk;
        while(l!=r){
            flag=true;
            int mid=(l+r)>>1;
            e=s+mid;
            for(int i=0; i<n-1; i++){
                if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s) || datas[i]/(e+1)>=k){
                    flag=false;
                    break;
                }
            }
            if(flag) r=mid;
            else l=mid+1;
        }
        res=min(res,l);

        for(int kk=2; kk<=k; kk++){
            flag=true;
            e=datas[n-1]/kk, s=e-res;
            for(int i=0; i<min(n-1,bucket_sz); i++){
                if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s) || datas[i]/(e+1)>=k){
                    flag=false;
                    break;
                }
            }
            if(flag){
                e=datas[n-1]/kk;
                l=0, r=res;
                while(l!=r){
                    flag=true;
                    int mid=(l+r)>>1;
                    s=e-mid;
                    for(int i=0; i<n-1; i++){
                        if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s)|| datas[i]/(e+1)>=k){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) r=mid;
                    else l=mid+1;
                }
                s=datas[n-1]/kk;
                res=min(res,l);
            }
            flag=true;
            s=datas[n-1]/kk, e=s+res;
            for(int i=0; i<min(n-1,bucket_sz); i++){
                if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s) || datas[i]/(e+1)>=k){
                    flag=false;
                    break;
                }
            }
            if(flag){
                s=datas[n-1]/kk;
                l=0, r=res;
                while(l!=r){
                    flag=true;
                    int mid=(l+r)>>1;
                    e=s+mid;
                    for(int i=0; i<n-1; i++){
                        if(datas[i]/(e+1)==(s<=0?INF:datas[i]/s) || datas[i]/(e+1)>=k){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) r=mid;
                    else l=mid+1;
                }
                res=min(res,l);
            }
        }
        
        cout<<res<<endl;
    }
    return 0;
}