#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
public:
    Node *left = NULL;
    Node *right = NULL;
    int value;
};

void printTree_pre(Node *node, ostringstream *buffer, bool isRoot = true)
{

    if (node->value != 0)
    {
        if (isRoot)
        {
            *buffer << node->value;
        }
        else
        {
            *buffer << " " << node->value;
        }
    }

    if (node->left)
        printTree_pre(node->left, buffer, false);
    if (node->right)
        printTree_pre(node->right, buffer, false);
}
void printTree_in(Node *node, ostringstream *buffer, int *count) // prints in-ordrer trversal. Breakes when there are 2 or more members in the input
{
    if (node->value != 0)
    {
        if (node->left)
            printTree_in(node->left, buffer, count);

        *count = *count - 1;
        if (*count > 0)
        {
            *buffer << node->value << " ";
        }
        else
        {
            *buffer << node->value;
        }

        if (node->right)
            printTree_in(node->right, buffer, count);
    }
}
void printTree_post(Node *node, ostringstream *buffer, bool isRoot = true)
{
    if (node->value != 0)
    {
        if (node->left)
            printTree_post(node->left, buffer, false);
        if (node->right)
            printTree_post(node->right, buffer, false);

        if (node->value != 0)
        {
            if (isRoot)
            {
                *buffer << node->value;
            }
            else
            {
                *buffer << node->value << " ";
            }
        }
    }
}

void insert(int val, Node *root)
{
    if (val < root->value)
    {
        if (root->left != NULL)
        {
            insert(val, root->left);
        }
        else
        {
            root->left = new Node();
            root->left->value = val;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            insert(val, root->right);
        }
        else
        {
            root->right = new Node();
            root->right->value = val;
        }
    }
}
struct Node *remove(int val, Node *root) // fucks everything up I
{
    if (root == NULL)
        return root;
    else if (val < root->value)
        root->left = remove(val, root->left);
    else if (val > root->value)
        root->right = remove(val, root->right);
    else // we found a node to be removed
    {
        // case 1 - no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2 - 1 child
        else if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        // ccaase 3 - 2 children
        else
        {
            struct Node *temp = root->left;
            while(temp && temp->right) temp = temp->right;
            root->value = temp->value;
            root->left = remove(temp->value, root->left);
        }
        return root;
    }
}
bool search(int input, Node *root)
{
    if (input == root->value)
        return true;

    else if (input < root->value)
    {
        if (root->left == NULL)
            return false;
        return search(input, root->left);
    }

    else if (input > root->value)
    {
        if (root->right == NULL)
            return false;
        return search(input, root->right);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string command;
    int input;
    int count1 = 0;
    Node *root = NULL;
    ostringstream out;

    while (cin >> command)
    {
        if (command == "R")
        {
            cin >> input;
            if (root != NULL)
            {
                if (search(input, root))
                {
                    count1--;
                    root = remove(input, root);
                }
            }
        }
        if (command == "I")
        {
            cin >> input;
            if (root == NULL)
            {
                root = new Node();
                root->value = input;
                count1++;
            }
            else
            {
                if (!search(input, root))
                {
                    count1++;
                    if (root->value == 0)
                        root->value = input;
                    else
                        insert(input, root);
                }
            }
        }
        if (command == "P")
        {
            cin >> input;
            if (root)
            {
                out << input << " ";
                if (!search(input, root))
                {
                    out << "nao ";
                }
                out << "existe\n";
            }
            else
                out << input << " nao existe\n";
        }

        if (command == "PREFIXA")
        {
            if (root->value != 0)
            {
                printTree_pre(root, &out);
                out << "\n";
            }
        }
        if (command == "POSFIXA")
        {
            if (root->value != 0)
            {
                printTree_post(root, &out);
                out << "\n";
            }
        }
        if (command == "INFIXA")
        {
            if (root->value != 0)
            {
                int count2 = count1;
                printTree_in(root, &out, &count2);
                out << "\n";
            }
        }
    }

    cout << out.str();

    return 0;
}