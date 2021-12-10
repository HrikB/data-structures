#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* treeRoot;

struct TreeNode* GetNewNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* Insert(struct TreeNode* root, int data) {
    //empty tree
    if(root == NULL) {
        struct TreeNode* newNode = GetNewNode(data);    
        return newNode;
    }      
    else if(data <= root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

int Search(struct TreeNode* root, int data) {
    if(root == NULL)    return 0;
    else if(root->data == data) return 1;
    else if(data <= root->data) return Search(root->left, data);
    else    return Search(root->right, data);
}

struct TreeNode* Min(struct TreeNode* root) {
    if(root->left == NULL) {
        return root;
    }
    return Min(root->left);
}

int Max(struct TreeNode* root) {
    if (root->right == NULL) {
        return root->data;
    }
    return Max(root->right);
}

int GetHeight(struct TreeNode* root) {
    if(root == NULL) {
        return -1;
    }
    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);
    if(leftHeight >= rightHeight) return leftHeight + 1;
    return rightHeight + 1;
}

void TraversePreorder(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    TraversePreorder(root->left);
    TraversePreorder(root->right);
}

void TraverseInorder(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    TraverseInorder(root->left);
    printf("%d ", root->data);
    TraverseInorder(root->right);
}

void TraversePostorder(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    TraversePostorder(root->left);
    TraversePostorder(root->right);
    printf("%d ", root->data);
}

//helper
int isBST(struct TreeNode* root) {
    IsBST(root, INT_MIN, INT_MAX);
}

int IsBST(struct TreeNode* root, int min, int max) {
    if(root == NULL) return 1;
    if(root->data > min && root->data < max && IsBST(root->left, min, root->data) && IsBST(root->right, root->data, max)) return 1;
    return 0;
}

struct TreeNode* Delete(struct TreeNode* root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {  //Found node to be deleted
        //No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        
        //One child
        else if(root->left == NULL) {
            struct TreeNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct TreeNode* temp = root;
            root = root->left;
            free(temp);
        }
        //2 children
        else {
            struct TreeNode *temp = Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }
}

struct TreeNode* SearchGetRef(struct TreeNode* root, int data) {
    if (root == NULL) return root;
    else if (root->data == data) return root;
    else if (data <= root->data) return SearchGetRef(root->left, data);
    else return SearchGetRef(root->right, data);
}

int GetInorderSuccessor(struct TreeNode* root, int data) {
    struct TreeNode* curr = SearchGetRef(root, data); 
    if(curr == NULL) return NULL;
    //If has right subtree
    if(curr->right != NULL) {
        //Finds minimum node pointer
        struct TreeNode* temp = curr->right;
        while(temp->left != NULL) temp = temp->left;
        return temp->data;
    }
    //No right subtree
    else {
        struct TreeNode* successor = NULL;
        struct TreeNode* ancestor = root;
        while(ancestor != curr) {
            if(curr->data < ancestor->data) {
                successor = ancestor;   
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
            
        }
        return successor->data;
    }
}

int main(){
    treeRoot = NULL;
    treeRoot = Insert(treeRoot, 5);
    treeRoot = Insert(treeRoot, 15);
    treeRoot = Insert(treeRoot, 7);
    treeRoot = Insert(treeRoot, 3);
    treeRoot = Insert(treeRoot, 8);
    treeRoot = Insert(treeRoot, 4);
    treeRoot = Insert(treeRoot, 20);
    if(Search(treeRoot, 8)) {
        printf("Found!\n");
    } else {
        printf("Not found\n");
    }
    printf("Min: %d\n", Min(treeRoot)->data);
    printf("Max: %d\n", Max(treeRoot));
    printf("Height: %d\n", GetHeight(treeRoot));
    TraversePreorder(treeRoot); printf("\n");
    TraverseInorder(treeRoot); printf("\n");
    TraversePostorder(treeRoot); printf("\n");
    
    printf("isBst? %d\n", isBST(treeRoot));
    printf("%d ", GetInorderSuccessor(treeRoot, 4));
}
