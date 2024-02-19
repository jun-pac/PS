// 
//./D<test

#include <bits/stdc++.h>
//#define endl '\n'
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

int datas[10000];
int ls[10000];
int rs[10000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll res=0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n-1; i++){
            ll temp=0;
            int l=i; // r은 l로부터 idx우측의 가장 가까운 inversion
            int last=datas[l];
            int cnt=0;
            ls[cnt++]=l;
                        
            while(l>=0){
                //cout<<"here?"<<endl;
                while(l>=0 && last>=datas[l]) l--;
                // 기존의 위치보다 더 '큰' datas[l]을 찾는다.
                if(l==-1) break;
                ls[cnt++]=l;
                last=datas[l];
            }
            reverse(ls,ls+cnt); // 이제 ls는 증가하는 순서임
            //cout<<"D "<<cnt<<endl;
            //for(int j=0; j<cnt; j++) cout<<'s'<<ls[j]<<' ';
            //cout<<endl;
            int r=i+1;
            for(int j=0; j<cnt; j++){
                //cout<<"ls[j] = "<<ls[j]<<endl;
                while(r<n && datas[r]>=datas[ls[j]]) r++;
                rs[j]=r;
            }
            for(int j=0; j<cnt-1; j++) temp+=(ls[j]+1)*(rs[j+1]-rs[j]);
            temp+=(ls[cnt-1]+1)*(n-rs[cnt-1]);
            res+=temp;
            //cout<<"idx = "<<i<<' '<<temp<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}