#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* childs[26];
    bool end;
};


struct TrieNode* newNode() {
    struct TrieNode* node = new TrieNode();
    for (int i=0; i<26; i++)
        node->childs[i] = NULL;
    node->end = false;
    return node;
}


void insert(struct TrieNode* root, string word) {
    struct TrieNode* current = root;
    for (int i=0; i<word.size(); i++) {
        int index = word[i] - 'a';
        if (!current->childs[index])
            current->childs[index] = newNode();
        current = current->childs[index];
    }
    current->end = true;
}


bool search(struct TrieNode* root, string word) {
    struct TrieNode* current = root;
    for (int i=0; i<word.size(); i++) {
        int index = word[i] - 'a';
        if (!current->childs[index])
            return false;
        current = current->childs[index];
    }
    return (current != NULL && current->end);
}

int main() {
    
}
