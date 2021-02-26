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
    traversal(root->r);
    cout << root->val << endl;
}


void traversal_(treeNode* node) {
    stack<treeNode*> node_stack;
    treeNode* pPre = nullptr;
    treeNode* pTmp;
    node_stack.push(node);
    while(!node_stack.empty()) {
        pTmp = node_stack.top();
        if(pTmp->l == nullptr && pTmp->r == nullptr || pPre != nullptr && (pPre == pTmp->r || pPre == pTmp->l)) {
            cout << pTmp-> val << endl;
            node_stack.pop();
            pPre = pTmp;
        }else{
            if(pTmp->r != nullptr) node_stack.push(pTmp->r);
            if(pTmp->l != nullptr) node_stack.push(pTmp->l);
        }
    }
}


int main() {
    treeNode* root;
    root = getNode(1);
    root->l = getNode(2); root->r = getNode(3);
    root->l->l = getNode(4); root->l->r = getNode(5); root->r->l = getNode(6); root->r->r = getNode(7);
    root->l->l->r = getNode(8);
    traversal(root);
}