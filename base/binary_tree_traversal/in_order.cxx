#include <iostream>
#include <stack>

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
    if(root == nullptr) return;
    traversal(root->l);
    cout << root->val << endl;
    traversal(root->r);
}


void traversal_(treeNode* root) {
    stack<treeNode*> node_stack;
    treeNode* temp = root;
    while(!node_stack.empty() || temp != nullptr) {
        while(temp != nullptr) {
            node_stack.push(temp);
            temp = temp->l;
        }
        if(!node_stack.empty()) {
            temp = node_stack.top();
            cout << temp->val << endl;
            node_stack.pop();
            temp = temp->r;
        }
    }
}


int main() {
    treeNode* root;
    root = getNode(1);
    root->l = getNode(2); root->r = getNode(3);
    root->l->l = getNode(4); root->l->r = getNode(5); root->r->l = getNode(6); root->r->r = getNode(7);
    traversal(root);
}