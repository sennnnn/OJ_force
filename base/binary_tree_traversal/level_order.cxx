#include <iostream>
#include <queue>

using namespace std;


struct treeNode {
    int val;
    treeNode* l;
    treeNode* r;
};


treeNode* getNode(int val) {
    treeNode* pointer = new treeNode();
    pointer->val = val;
    pointer->l = nullptr;
    pointer->r = nullptr;
    return pointer;
}


void traversal(treeNode* root) {
    queue<treeNode*> node_queue;
    node_queue.push(root);
    treeNode* temp;
    while(!node_queue.empty()) {
        temp = node_queue.front();
        cout << temp->val << endl;
        node_queue.pop();
        if(temp->l != nullptr) node_queue.push(temp->l);
        if(temp->r != nullptr) node_queue.push(temp->r);
    }
}


int main() {
    treeNode* root;
    root = getNode(1);
    root->l = getNode(2); root->r = getNode(3);
    root->l->l = getNode(4); root->l->r = getNode(5); root->r->l = getNode(6); root->r->r = getNode(7);
    root->r->r->r = getNode(8); root->l->l->l = getNode(11);
    traversal(root);
}