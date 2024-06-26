#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int freq;
    int size;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_node(int key, int freq) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->freq = freq;
    node->size = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* build_tree(int keys[], int freq[], int left, int right) {
    if (left > right)
        return NULL;
    if (left == right)
        return new_node(keys[left], freq[left]);
    int mid = left;
    for (int i = left + 1; i <= right; i++) {
        if (freq[i] > freq[mid])
            mid = i;
    }
    Node *node = new_node(keys[mid], freq[mid]);
    node->left = build_tree(keys, freq, left, mid - 1);
    node->right = build_tree(keys, freq, mid + 1, right);
    node->size = node->left->size + node->right->size + node->freq;
    return node;
}

int search(Node *root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return root->freq;
    if (root->key > key)
        return search(root->left, key);
    return search(root->right, key) + root->freq;
}

int main() {
    int keys[] = {1, 2, 3, 4, 5};
    int freq[] = {5, 9, 2, 8, 7};
    int n = sizeof(keys) / sizeof(keys[0]);
    Node *root = build_tree(keys, freq, 0, n - 1);
    printf("Total cost of all searches: %d\n", search(root, 5));
    return 0;
} 