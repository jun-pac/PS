#include <iostream>
#include "grade.h"
using namespace std;

typedef long long ll;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define INF (1e16)

grade::grade(int n, int *s, int g)
{
    int i = 0;
    this->num = n;
    this->scores = new int[n];
    this->numOfGroups = g;
    
    for (i = 0; i < n; i++)
        scores[i] = s[i];
    return;
}

grade::~grade()
{
    if (this->scores)
        delete[] this->scores;
    this->scores = 0;
    this->num = 0;
    return;
}

void grade::printScores()
{
    if (this->num)
    {
        int i = 0;
        cout << "Number of scores: " << this->num << endl;
        cout << "Number of groups: " << this->numOfGroups << endl;
        for (i = 0; i < num - 1; i++)
            cout << scores[i] << "  ";
        cout << scores[num - 1] << endl;
    }
}

// Algorithm starts from here.
// Get error value is scores[l], scores[l+1], ... scores[r] are grouped. It works in O(1) time.
inline ll get_error(int l, int r, ll sum[]){
   int mid=(l+r)>>1;
   if((r-l+1)%2==0) return sum[r]-2*sum[mid]+(l==0?0:sum[l-1]);
   else return sum[r]-sum[mid]-(mid==0?0:sum[mid-1])+(l==0?0:sum[l-1]);
}

int grade::minimumError(){
    int n=this->num, g=this->numOfGroups;

    ll** DP = new ll*[g];
    for(int i = 0; i < g; i++) DP[i] = new ll[n];
    ll* sum = new ll[n];

    // Insertion Sort : O(N^2) is enough since total complexity is O(N^2 G).
    rng(i,0,n-1){
            int mn=scores[i], mnidx=i;
            rng(j,i+1,n-1) if(scores[j]<mn) mn=scores[j], mnidx=j;
            swap(scores[i],scores[mnidx]);
    }
    // sum[i] = scores[0]+scores[1]+...+scores[i]
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+scores[i];

    // Dynamic programming. DP[i][j] indicates minimum total error when 0,1,...,j th elements are grouped in i+1 group(s).
    // This will take O(N^2 G)
    rng(j,0,n-1) DP[0][j]=get_error(0,j,sum);
    rng(i,1,g-1){
        rng(j,i,n-1){
            ll mn=INF;
            rng(k,i,j){
                mn=min(mn,DP[i-1][k-1]+get_error(k,j,sum));
            }
            DP[i][j]=mn;
            // DP[i][j]=max{DP[i-1][j-1]+geterror(j,j), ... DP[i-1][i-1]+geterror(i,j)}
        }
    }
    return DP[g-1][n-1];
}