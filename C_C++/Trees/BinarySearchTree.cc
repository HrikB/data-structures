#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

class BinarySearchTree
{

    struct TreeNode
    {
        int data;
        TreeNode *left;
        TreeNode *right;
    };

private:
    TreeNode *root;

    TreeNode *GetNewTreeNode(int data)
    {
        TreeNode *newTreeNode = new TreeNode;
        newTreeNode->data = data;
        newTreeNode->left = newTreeNode->right = NULL;
        return newTreeNode;
    }

    TreeNode *Insert(TreeNode *root, int data)
    {
        if (root == NULL)
            return GetNewTreeNode(data);
        else if (data <= root->data)
            root->left = Insert(root->left, data);
        else
            root->right = Insert(root->right, data);
        return root;
    }

    bool Search(TreeNode *root, int data)
    {
        if (root == NULL)
            return false;
        else if (root->data == data)
            return true;
        else if (data <= root->data)
            return Search(root->left, data);
        else
            return Search(root->right, data);
    }

    TreeNode *SearchGetRef(TreeNode *root, int data)
    {
        if (root == NULL)
            return root;
        else if (root->data == data)
            return root;
        else if (data <= root->data)
            return SearchGetRef(root->left, data);
        else
            return SearchGetRef(root->right, data);
    }

    TreeNode *Min(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        Min(root->left);
    }

    int Max(TreeNode *root)
    {
        if (root->right == NULL)
        {
            return root->data;
        }
        return Max(root->right);
    }

    int FindHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        int rightHeight = FindHeight(root->right);
        int leftHeight = FindHeight(root->left);
        if (leftHeight >= rightHeight)
            return leftHeight + 1;
        return rightHeight + 1;
    }

    void TraversePreorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        TraversePreorder(root->left);
        TraversePreorder(root->right);
    }

    void TraverseInorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        TraverseInorder(root->left);
        cout << root->data << " ";
        TraverseInorder(root->right);
    }

    void TraversePostorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        TraversePostorder(root->left);
        TraversePostorder(root->right);
        cout << root->data << " ";
    }

    bool IsBST(TreeNode *root, int min, int max)
    {
        if (root == NULL)
            return 1;
        if (root->data > min && root->data < max && IsBST(root->left, min, root->data) && IsBST(root->right, root->data, max))
            return 1;
        return 0;
    }

    TreeNode *Delete(TreeNode *root, int data)
    {
        if (root == NULL)
            return root;
        else if (data < root->data)
            root->left = Delete(root->left, data);
        else if (data > root->data)
            root->right = Delete(root->right, data);
        else
        { //Found node to be deleted
            //No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            //One child
            else if (root->left == NULL)
            {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                TreeNode *temp = Min(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
            return root;
        }
    }

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void Insert(int data)
    {
        root = Insert(root, data);
    }

    bool Search(int data)
    {
        return Search(root, data);
    }

    int Min()
    {
        return Min(root)->data;
    }

    int Max()
    {
        return Max(root);
    }

    int FindHeight()
    {
        return FindHeight(root);
    }

    void TraverseLevelOrder()
    {
        if (root == NULL)
            return;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *current = Q.front();
            cout << current->data << " ";
            if (current->left != NULL)
                Q.push(current->left);
            if (current->right != NULL)
                Q.push(current->right);
            Q.pop();
        }
    }

    void TraversePreorder()
    {
        TraversePreorder(root);
    }

    void TraverseInorder()
    {
        TraverseInorder(root);
    }

    void TraversePostorder()
    {
        TraversePostorder(root);
    }

    bool IsBST()
    {
        IsBST(root, INT_MIN, INT_MAX);
    }

    TreeNode *Delete(int data)
    {
        Delete(root, data);
    }

    int GetInorderSuccessor(int data)
    {
        TreeNode *curr = SearchGetRef(root, data);
        if (curr == NULL)
            return INT_MIN;
        //has right subtree
        if (curr->right != NULL)
        {
            TreeNode *temp = curr->right;
            while (temp->left != NULL)
                temp = temp->left;
            return temp->data;
        }
        //no right subtree
        else
        {
            TreeNode *ancestor = NULL;
            TreeNode *successor = root;
            while (successor != curr)
            {
                if (curr->data < successor->data)
                {
                    ancestor = successor;
                    successor = successor->left;
                }
                else
                {
                    successor = successor->right;
                }
            }
            return ancestor->data;
        }
    }
};

int main()
{
    BinarySearchTree tree;

    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(4);

    if (tree.Search(9))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found\n");
    }

    printf("Min: %d\n", tree.Min());
    printf("Max: %d\n", tree.Max());

    printf("Height: %d\n", tree.FindHeight());
    tree.TraverseLevelOrder();
    printf("\n");
    tree.TraversePreorder();
    printf("\n");
    tree.TraverseInorder();
    printf("\n");
    tree.TraversePostorder();
    printf("\n");

    cout << "IsBST? " << tree.IsBST() << "\n";

    tree.Delete(15);
    tree.TraversePreorder();
    printf("\n");

    cout << "InorderSuccessor " << tree.GetInorderSuccessor(8);
}
