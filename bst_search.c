/* BST vs Linear Search - reads keys and search targets from a file.
   Usage: ./bst_search data/input.txt
   Input format: n, n keys, m, m targets */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->left = n->right = NULL;
    return n;
}

/* Insert with trace: prints comparison path for each key */
Node *insert(Node *root, int v, int step) {
    printf("Step %d | insert %d | ", step, v);
    if (!root) { printf("tree empty -> root\n"); return newNode(v); }
    Node *cur = root;
    for (;;) {
        if (v < cur->data) {
            printf("%d<%d ", v, cur->data);
            if (!cur->left) { cur->left = newNode(v); printf("-> left child of %d\n", cur->data); break; }
            cur = cur->left;
        } else {
            printf("%d>%d ", v, cur->data);
            if (!cur->right) { cur->right = newNode(v); printf("-> right child of %d\n", cur->data); break; }
            cur = cur->right;
        }
    }
    return root;
}

void inorder(Node *r)   { if (r) { inorder(r->left);  printf("%d ", r->data); inorder(r->right); } }
void preorder(Node *r)  { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int height(Node *r) { if (!r) return -1; int a = height(r->left), b = height(r->right); return 1 + (a > b ? a : b); }

/* Search functions return found(1)/not found(0) and count comparisons */
int searchBST(Node *r, int t, int *cmp) {
    *cmp = 0;
    while (r) { (*cmp)++; if (r->data == t) return 1; r = (t < r->data) ? r->left : r->right; }
    return 0;
}
int searchLinear(int a[], int n, int t, int *cmp) {
    *cmp = 0;
    for (int i = 0; i < n; i++) { (*cmp)++; if (a[i] == t) return 1; }
    return 0;
}

int main(int argc, char **argv) {
    FILE *f = fopen(argc > 1 ? argv[1] : "data/input.txt", "r");
    if (!f) { perror("input file"); return 1; }
    int n, m;
    if (fscanf(f, "%d", &n) != 1) return 1;
    int *keys = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) if (fscanf(f, "%d", &keys[i]) != 1) return 1;
    if (fscanf(f, "%d", &m) != 1) return 1;
    int *targets = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) if (fscanf(f, "%d", &targets[i]) != 1) return 1;
    fclose(f);

    printf("=== BST Insertion Trace ===\n");
    Node *root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, keys[i], i + 1);

    printf("\nBST height: %d\n", height(root));
    printf("Inorder:   "); inorder(root);   printf("\n");
    printf("Preorder:  "); preorder(root);  printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printf("\n=== Search Comparison ===\n");
    printf("%-8s %-10s %-16s %-16s\n", "Key", "Status", "BST comparisons", "Linear comparisons");
    for (int i = 0; i < m; i++) {
        int cb, cl;
        int fb = searchBST(root, targets[i], &cb);
        int fl = searchLinear(keys, n, targets[i], &cl);
        printf("%-8d %-10s %-16d %-16d\n", targets[i], (fb && fl) ? "Found" : "Not Found", cb, cl);
    }
    return 0;
}
