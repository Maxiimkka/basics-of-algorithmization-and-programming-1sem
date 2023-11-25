#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    string data;
    Node* left;
    Node* right;
};

// ������� ��� ���������� ���� � ������
Node* addNode(Node* root, int key, string data) {
    // ���� ������ ������, ������� ������
    if (root == NULL) {
        root = new Node;
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    // ���� ���� ������ �����, ��������� � ����� ���������
    else if (key < root->key) {
        root->left = addNode(root->left, key, data);
    }
    // ���� ���� ������ �����, ��������� � ������ ���������
    else {
        root->right = addNode(root->right, key, data);
    }
    return root;
}
int countPath(Node* root, int key) {
    // ������� ������: ���� ������ ������, �� ���-�� ������ ����� 0
    if (root == NULL) {
        return 0;
    }
    // ���� ���� ���� ����� �������� �����, �� ���������� ������ �� ���� ����� 1
    if (root->key == key) {
        return 1;
    }

    // ���� ���� � ����� ���������
    int leftCount = countPath(root->left, key);
    // ���� ����� ���� � ����� ���������, �� ��������� 1 � ���������� ��������
    if (leftCount > 0) {
        return leftCount + 1;
    }

    // ���� ���� � ������ ���������
    int rightCount = countPath(root->right, key);
    // ���� ����� ���� � ������ ���������, �� ��������� 1 � ���������� ��������
    if (rightCount > 0) {
        return rightCount + 1;
    }

    // ���� ���� �� ������ � ������� ���������, �� ���������� 0
    return 0;

}

// ������� ��� ������ ���� � ������ �� �����
Node* findNode(Node* root, int key) {
    // ���� ������ ������ ��� ���� ������ � �����
    if (root == NULL || root->key == key) {
        return root;
    }
    // ���� ���� ������ �����, ���� � ����� ���������
    else if (key < root->key) {
        return findNode(root->left, key);
    }
    // ���� ���� ������ �����, ���� � ������ ���������
    else {
        return findNode(root->right, key);
    }
}

// ������� ��� �������� ���������� ������ �� ���� � �������� ������
int countPath(Node* root, int key) {
    // ���� ������ ������ ��� ���� ������ � �����
    if (root == NULL || root->key == key) {
        return 0;
    }
    // ���� ���� ������ �����, ���� � ����� ���������
    else if (key < root->key) {
        return 1 + countPath(root->left, key);
    }
    // ���� ���� ������ �����, ���� � ������ ���������
    else {
        return 1 + countPath(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    // ��������� ���� � ������
    root = addNode(root, 10, "Data 10");
    root = addNode(root, 5, "Data 5");
    root = addNode(root, 15, "Data 15");
    root = addNode(root, 3, "Data 3");
    root = addNode(root, 8, "Data 8");
    root = addNode(root, 12, "Data 12");
    root = addNode(root, 20, "Data 20");

    int key = 12;
    // ���� ���� �� �����
    Node* node = findNode(root, key);
    if (node != NULL) {
        // ������������ ���������� ������ �� ����
        int count = countPath(root, key);
        cout << "Number of branches to node with key " << key << endl;
        if (node->key == key) {
            // ������� ������ ��� �������� ���� �� ����
            vector<int> path;
            // ������� ������ �� ����� �� ���� � ��������� ������ path   TreeNode* curr = root;

            while (curr != NULL && curr->key != key) {
                path.push_back(curr->key);
                if (key < curr->key) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            path.push_back(key);

            // ������� ���� �� ����
            cout << "���� �� ������� � ������ " << key << ":\n";
            for (int i = 0; i < path.size() - 1; i++) {
                cout << path[i] << " -> ";
            }
            cout << path[path.size() - 1] << endl;

            // ������� ���������� ������ �� ����
            cout << "���������� ������ �� ������� � ������ " << key << ": " << path.size() - 1 << endl;
        }
        // ���� �������� ���� ������ �������� �����, ���� �����
        else if (node->key > key) {
            countPathUtil(node->left, key, root);
        }
        // ���� �������� ���� ������ �������� �����, ���� ������
        else {
            countPathUtil(node->right, key, root);
        }

    else {
        cout << "������� � ������ " << key << " �� �������" << endl;
    }
    }