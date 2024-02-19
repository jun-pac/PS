
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
// a�� b�� �ڷ�, c�� b�� ������  b ccc b aaa b--> cccbbbaaa�� ���� �� �ִ� ���̴�.
// a�� c�� ����� ���� ���Ͱ� �Ұ���
// b�� 

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
    // s�� �ִ� b�� ���..? a�麸�ٴ� 
    // acs���� Ȯ���� �ϴ°Ŵ�. s->t�� ������ acs���� a���� �� �ڷ� �����鼭 ������ �Ӵ���
    // acs�� c���� �� ������ ������ ���� �ڷ� �Դ���
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
    //     // a, b�� ��Ī�Ǵ� 'b'�̴�.   
    //     bcnt++; // ��� ã�� b�� 1���� ������ ����.     
    //     //cout<<"check "<<a<<' '<<b<<' '<<bcnt<<' '<<a-bcnt<<' '<<b-bcnt<<'\n';
    //     if(a<b){
    //         // s�ʿ��� �տ� �־��ٴ� ����, ���̿� c�ۿ� �����ٴ� ���̴�.
    //         // acs[a-bcnt+1] ... acs[b-bcnt]���̿� c�ۿ� ����?
    //         // a=0 b=1 bcnt=1�� �����غ��� acs[0]�� c�� ��.
    //         // a=1 b=5 bcnt=1 
    //         int anum=acnt[b-bcnt]-(a-bcnt==-1?0:acnt[a-bcnt]);
    //         int cnum=(b-a)-anum;
    //         if(anum!=0){
    //             flag=0;
    //             break;
    //         }
    //     }
    //     else if(a>b){
    //         // b�� ������ ���� ���ȿ��� ���̿� 'a'�ۿ� ������� �Ѵ�.
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

