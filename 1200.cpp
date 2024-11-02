#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    public:
        Node *left = NULL;
        Node *right = NULL;
        char value;
};


void printTree_pre(Node *node, ostringstream *buffer, bool isRoot=true) {
    
    if (isRoot) {
        *buffer << node->value;
    } else {
        *buffer  << " " << node->value;
    }

    if (node->left) printTree_pre(node->left, buffer, false);
    if (node->right) printTree_pre(node->right, buffer, false);
}
void printTree_in(Node *node, ostringstream *buffer, int *count) {

    if (node->left && !node->right) printTree_in(node->left,buffer, count);
    else if (node->left) printTree_in(node->left, buffer, count);
    
        *count = *count - 1;
    if (*count > 0) {
        *buffer << node->value << " ";
    } else {
        *buffer << node->value;
    }

    if (node->right) printTree_in(node->right, buffer, count);

}
void printTree_post(Node *node, ostringstream *buffer, bool isRoot=true) {
    if (node->left) printTree_post(node->left, buffer, false);
    if (node->right) printTree_post(node->right, buffer, false);
    
    if (isRoot) {
        *buffer << node->value;
    } else {
        *buffer  << node->value << " ";
    }


}

void insert(char val, Node *root) {
    if (val < root->value) {
        if (root->left != NULL) {
            insert(val, root->left);
        } else {
            root->left = new Node();
            root->left->value = val;
        }
    } else {
        if (root->right != NULL) {
            insert(val, root->right);
        } else {
            root->right = new Node();
            root->right->value = val;
        }
    }
}

bool search (char input, Node *root) {
    if (input == root->value) return true;

    if (input < root->value) {
        if (root->left == NULL) return false;
        return search(input, root->left);
    }

    if (root->right == NULL) return false;
    return search(input, root->right);
}

int main() {
    string command;
    char input;
    int count1 = 0;

    Node *root = NULL;
    ostringstream out;

    while (cin >> command) {
        if (command == "I") {
            cin >> input;
            count1++;
            if(root == NULL) {
                root = new Node();
                root->value = input;
            } else {
                insert(input, root);
            }
        }
        if(command == "P") {
            cin >> input;
            out << input << " ";
            if (!search(input, root)) {
                out << "nao ";
            }
            out << "existe\n";
        }

        if(command == "PREFIXA") {
            printTree_pre(root, &out);
            out << "\n";
        }
        if(command == "POSFIXA") {
            printTree_post(root, &out);
            out << "\n";
        }
        if(command == "INFIXA") {
            int count2 = count1;
            printTree_in(root, &out, &count2);
            out << "\n";
        }
    }

    cout << out.str();

    return 0;
}