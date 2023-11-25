#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    string data;
    Node* left;
    Node* right;
};

// Функция для добавления узла в дерево
Node* addNode(Node* root, int key, string data) {
    // Если дерево пустое, создаем корень
    if (root == NULL) {
        root = new Node;
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    // Если ключ меньше корня, добавляем в левое поддерево
    else if (key < root->key) {
        root->left = addNode(root->left, key, data);
    }
    // Если ключ больше корня, добавляем в правое поддерево
    else {
        root->right = addNode(root->right, key, data);
    }
    return root;
}
int countPath(Node* root, int key) {
    // Базовый случай: если дерево пустое, то кол-во ветвей равно 0
    if (root == NULL) {
        return 0;
    }
    // Если ключ узла равен искомому ключу, то количество ветвей до узла равно 1
    if (root->key == key) {
        return 1;
    }

    // Ищем ключ в левом поддереве
    int leftCount = countPath(root->left, key);
    // Если нашли ключ в левом поддереве, то добавляем 1 и возвращаем значение
    if (leftCount > 0) {
        return leftCount + 1;
    }

    // Ищем ключ в правом поддереве
    int rightCount = countPath(root->right, key);
    // Если нашли ключ в правом поддереве, то добавляем 1 и возвращаем значение
    if (rightCount > 0) {
        return rightCount + 1;
    }

    // Если ключ не найден в текущем поддереве, то возвращаем 0
    return 0;

}

// Функция для поиска узла в дереве по ключу
Node* findNode(Node* root, int key) {
    // Если дерево пустое или ключ найден в корне
    if (root == NULL || root->key == key) {
        return root;
    }
    // Если ключ меньше корня, идем в левое поддерево
    else if (key < root->key) {
        return findNode(root->left, key);
    }
    // Если ключ больше корня, идем в правое поддерево
    else {
        return findNode(root->right, key);
    }
}

// Функция для подсчета количества ветвей до узла с заданным ключом
int countPath(Node* root, int key) {
    // Если дерево пустое или ключ найден в корне
    if (root == NULL || root->key == key) {
        return 0;
    }
    // Если ключ меньше корня, идем в левое поддерево
    else if (key < root->key) {
        return 1 + countPath(root->left, key);
    }
    // Если ключ больше корня, идем в правое поддерево
    else {
        return 1 + countPath(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    // Добавляем узлы в дерево
    root = addNode(root, 10, "Data 10");
    root = addNode(root, 5, "Data 5");
    root = addNode(root, 15, "Data 15");
    root = addNode(root, 3, "Data 3");
    root = addNode(root, 8, "Data 8");
    root = addNode(root, 12, "Data 12");
    root = addNode(root, 20, "Data 20");

    int key = 12;
    // Ищем узел по ключу
    Node* node = findNode(root, key);
    if (node != NULL) {
        // Подсчитываем количество ветвей до узла
        int count = countPath(root, key);
        cout << "Number of branches to node with key " << key << endl;
        if (node->key == key) {
            // создаем вектор для хранения пути до узла
            vector<int> path;
            // обходим дерево от корня до узла и заполняем вектор path   TreeNode* curr = root;

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

            // выводим путь до узла
            cout << "Путь до вершины с ключом " << key << ":\n";
            for (int i = 0; i < path.size() - 1; i++) {
                cout << path[i] << " -> ";
            }
            cout << path[path.size() - 1] << endl;

            // выводим количество ветвей до узла
            cout << "Количество ветвей до вершины с ключом " << key << ": " << path.size() - 1 << endl;
        }
        // если значение узла больше искомого ключа, идем влево
        else if (node->key > key) {
            countPathUtil(node->left, key, root);
        }
        // если значение узла меньше искомого ключа, идем вправо
        else {
            countPathUtil(node->right, key, root);
        }

    else {
        cout << "Вершина с ключом " << key << " не найдена" << endl;
    }
    }