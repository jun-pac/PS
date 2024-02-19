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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b,c,res;
        cin>>a>>b>>c;
        int an=0, bn=0, cn=0;
        for(int i=0; i<2*n; i++){
            if(a[i]=='1') an++;
            if(b[i]=='1') bn++;
            if(c[i]=='1') cn++;
        }
        int more_half=0;
        if(an>=n) more_half++;
        if(bn>=n) more_half++;
        if(cn>=n) more_half++;
        bool rev=(more_half<2);
        if(rev){
            for(int i=0; i<2*n; i++){
                a[i]=(a[i]=='1'?'0':'1');
                b[i]=(b[i]=='1'?'0':'1');
                c[i]=(c[i]=='1'?'0':'1');
            }
            an=2*n-an;
            bn=2*n-bn;
            cn=2*n-cn;
        }
    
        if(an<n){
            an=cn;
            a=c;
        } 
        else if(bn<n){
            bn=cn;
            b=c;
        }
        
        if(an<bn){
            swap(a,b);
            swap(an,bn);    
        }
        int cur=0; // cursor in b
        for(int i=0; i<2*n; i++){
            if(a[i]=='0'){
                res.push_back('0');
            }
            else{
                while(cur<2*n && b[cur]=='0'){
                    cur++;
                    res.push_back('0');
                }
                cur++;
                res.push_back('1');
            }
        }
        while(cur<2*n && b[cur]=='0'){
            cur++;
            res.push_back('0');
        }
        for(int i=0; i<res.size(); i++) cout<<(rev?(res[i]=='1'?'0':'1'):res[i]);
        cout<<endl; 
    }
    return 0;
}