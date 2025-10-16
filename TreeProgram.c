#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int item) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct TreeNode* insert(struct TreeNode *root, int item) {
    if (root == NULL)
        return createNode(item);

    struct TreeNode *ptr = root, *par = NULL;
    while (ptr != NULL) {
        par = ptr;
        if (item == ptr->data) {
            printf("Already exists %d\n", item);
            return root;
        } 
		else if (item < ptr->data) {
            ptr = ptr->left;
        } 
		else {
            ptr = ptr->right;
        }
    }

    if (item < par->data)
        par->left = createNode(item);
    else
        par->right = createNode(item);

    return root;
}

void preorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void conversePreorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    conversePreorder(root->right);
    conversePreorder(root->left);
}

void converseInorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    converseInorder(root->right);
    printf("%d ", root->data);
    converseInorder(root->left);
}

void conversePostorder(struct TreeNode *root) {
    if (root == NULL)
        return;
    conversePostorder(root->right);
    conversePostorder(root->left);
    printf("%d ", root->data);
}

void search(struct TreeNode *root, int item) {
    struct TreeNode *ptr = root;
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Found %d\n", item);
            return;
        }
        if (item < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    printf("Not Found %d\n", item);
}

// Case A  Node has 0 or 1 child
struct TreeNode* caseA(struct TreeNode* root, struct TreeNode* ptr, struct TreeNode* par, int item) {
    struct TreeNode* child = NULL;

    if (ptr->left != NULL && ptr->right != NULL) {
        return root;
    }

    if (ptr->left == NULL && ptr->right == NULL)
        child = NULL;
    else if (ptr->left != NULL)
        child = ptr->left;
    else
        child = ptr->right;

    if (par == NULL)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    free(ptr);
    return root;
}


struct TreeNode* caseB(struct TreeNode* root, struct TreeNode* ptr, struct TreeNode* par, int item) {
    struct TreeNode *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->right;//Successor
    while (succ->left != NULL) {
        parsucc = succ;
        succ = succ->left;
    }
    ptr->data = succ->data;
    root = caseA(root, succ, parsucc, succ->data);
    return root;
}

// Delete Function
struct TreeNode* del(struct TreeNode* root, int item) {
    struct TreeNode *ptr = root, *par = NULL;

    // Find node
    while (ptr != NULL && ptr->data != item) {
        par = ptr;
        if (item < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (ptr == NULL) {
        printf("Not found %d\n", item);
        return root;
    }

    
    if (ptr->left != NULL && ptr->right != NULL)
        root = caseB(root, ptr, par, item);
    else
        root = caseA(root, ptr, par, item);

    printf("\nDeleted %d\n", item);
    return root;
}

int main() {
    struct TreeNode *root = NULL;

    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);

    search(root, 4);
    search(root, 5);

    printf("\n--- Normal Traversals ---\n");
    printf("Preorder -> ");
    preorder(root);
    printf("\n");

    printf("Inorder -> ");
    inorder(root);
    printf("\n");

    printf("Postorder -> ");
    postorder(root);
    printf("\n");

    printf("\n--- Converse Traversals ---\n");
    printf("Converse Preorder -> ");
    conversePreorder(root);
    printf("\n");

    printf("Converse Inorder -> ");
    converseInorder(root);
    printf("\n");

    printf("Converse Postorder -> ");
    conversePostorder(root);
    printf("\n");

    
    root = del(root, 3);
    root = del(root, 5); 

    printf("\nAfter Deletions (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}

