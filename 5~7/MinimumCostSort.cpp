#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

static const int MAX  = 1000;
static const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

int MinimumCostSort(int A[], int B[], int n) {
  int ans = 0;

  bool V[MAX];
  for ( int i = 0; i< n; i++ ) {
    V[i] = false;
  }
  
  for ( int i = 0; i < n; i++ ) T[B[i]] = i;
  for ( int i = 0; i < n; i++ ) {
    if ( V[i] ) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    while ( 1 ) {
      V[cur] = true;
      an++;
      int v = A[cur];
      m = min(m, v);
      S+= v;
      cur = T[v];
      if ( V[cur] ) break;
    }
    ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
  }

  return ans;
}

int main() {
  cin >> n;
  s = VMAX;
  for ( int i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
    s = min(s, A[i]);
    B[i] = A[i];
  }
  sort(B, B + n);
  
  int ans = MinimumCostSort(A, B, n);
  
  cout << ans << endl;
  return 0;
}
