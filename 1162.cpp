#include <bits/stdc++.h> 

using namespace std;

int swapper (vector <int> t) {
    int n = t.size();
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                swap(t[j],t[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, swaps = 0;
    vector <int> train;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n_cars;
        cin >> n_cars;
        for (int j = 0; j < n_cars; j++) {
            int n;
            cin >> n;
            train.push_back(n);
        }
         vector <int> ot = train;
        sort (ot.begin(), ot.end());
        if ( train != ot) {
            swaps = swapper(train);
        }
        cout << "Optimal train swapping takes " << swaps << " swaps.\n" ;
        train.clear();
    } 
}