// 
//./C<test.txt

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

int datas[200001];

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
        if(n%2==0){
            int last=datas[0];
            int last_idx=0; 
            int mx_len=0, mn_len=220000;
            int mx_idx, mn_idx;
            int i=1;
            while(i<n){
                while(i<n && datas[i]==last) i++;
                if(i!=n) last=datas[i];
                int cur_len=i-last_idx;
                if(cur_len>mx_len){
                    mx_len=cur_len;
                    mx_idx=last_idx;
                }
                if(cur_len<mn_len){
                    mn_len=cur_len;
                    mn_idx=last_idx;
                }
                last_idx=i;
            }
            //cout<<"de "<<mx_len<<' '<<mn_len<<' '<<mx_idx<<' '<<mn_idx<<endl;
            
            datas[mx_idx]=datas[mn_idx];
            
            sort(datas,datas+n);
        }
        if(n%2==1){
            int last=datas[0];
            int last_idx=0; 
            int mn_len=220000;
            int mn_idx=0;
            int i=1;
            while(i<n){
                while(i<n && datas[i]==last) i++;
                if(i!=n) last=datas[i];
                int cur_len=i-last_idx;
                if(cur_len<mn_len){
                    mn_len=cur_len;
                    mn_idx=last_idx;
                }
                last_idx=i;
            }
            datas[n]=datas[mn_idx];
            n++;
            sort(datas,datas+n);
        }
        //for(int i=0; i<n; i++) cout<<datas[i]<<' ';
        //cout<<endl;

        int inc_num=n/2, i_l;
        int dec_num=n/2, d_l;

        i_l=datas[0];
        d_l=datas[1];
        for(int i=2; i<n; i++){
            if(i%2==0){
                if(i_l==datas[i]) inc_num--;
                i_l=datas[i];
            }
            else{
                if(d_l==datas[i]) dec_num--;
                d_l=datas[i];
            }
        }
        cout<<min(inc_num,dec_num)<<endl;
    }
    return 0;
}