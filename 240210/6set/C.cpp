
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 100030
#define MOD 998244353
#define INF 1000000007 

string s,t;
int fcnt[3];
// a는 b의 뒤로, c는 b의 앞으로  b ccc b aaa b--> cccbbbaaa를 만들 수 있는 것이다.
// a와 c의 관계는 절대 복귀가 불가능
// b는 

void Solve(){
    int n;
    cin>>n;
    cin>>s>>t;
    fill(fcnt,fcnt+3,0);
    //rng(i,0,2) cout<<fcnt[i]<<' '; cout<<'\n'; 
    rng(i,0,n-1) fcnt[s[i]-'a']++;
    //rng(i,0,2) cout<<fcnt[i]<<' '; cout<<'\n'; 
    rng(i,0,n-1) fcnt[t[i]-'a']--;
    //rng(i,0,2) cout<<fcnt[i]<<' '; cout<<'\n'; 
    if(!(fcnt[0]==0 && fcnt[1]==0 && fcnt[2]==0)){
        cout<<"NO\n";
        return;
    }
    bool ac=1;
    int a=0, b=0;
    bool flag=1;
    int sb=0, tb=0;
    while(a<n && b<n){
        while(a<n && s[a]=='b'){
            sb++, a++;
        }
        while(b<n && t[b]=='b'){
            tb++, b++;
        }
        if(a==n || b==n){
            assert(a==n && b==n);
            break;
        }
        if(s[a]!=t[b]){
            ac=0; break;
        }
        if(s[a]=='c'){
            if(sb<tb){
                flag=0;
                break;
            }
        }
        else if(s[a]=='a'){
            if(sb>tb){
                flag=0;
                break;
            }
        }
        a++, b++;
    }
    if(!ac || !flag) cout<<"NO\n";
    else cout<<"YES\n";

    //rng(i,0,(int)acs.size()-1) acnt[i]=(i==0?0:acnt[i-1])+(acs[i]=='a');
    // s에 있는 b는 어떻게..? a들보다는 
    // acs에서 확인을 하는거다. s->t로 가려면 acs에서 a들을 다 뒤로 보내면서 앞으로 왓던지
    // acs의 c들을 다 앞으로 보내고 내가 뒤로 왔던지
    // a=0, b=0;
    // int bcnt=0;
    // bool flag=1;
    // while(a<n && b<n){
    //     while(a<n && s[a]!='b') a++;
    //     while(b<n && t[b]!='b') b++;
    //     if(a==n || b==n){
    //         assert(a==n && b==n);
    //         break;
    //     }
    //     assert(s[a]=='b' && t[b]=='b');
    //     // a, b가 매칭되는 'b'이다.   
    //     bcnt++; // 방금 찾은 b도 1개로 세도록 하자.     
    //     //cout<<"check "<<a<<' '<<b<<' '<<bcnt<<' '<<a-bcnt<<' '<<b-bcnt<<'\n';
    //     if(a<b){
    //         // s쪽에서 앞에 있었다는 것은, 사이에 c밖에 없었다는 것이다.
    //         // acs[a-bcnt+1] ... acs[b-bcnt]사이에 c밖에 없다?
    //         // a=0 b=1 bcnt=1을 생각해보면 acs[0]만 c면 됨.
    //         // a=1 b=5 bcnt=1 
    //         int anum=acnt[b-bcnt]-(a-bcnt==-1?0:acnt[a-bcnt]);
    //         int cnum=(b-a)-anum;
    //         if(anum!=0){
    //             flag=0;
    //             break;
    //         }
    //     }
    //     else if(a>b){
    //         // b가 앞으로 가는 동안에는 사이에 'a'밖에 없었어야 한다.
    //         int anum=acnt[a-bcnt]-(b-bcnt==-1?0:acnt[b-bcnt]);
    //         int cnum=(a-b)-anum;
    //         if(cnum!=0){
    //             flag=0;
    //             break;
    //         }
    //     }
    //     a++, b++;
    // }
    // 
    //cout<<(flag?"YES\n":"NO\n");

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

