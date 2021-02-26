# 二叉树的遍历

参考链接: https://blog.csdn.net/My_Jobs/article/details/43451187

## 先序(深度优先遍历)

### 递归形式

```c++
void traversal(treeNode* root) {
    if(root == nullptr) return;
    cout << root->val << endl;
    traversal(root->l);
    traversal(root->r);
}
```

### 非递归形式

```c++
void traversal_(treeNode* node) {
    stack<treeNode*> node_stack;
    treeNode* temp = node;
    while(!node_stack.empty() || temp != nullptr) {
        while(temp != nullptr) {
            cout << temp->val << endl;
            node_stack.push(temp);
            temp = temp->l;
        }

        if(!node_stack.empty()) {
            temp = node_stack.top();
            node_stack.pop();
            temp = temp->r;
        }   
    }
}
```

## 中序(深度优先遍历)

### 递归形式

```c++
void traversal(treeNode* root) {
    if(root == nullptr) return;
    traversal(root->l);
    cout << root->val << endl;
    traversal(root->r);
}
```

### 非递归形式

```c++
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
```

## 后序(深度优先遍历)

### 递归形式

```c++
void traversal(treeNode* root) {
    if(root == nullptr) return;
    traversal(root->l);
    traversal(root->r);
    cout << root->val << endl;
}
```

### 非递归形式

```c++
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
```


## 层序(广度优先遍历)

### 队列实现

```c++
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
```