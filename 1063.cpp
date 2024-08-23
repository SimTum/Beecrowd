#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <char> init;
    queue <char> desired;
    stack <char> buffer;
    stack <char> result;
    unsigned int t_length;
    string output = "";
    do { 
        cin >> t_length;
        if (t_length < 0) return 0;
        for (int i = 0; i < t_length; i++) {
            char letter;
            cin >> letter;
            init.push(letter);
            // cout << init [i] << " ";
        }
        for (int i = 0; i < t_length; i++) {
            char letter;
            cin >> letter;
            desired.push(letter);
            // cout << desired [i] << " ";
        }
    int j = 0;
    for (int i = 0; i < t_length; i ++) {
        buffer.push(init.front());
        init.pop(); 
        // cout << buffer[i] << " ";
        output.append("I");
        while (buffer.top() == desired.front() && desired.front() != 0) {
            result.push(buffer.top());
            buffer.pop();
            desired.pop();
            output.append("R");
            // cout <<  result.top() << " ";
            j++;
        }
    j = 0;
    }
    if (output.size() != t_length * 2) cout << output << " Impossible" << endl;
    else cout << output << endl;
    init.empty();
    desired.empty();
    buffer.empty();
    result.empty();
    output.clear();
    } while (t_length > 0);
    return 0;
}