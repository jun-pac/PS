// 
//./D<test

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

ull r_swap[300001], l_swap[300001];
// r_swap은 1들에게 묻는다. 느그 우측에 0몇 개야?
// l_swap은 # of 1s in the left side of 0s


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        ull num1=0, num0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') num0++;
            else num1++;
        }
        ull num_swap=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') num0--;
            else{
                // '1'일 때만 r_swap의미있다
                r_swap[i]=num0;
                num_swap=num_swap+r_swap[i];
            }
        }
        //cout<<"NS "<<num_swap<<endl;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1') num1--;
            else l_swap[i]=num1;
        }

        ull del1=0, del0=0;
        int l=0, r=n-1;
        while(l<n && s[l]=='0') l++;
        while(r>=0 && s[r]=='1') r--;
        // l은 언제나 1에 멈춰있고
        // r은 언제나 0에 멈춰있음
        while(l<r){
            if(r_swap[l]-del0==l_swap[r]-del1 && l_swap[r]-del1>1){
                if(s[r-1]=='1'){
                    num_swap=num_swap-(r_swap[l]-del0);
                    del1+=1;
                    l++;
                    while(l<n && s[l]=='0') l++;
                }
                else{
                    num_swap=num_swap-(l_swap[r]-del1);
                    del0+=1;
                    r--;
                    while(r>=0 && s[r]=='1') r--;
                }
            }
            else if(r_swap[l]-del0>l_swap[r]-del1 && r_swap[l]-del0>1){
                // l을 제거
                num_swap=num_swap-(r_swap[l]-del0);
                del1+=1;
                l++;
                while(l<n && s[l]=='0') l++;
            }
            else if(r_swap[l]-del0<l_swap[r]-del1 && l_swap[r]-del1>1){
                num_swap=num_swap-(l_swap[r]-del1);
                del0+=1;
                r--;
                while(r>=0 && s[r]=='1') r--;
            }
            else{
                break;
            }
        }
        ull mul=1000000000000;
        //cout<<del0<<' '<<del1<<endl;
        cout<<num_swap*mul+(del0+del1)*(mul+1)<<endl;
    }
    return 0;
}