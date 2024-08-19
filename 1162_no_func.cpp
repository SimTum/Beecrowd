#include <bits/stdc++.h> 

using namespace std;



int main() {
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
        int m = train.size();
        for (int k = 0; k < m - 1; k++) {
            for (int l = 0; l < m - k - 1; l++) {
                if (train[l] > train[l + 1]) {
                    swap(train[l],train[l + 1]);
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
        train.clear();
        swaps = 0;
    } 
}