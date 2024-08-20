#include <bits/stdc++.h>

using namespace std;

struct {
    int index;
    int desired_index;
} train_car;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <char> init;
    vector <char> desired;
    vector <char> buffer;
    vector <char> result;
    unsigned int t_length;
    string output = "";
    cin >> t_length;
    if (t_length != 0) {
        for (int i = 0; i < t_length; i++) {
            char letter;
            cin >> letter;
            init.push_back(letter);
            // cout << init [i] << " ";
        }
        for (int i = 0; i < t_length; i++) {
            char letter;
            cin >> letter;
            desired.push_back(letter);
            // cout << desired [i] << " ";
        }
    }
    for (int i = 0; i < t_length; i ++) {
        buffer.push_back(init[1]);
        init.erase(1);
        if (buffer.end() == Desired [i]) {
        }
        else {
        }
    }
}