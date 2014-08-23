#include <bits/stdc++.h>

using namespace std;

int v[11];
int dp[101];
int ind[101];

int main() {
  int N;
 
  for (int i=1; i<=10; i++) {
    cin >> v[i];
  }
 
  cin >> N;
 
  for (int i=1; i<=10; i++) { //se llena la matriz de km con los costos del 1 al 10
    dp[i] = v[i];  
    ind[i] = i;
  }
 
 	
 
  for (int i=11; i<=N; i++) { //se llena la matriz restante
    dp[i] = v[1]*i;
    ind[i] = 1;
  }
  
  for (int i=2; i<=N; i++) { //se resuelve
    for (int j=i+1 ; j<=N; j++) {
      if (dp[j] > dp[i] + dp[j-i]) {
        dp[j] = dp[i] + dp[j-i];
        ind[j] = ind[j-i];
      }
    }
  }
  
  stack< pair<int,int> > c;
  short k = N;
  while (k>0){ //se obtienen los nodods
  	c.push( make_pair(ind[k],dp[ind[k]]  ));
  	k-=ind[k];
  }
  
  while(!c.empty()){ //se imprime
  	cout << c.top().first << " " << c.top().second << endl;
  	c.pop();
  }
    cout << dp[N];
    return 0;
}
