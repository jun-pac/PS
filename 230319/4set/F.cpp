// 
//./F<test

// DP...? 를 이용한 풀이를 생각해보자.

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

int datas[10000];
int n,b;

ll get_mx_del(int s, int r, int mid, int k1, int k2){
    // s는 2b-1이하의 원소의 개수, r은 div와 sub연산을 중복할 애들의 개수
    // mid는 lower_bound(b)임. 즉 b이상인 최소의 원소
    // s-r은 한 개 이하의 연산만 적용할 대상자들. 
    //cout<<"FN : "<<s<<' '<<r<<' '<<mid<<' '<<k1<<' '<<k2<<endl; 
    ll res=0;
    for(int i=s-r; i<s; i++) res+=datas[i];

    //cout<<"res temp : "<<res<<endl;
    int l_end=s-r-k1-k2; // [l_end, s-r-1]까지를 하나로 채우면 된다.
    if(l_end>=mid){
        // 앞부분은 k2로 제끼고, 뒷부분은 k1으로 제낀다. 순서대로 해주면 됨
        //cout<<"FIRST CASE : "<<l_end<<' '<<datas[l_end]<<' '<<datas[s-r-k1]<<endl;
        for(int i=l_end; i<s-r-k1; i++){
            res+=datas[i]-max(datas[i]-b,0);
        }
        for(int i=s-r-k1; i<s-r; i++){
            res+=datas[i]-(datas[i]+1)/2;
        }
        //cout<<"RES : "<<res<<endl;
    }
    else if(s<=mid){
        //cout<<"FIRST CASE2 : "<<l_end<<' '<<datas[l_end]<<' '<<datas[s-r-k2]<<endl;
        for(int i=l_end; i<s-r-k2; i++){
            res+=datas[i]-(datas[i]+1)/2;
        }
        for(int i=s-r-k2; i<s-r; i++){
            res+=datas[i]-max(datas[i]-b,0);
        }
        //cout<<"RES : "<<res<<endl;
    }
    else{
        // div sub div가 번갈아서 등장해야 함.
        //cout<<"LAST CASE"<<endl;
        int r_sub=mid;
        int l_sub=mid-1;
        while(k2>0){
            if(r_sub>=s){
                res+=datas[l_sub]-max(datas[l_sub]-b,0);
                //cout<<"L del : "<<datas[l_sub]-max(datas[l_sub]-b,0)<<endl;
                l_sub--;
            }
            else if(l_sub<l_end){
                res+=datas[r_sub]-max(datas[r_sub]-b,0);
                //cout<<"R del : "<<datas[r_sub]-max(datas[r_sub]-b,0)<<endl;
                r_sub++;
            }
            else{
                if(datas[r_sub]-b>=b-datas[l_sub]){
                    res+=datas[l_sub]-max(datas[l_sub]-b,0);
                    //cout<<"L del : "<<datas[l_sub]-max(datas[l_sub]-b,0)<<endl;
                    l_sub--;
                }
                else{
                    res+=datas[r_sub]-max(datas[r_sub]-b,0);
                    //cout<<"R del : "<<datas[r_sub]-max(datas[r_sub]-b,0)<<endl;
                    r_sub++;
                }
            }
            k2--;
        }
        //cout<<"l r k2 "<<l_sub<<' '<<r_sub<<' '<<k2<<endl;
        for(int i=l_end; i<s-r; i++){
            if(i<=l_sub || i>=r_sub){
                k1--;
                res+=datas[i]-(datas[i]+1)/2;
            }
        }
        //cout<<"For debug, k1==0 : "<<k1<<endl;
    }
    //cout<<"res last : "<<res<<endl;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int k1, k2;
        cin>>n>>b>>k1>>k2;
        for(int i=0; i<n; i++) cin>>datas[i];
        ll sum=0;
        for(int i=0; i<n; i++) sum+=datas[i];
        //cout<<sum<<endl;
        sort(datas,datas+n);
        int s=lower_bound(datas,datas+n,2*b)-datas;
        int m=lower_bound(datas,datas+n,b)-datas;

        ll del=0;
        for(int i=n-1; i>=s; i--){
            if(k1>0){
                k1--;
                del+=datas[i]-(datas[i]+1)/2;
                datas[i]=(datas[i]+1)/2;
            }
            if(k2>0){
                k2--;
                del+=datas[i]-max(datas[i]-b,0);
                datas[i]=max(datas[i]-b,0);
            }
        }
        
        if(k1>0 || k2>0){
            ll mx_del=0;
            for(int r=max(k1+k2-s,0); r<=min(k1,k2); r++) mx_del=max(mx_del,get_mx_del(s,r,m, k1-r,k2-r));
            //cout<<"DEL MXDEL : "<<del<<' '<<mx_del<<endl;
            del+=mx_del;
        }

        cout<<sum-del<<endl;

    }
    return 0;
}

