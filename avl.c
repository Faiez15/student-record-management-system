/*
 * Student Record Search using AVL Tree
 * Compile: gcc avl.c -o avl
 * Run:     ./avl
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int regNo, height;
    struct Node *left, *right;
} Node;

int comparisons = 0;

int max(int a, int b) { return a > b ? a : b; }
int nodeHeight(Node *n) { return n ? n->height : 0; }

Node *newNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->regNo=key; n->left=n->right=NULL; n->height=1;
    return n;
}

int balanceFactor(Node *n) {
    return n ? nodeHeight(n->left)-nodeHeight(n->right) : 0;
}

Node *rightRotate(Node *y) {
    Node *x=y->left, *t2=x->right;
    x->right=y; y->left=t2;
    y->height=1+max(nodeHeight(y->left),nodeHeight(y->right));
    x->height=1+max(nodeHeight(x->left),nodeHeight(x->right));
    return x;
}

Node *leftRotate(Node *x) {
    Node *y=x->right, *t2=y->left;
    y->left=x; x->right=t2;
    x->height=1+max(nodeHeight(x->left),nodeHeight(x->right));
    y->height=1+max(nodeHeight(y->left),nodeHeight(y->right));
    return y;
}

Node *insert(Node *node, int key) {
    if (!node) return newNode(key);
    if (key < node->regNo) node->left=insert(node->left,key);
    else if (key > node->regNo) node->right=insert(node->right,key);
    else return node;

    node->height=1+max(nodeHeight(node->left),nodeHeight(node->right));
    int b=balanceFactor(node);

    if (b>1 && key<node->left->regNo) return rightRotate(node);       /* LL */
    if (b<-1 && key>node->right->regNo) return leftRotate(node);      /* RR */
    if (b>1 && key>node->left->regNo) {                                /* LR */
        node->left=leftRotate(node->left); return rightRotate(node);
    }
    if (b<-1 && key<node->right->regNo) {                              /* RL */
        node->right=rightRotate(node->right); return leftRotate(node);
    }
    return node;
}

Node *search(Node *root, int key) {
    while (root) {
        comparisons++;
        if (key==root->regNo) return root;
        root = key<root->regNo ? root->left : root->right;
    }
    return NULL;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left); printf("%d ",root->regNo); inorder(root->right);
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left); freeTree(root->right); free(root);
}

int main(void) {
    int data[] = {105,110,115,120,125,130,135,140,145,150,
                  155,160,165,170,175,180,185,190,195,200,
                  205,210,215,220,225,230,235,240,245,250};
    int n=sizeof(data)/sizeof(data[0]);
    Node *root=NULL;
    for (int i=0;i<n;i++) root=insert(root,data[i]);

    printf("AVL - Student Record Search\n");
    printf("Records inserted: %d\n",n);
    printf("Inorder traversal: "); inorder(root); printf("\n");
    printf("Tree height (levels): %d\n",nodeHeight(root));

    int key=175;
    comparisons=0;
    Node *found=search(root,key);
    printf("Successful search %d: %s; comparisons = %d\n",
           key,found?"FOUND":"NOT FOUND",comparisons);

    key=999;
    comparisons=0;
    found=search(root,key);
    printf("Unsuccessful search %d: %s; comparisons = %d\n",
           key,found?"FOUND":"NOT FOUND",comparisons);

    root=insert(root,252);
    comparisons=0;
    found=search(root,252);
    printf("After inserting 252, search: %s; comparisons = %d\n",
           found?"FOUND":"NOT FOUND",comparisons);
    printf("Height after insertion (levels): %d\n",nodeHeight(root));

    freeTree(root);
    return 0;
}
