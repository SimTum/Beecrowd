#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node {
    public:
        Node *left = NULL;
        Node *right = NULL;
        int value = 0;
};

Node *insert (int value, Node* root) {
    if (root == NULL) {
        root = new Node();
        root->value = value;
        return root;
    } else {
        if (value < root->value) {
            if (root->left) {
                insert(value, root->left);
            } else {
                root->left = new Node();
                root->left->value = value;
            }
        } else {
            if (root->right) {
                insert(value, root->right);
            } else {
                root->right = new Node();
                root->right->value = value;
            }
        }
        return root;
    }
}

Node* remove (int value, Node* root) {
    if (root == NULL) return NULL;

    if (value == root->value) {
        // Aqui existem três casos:
        // - O node não tem filhos;
        // - O node tem um filho;
        // - O node tem dois filhos;

        // Caso 1: O node não tem filhos
        // Neste caso, basta fazer com que o node pai perca a
        // referência ao node atual, efetivamente "deletando" o node
        if (root->left == NULL && root->right == NULL) {
            // Libera a memória
            delete root;

            // Retorna NULL pois o retorno dessa função
            // é setado como filho do node que a chamou
            return NULL;
        }

        // Caso 2: O node tem um filho
        // Neste caso, basta fazer com que o node pai passe
        // a apontar  para o único filho do node atual
        if ((root->left == NULL) != (root->right == NULL)) {
            // Descobre qual dos filhos é o sucessor antes de deletar o node
            Node* temp = root->left != NULL ? root->left : root->right;

            // Libera a memória
            delete root;

            // Retorna o único filho disponível, que agora passa
            // a ser o novo filho do node que chamou a função
            return temp;
        }

        // Caso 3: O node tem dois filhos
        // Neste caso, precisamos encontrar o node antecessor
        // (maior valor da árvore esquerda) ou sucessor
        // (menor valor da árvore direita) do node a ser removido para
        // colocá-lo no lugar. Neste caso específico, o problema 1201
        // especifica que devemos usar o ANTECESSOR.

        // Encontra o maior node na subárvore esquerda
        Node* temp = root->left;
        while (temp && temp->right) temp = temp->right;

        // Troca o valor do node atual
        root->value = temp->value;

        // Agora que atualizamos o valor da raiz, devemos
        // apagar o antecessor da árvore. Para isso, basta
        // chamar a mesma função atual para remover o valor
        // (atualmente) duplicado. Neste caso o node a ser
        // removido sempre cairá no Caso 1 ou Caso 2, dado que
        // como o antecessor é o maior node da subárvore, ele
        // obrigatoriamente não terá um node à sua  direita.
        root->left = remove(root->value, root->left);
    } else if (value < root->value) {
        root->left = remove(value, root->left);
    } else {
        root->right = remove(value, root->right);
    }

    return root;
}

bool exists(int value, Node* root) {
    if (root == NULL) return false;

    if (value == root->value) return true;

    if (value < root->value) {
        if (root->left) {
            return exists(value, root->left);
        } else {
            return false;
        }
    } else {
        if (root->right) {
            return exists(value, root->right);
        } else {
            return false;
        }
    }
}

void prefix(Node* root, ostringstream* buffer) {
    if (root == NULL) return;
    
    *buffer << root->value << " ";
    prefix(root->left, buffer);
    prefix(root->right, buffer);
}

void infix(Node* root, ostringstream* buffer) {
    if (root == NULL) return;

    infix(root->left, buffer);
    *buffer << root->value << " ";
    infix(root->right, buffer);
}

void postfix(Node* root, ostringstream* buffer) {
    if (root == NULL) return;

    postfix(root->left, buffer);
    postfix(root->right, buffer);
    *buffer << root->value << " ";
}

// estava com saudade de dependency injection
void printTree(Node* root, void (*traversalFunction)(Node*, ostringstream*)) {
    ostringstream buffer;
    traversalFunction(root, &buffer);

    string result = buffer.str();
    if (!result.empty()) result.pop_back(); // Apaga o espaço do final

    cout << result << "\n";
}


int main() {
    Node *root = NULL;
    string input;
    int value;
    
    while (cin >> input) {
        if (input == "I") {
            cin >> value;
            root = insert(value, root);
        } else if (input == "P") {
            cin >> value;
            if (exists(value, root)) {
                cout << value << " existe\n";
            } else {
                cout << value << " nao existe\n";
            };
        } else if (input == "R") {
            cin >> value;
            root = remove(value, root);
        } else if (input == "INFIXA") {
            printTree(root, infix);
        } else if (input == "POSFIXA") {
            printTree(root, postfix);
        } else if (input == "PREFIXA") {
            printTree(root, prefix);
        }
    }
    
    return 0;
}