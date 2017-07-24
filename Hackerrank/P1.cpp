#include <bits/stdc++.h>

using namespace std;

int whoGetsTheCatch(int n, int x, vector < int > X, vector < int > V){
    // Complete this function
    vector<int>times;
    std::vector<int>times1=times;
    for(int i = 0;i<n;i++){
      times.push_back(abs(X[i]-x)/V[i]);
      times1.push_back(abs(X[i]-x)/V[i]);
    }
    sort(times1.begin(),times1.end());
    if(times1[0] == times1[1]){
      return -1;

    }
    else{
      for(int i = 0;i<n;i++){
        if(times1[0] == times[i])return i;
      }
    }
    return 0;
}

int main() {
    //  Return the index of the catcher who gets the catch, or -1 if no one gets the catch.
    int n;
    int x;
    cin >> n >> x;
    vector<int> X(n);
    for(int X_i = 0; X_i < n; X_i++){
       cin >> X[X_i];
    }
    vector<int> V(n);
    for(int V_i = 0; V_i < n; V_i++){
       cin >> V[V_i];
    }
    int result = whoGetsTheCatch(n, x, X, V);
    cout << result << endl;
    return 0;
}