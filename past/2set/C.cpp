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

string s;
pair<int,int> lmx[100000];
pair<int,int> rmx[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int mn=100, mx=-1;
        cin>>s;
        int ssum=s[0]-'0';
        lmx[0]={s[0]-'0',0};
        for(int i=1; i<n; i++){
            if(lmx[i-1].fi<s[i]-'0') lmx[i]={s[i]-'0',i};
            else lmx[i]=lmx[i-1];
            ssum+=int(s[i]-'0');
        }
        rmx[0]={s[n-1]-'0',n-1};
        for(int i=n-2; i>=0; i--){
            if(rmx[n-1-i-1].fi<s[i]-'0') rmx[n-1-i]={s[i]-'0',i};
            else rmx[n-1-i]=rmx[n-2-i];
        }

        // debug
        //for(int i=0; i<n; i++) cout<<lmx[i].fi<<' '<<lmx[i].se<<endl;
        //cout<<endl;
        //for(int i=0; i<n; i++) cout<<rmx[i].fi<<' '<<rmx[i].se<<endl;
        //cout<<endl;

        int l_mx, r_mx;
        r_mx=rmx[min(k,n-1)].fi;
        int r_idx=rmx[min(k,n-1)].se;
        int left_k=k-(n-1-r_idx);

        //cout<<r_mx<<' '<<r_idx<<' '<<left_k<<endl;
        
        if(r_idx!=0){
            l_mx=lmx[min(left_k,r_idx-1)].fi;
        }
        else{
            l_mx=s[1]-'0';
        }
        
        int val=l_mx*10+r_mx;
        //cout<<"debelf "<<l_mx<<' '<<val<<endl;
        cout<<11*(ssum-l_mx-r_mx)+val<<endl;
    }
    return 0;
}