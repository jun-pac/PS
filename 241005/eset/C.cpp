
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)


int visited[10000];
bool check(int a, int b, int c, int d){
    if(10*a+b<=23 && 10*c+d<=59 && !visited[1000*a+100*b+10*c+d]){
        return visited[1000*a+100*b+10*c+d]=1;
    }
    return 0;
}
int valid_hhmm(int a, int b, int c, int d){
    int res=0;
    if(check(a,b,c,d)) res++;
    if(check(b,a,c,d)) res++;
    if(check(a,b,d,c)) res++;
    if(check(b,a,d,c)) res++;
    return res;
}

int solution(int A, int B, int C, int D){
    int res=0;
    fill(visited,visited+10000,0);
    res+=valid_hhmm(A,B,C,D);
    res+=valid_hhmm(A,C,B,D);
    res+=valid_hhmm(A,D,B,C);
    res+=valid_hhmm(B,C,A,D);
    res+=valid_hhmm(B,D,A,C);
    res+=valid_hhmm(C,D,A,B);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<solution(a,b,c,d)<<'\n';
    
    return 0;
}

