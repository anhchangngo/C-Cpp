#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void array_random(int *arr, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

typedef struct TreeNode {
    int val;  // node's data store
    struct TreeNode *parent;
    struct TreeNode *tLeft;  // link node on the left
    struct TreeNode *tRight; // link node on the right
} TreeNode;

typedef TreeNode *Tree;

Tree init(int i) {
    Tree t = (Tree)malloc(sizeof(TreeNode));
    t->val = i;
    t->parent = NULL;
    t->tLeft = NULL;
    t->tRight = NULL;
    return t;
}

void insertRight(Tree pa, Tree ri) {
    ri->parent = pa;
    pa->tRight = ri;
}

void insertLeft(Tree pa, Tree le) {
    le->parent = pa;
    pa->tLeft = le;
}

void insertNode(Tree pa) {
    Tree t = init(0);
    if (pa->tLeft == NULL) {
        insertLeft(pa, t);
    } else {
        insertRight(pa, t);
    }
}

void deleteLeft(Tree pa, Tree le) {
    pa->tLeft = NULL;
    free(le);
}

void deleteRight(Tree pa, Tree r) {
    pa->tRight = NULL;
    free(r);
}

void removeLeftNode(Tree t) {
    if (t->tLeft != NULL) {
        deleteLeft(t, t->tLeft);
    }
}

void removeRightNode(Tree t) {
    if (t->tRight != NULL) {
        deleteRight(t, t->tRight);
    }
}

int height(int n) {
    double h = log2(n) + 1;
    double h1;
    double frac = modf(h, &h1);
    if (frac > 0.0) {
        h1++;
    }
    int h2 = (int)h1;
    return h2;
}

int initializeTree(Tree t, int x, int h, int a[], int i, int all) {
    if (h == all && x == 0) {
        if (t->tLeft->val > t->tRight->val) {
            t->val = t->tRight->val;
        } else {
            t->val = t->tLeft->val;
        }
        return 0;
    }

    if (t->tLeft == NULL && t->tRight == NULL) {
        goto Next;
    }

    if (t->tLeft != NULL && t->tRight == NULL) {
        t->val = t->tLeft->val;
        goto Next;
    }

    if (t->tLeft->val > t->tRight->val) {
        t->val = t->tRight->val;
    } else {
        t->val = t->tLeft->val;
    }

Next:
    if ((t->tLeft != NULL) && (t->tRight != NULL)) {
        if (x == 0) {
            return initializeTree(t->parent, x, h + 1, a, i, all);
        } else {
            return initializeTree(t->parent, x, h + 1, a, i, all);
        }
    }

    if (h == 1) {
        t->val = a[i];
        return initializeTree(t->parent, x - 1, h + 1, a, i + 1, all);
    }

    if (x == 0) {
        return initializeTree(t->parent, x, h + 1, a, i, all);
    }

    insertNode(t);

    if (t->tLeft != NULL && t->tRight == NULL) {
        return initializeTree(t->tLeft, x, h - 1, a, i, all);
    } else {
        return initializeTree(t->tRight, x, h - 1, a, i, all);
    }
}

void printTree(Tree t, int n) {
    if (t == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("|>");
        } else {
            printf("   ");
        }
    }
    printf("%d\n", t->val);
    printTree(t->tLeft, n + 1);
    printTree(t->tRight, n + 1);
}

int find(Tree t, int i) {
    if (t == NULL) {
        return 0; // Value not found in the tree
    }

    if (t->val == i) {
        printTree(t, 1);
        return 1; // Value found in the tree
    } else {
        int left_result = find(t->tLeft, i);
        int right_result = find(t->tRight, i);

        return left_result || right_result; // Value found in the current subtree
    }
}

int main() {
    int n;
    printf("Input the number of elements in array: ");
    scanf("%d", &n);

    int arr1[n];

    srand(time(NULL));
    array_random(arr1, n);

    int h = height(n);
    int m = (int)pow(2, h - 1);
    int a[m];

    if (n == m) {
        for (int i = 0; i < n; i++) {
            a[i] = arr1[i];
        }
        goto Next;
    } else {
        int E = 0;
        for (int i = 0; i < n; i++) {
            if (arr1[i] > E) {
                E = arr1[i] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            a[i] = arr1[i];
        }

        for (int i = n; i < m; i++) {
            a[i] = E;
        }
    }
Next:
    printf("Random array :");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Height of tree : %d\n", h);

    Tree t = init(0);
    initializeTree(t, m, h, a, 0, h);

    printf("Display the tree information :\n");
    printTree(t, 1);

    int x;  // value need to find
    printf("\nEnter a value to search in the tree :");
    scanf("%d", &x);

    int val = find(t, x);
    if (!val) {
        printf("Value not found in the tree\n");
    }

    int y; // remove choice
    printf("\nDo you want to remove the left (input 1) child or right (input 2) child of the root? Enter 0 to skip: ");
    scanf("%d", &y);
    if (y < 0 || y > 2) {
        printf("Your choice is not satisfied\n");
    } else if (y == 1) {
        removeLeftNode(t);
    } else if (y == 2) {
        removeRightNode(t);
    }

    printf("Information of tree after removing a node:\n");
    printTree(t, 1);
    return 0;
}
