#include <bits/stdc++.h>

using namespace std;

struct Node {
    public:
        Node *left = NULL;
        Node *right = NULL;
        char value = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int cases, n;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> n;
        Node nodes[n];
        Node *parent = &nodes[0];
        string input_pre, input_in; 
        cin >> input_pre >> input_in;
        parent.value = input_per[0];
        int k = 1;
        for (int j = 0; j < n; j++) {
            if (j == 0) continue;
            if (j == n-1) break;;
            if (input_in[j] == parent.value) {
                input_in[j-1] = node[k].value;
                parent.value = node[k].value;
                parent->left = &nodes[k].value;
                k++;
                input[j+1] node[k].value;
                parent->right = &nodes[k].value;
                k++;
                j = 0;
            }
        }
    }
    
}