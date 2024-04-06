// binary search khong co phan tu nao giong nhau

/*
6 cach duyet
  -  NLR
  -  NRL
  -  LNR
  -  RNL
  -  RLN
  -  LRN
*/

/*
Tim kiem tren cay nhi phan
   - cac Node co 2 con (ton tai ca cay con phai va cay con trai)
   - cac Node co 1 con (ton tai cay con trai KHONG ton tai cay con phai OR nguoc lai)
   - cac Node la (Node k co con nao)
   - tim MAX , MIN
   - 
*/

/*
Xoa 1 node bat ki trong cay nhi phan tim kiem
Node X la node can xoa:
1. Node la : xoa binh thuong - boi vi luc nay node x dg la node tu do
2. Node 1 con : truoc khi xoa node x cap nhat moi lket giua node cha cua node x vs node con (trai or phai) cua node
3. Node 2 con : truoc khi xoa xoa ta can tim 1 node the mang cho node can xoa
 - Tim node the mang phai dam bao quy tac cay nhi phan tim kiem
 + Tim node trai nhat cua cay con phai (cay con phai cua node can xoa)
 + Tim node phai nhat cua cay con trai (cay con trai cua cai node can xoa)

//BFS - breath-first search (level order traverse)
    //visit all nodes level by level from left to right - using queue
//DFS - depth-first search 
    //find the node with no childe=ren and then backtrack it - using stack
    //three types of DFS
    //Tree traversal - visiting (checking and/or updating)
    // L before R => left to right 
    // R before L => right to left
        //pre-oder: NLR (root, left, right)
            //display the data part of the root (current code)
            //traverse the left subtree by recursive
            //traverse the right 
        //in-order LNR (left, root, right)
            //traverse left by recursive
            //display the data part of the root (or cur node)
            //right by recursive
        //post-order (left, right, root)
            //left recursive
            //right recursive
            //display the data part 
//for example:
//tree: 
5(r)    12  18  4 (Left)
                13
    7   69 (Right)
//Inorder: 4 18 13 12 5 7 69
//Pre-order: 5 12 18 4 13 7 69
//Post-order: 4 13 18 12 69 7 5

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


typedef struct TreeNode {
    int val;  // du lieu ma node luu tru
    struct TreeNode *parent;
    struct TreeNode *tLeft;  // node lien ket ben trai
    struct TreeNode *tRight; // node lien ket ben phai
} TreeNode;

typedef TreeNode* Tree;

Tree init(int val){
    // initialize a tree node with a specific value
    Tree tree = (Tree)malloc(sizeof(TreeNode));
    tree->val = val;   
    tree->tLeft = NULL;
    tree->tRight = NULL;
    return tree;
}

// ham them phan tu vao cay nhi phan
Tree insert(Tree tree, int x){  // x la phan tu them vao
    // neu cay rong
    if(tree == NULL){  // cay khong ton tai phan tu
        tree = init(x);
        return tree;
    }
    else{ // cay co ton tai phan tu (nho qua trai, lon qua phai)
    // neu phan tu them vao ma nho hon node goc -> them no vao ben trai
    if(tree->val > x){
        tree->tLeft = insert((tree->tLeft), x); // duyet qua trai de them phan tu x
    }
    else if(tree->val < x){ // neu phan tu them vao lon hon nut goc -> them phai
        tree->tRight = insert((tree->tRight), x);
    }
    }
    return tree;
}

// ham xuat cay nhi phan theo NLR
void Duyet_NLR(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        printf("%d ", t->val);   // xuat du lieu trong node
        Duyet_NLR(t->tLeft);  // duyet qua trai
        Duyet_NLR(t->tRight);  // duyet qua phai
    }
}

// ham xuat cay nhi phan theo NRL
void Duyet_NRL(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        printf("%d ", t->val);   // xuat du lieu trong node
        Duyet_NRL(t->tRight);  // duyet qua phai
        Duyet_NRL(t->tLeft);  // duyet qua trai
    }
}

// ham xuat cay nhi phan theo LNR <-> in ra cac phan tu tu be den lon
void Duyet_LNR(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        Duyet_LNR(t->tLeft);  // duyet qua trai
        printf("%d ", t->val);   // xuat du lieu trong node
        Duyet_LNR(t->tRight);  // duyet qua phai
    }
}

// ham xuat cay nhi phan theo RNL <-> in ra cac phan tu tu lon ve be
void Duyet_RNL(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        Duyet_RNL(t->tRight);  // duyet qua phai
        printf("%d ", t->val);   // xuat du lieu trong node
        Duyet_RNL(t->tLeft);  // duyet qua trai
    }
}

// ham xuat cay nhi phan theo LRN
void Duyet_LRN(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        Duyet_LRN(t->tLeft);  // duyet qua trai
        Duyet_LRN(t->tRight);  // duyet qua phai
        printf("%d ", t->val);   // xuat du lieu trong node
    }
}

// ham xuat cay nhi phan theo RLN
void Duyet_RLN(Tree t) {
    // duyet cay cho den het
    if (t != NULL) {
        Duyet_RLN(t->tRight);  // duyet qua phai        
        Duyet_RLN(t->tLeft);  // duyet qua trai
        printf("%d ", t->val);   // xuat du lieu trong node
    }
}

// TimKiem
// Neu node co ton tai trong cay -> tra ve node do còn khong tra ve NULL
Tree Find(Tree t, int x){
    if(t == NULL){
        return NULL;
    }
    else{
        // neu phan tu can tim kiem nho hon node goc -> de quy sang trai de tim
        if(x < t->val){
            return Find(t->tLeft, x);
        }
        // neu phan tu can tim kiem lon hon node goc -> de quy sang phai de tim
        else if (x > t->val){
            return Find(t->tRight, x);
        }
        else {  // x = t->val
            return t;
        }
    }
}

// Tim cac Node co 2 con
void Node_Has_2(Tree t){
    if(t != NULL){
        if(t->tLeft != NULL && t->tRight != NULL){
            printf("%d ", t->val);
        }
        Node_Has_2(t->tLeft);
        Node_Has_2(t->tRight);
    }
}

// Tim cac Node co 1 con
void Node_Has_1(Tree t){
    if(t != NULL){
        if((t->tLeft != NULL && t->tRight == NULL) || (t->tLeft == NULL && t->tRight != NULL)){
            printf("%d ", t->val);
        }
        Node_Has_2(t->tLeft);
        Node_Has_2(t->tRight);
    }
}

// Tim Node la
void Node_leaves(Tree t){
    if(t != NULL){
        if((t->tLeft == NULL) && (t->tRight == NULL)){
            printf("%d ", t->val);
        }
        Node_Has_2(t->tLeft);
        Node_Has_2(t->tRight);
    }
}

// Tim phan tu lon nhat trong cay
int MAX = INT_MIN;  // gan bien MAX la gia tri nho nhat
void FindMax(Tree t){
    if(t != NULL){
        if(MAX < t->val){
            MAX = t->val; // cap nhat lai gia tri va gan bien MAX
        }
        FindMax(t->tLeft);
        FindMax(t->tRight);
    }
}

// Tim phan tu be nhat trong cay
int MIN = INT_MAX;  // gan bien MAX la gia tri nho nhat
void FindMin(Tree t){
    if(t != NULL){
        if(MIN < t->val){
            MIN = t->val; // cap nhat lai gia tri va gan bien MAX
        }
        FindMin(t->tLeft);
        FindMin(t->tRight);
    }
}

// Cach 2 tim MAX
int FinMax2(Tree t){
  // Neu node la node la
  if(t->tRight == NULL){
    return t->val;
  }
  return FinMax2(t->tRight); // duyet sang node cuoi cung nhat cua cay con phai -> tim gtri lon nhat
}

// Cach 2 tim MIN
int FinMin2(Tree t){
  // Neu node la node la
  if(t->tLeft == NULL){
    return t->val;
  }
  return FinMin2(t->tLeft); // duyet sang node cuoi cung nhat cua cay con trai -> tim gtri be nhat
}

// ham di tim node the mang
void DiTimNodeTheMang(Tree X, Tree Y){  // Tree temp1 = t->tRight
  // duyet sang ben trai nhat cua cay con phai
  if(Y->tLeft != NULL){
    DiTimNodeTheMang(X, Y->tLeft); // tim ra dc node trai nhat ?
  }
  else{  // tim ra dc node trai nhat
  
  }
}

// Xoa 1 node bat khi trong cay nhi phan tim kiem
Tree Delete(Tree t, int val) {
    if (t == NULL) {
        return t;
    }

    if (val < t->val) {
        t->tLeft = Delete(t->tLeft, val);
    } else if (val > t->val) {
        t->tRight = Delete(t->tRight, val);
    } else {
        if (t->tLeft == NULL) {
            Tree temp = t->tRight;
            free(t);
            return temp;
        } else if (t->tRight == NULL) {
            Tree temp = t->tLeft;
            free(t);
            return temp;
        } else {
            // Find the node with the minimum value in the right subtree
            Tree temp = t->tRight;
            while (temp->tLeft != NULL) {
                temp = temp->tLeft;
            }

            // Copy the minimum value to this node
            t->val = temp->val;

            // Delete the node with the minimum value in the right subtree
            t->tRight = Delete(t->tRight, temp->val);
        }
    }
    return t;
}



// ham nhap du lieu
void Menu(Tree *t){
    while(1){
        // system("clear || cls");
    printf("---------------  MENU  -------------\n");
    printf("1. Nhap du lieu\n");
    printf("2. Xuat du lieu cay theo NLR\n");
    printf("3. Xuat du lieu cay theo NRL\n");
    printf("4. Xuat du lieu cay theo LNR\n");
    printf("5. Xuat du lieu cay theo RNL\n");
    printf("6. Xuat du lieu cay theo LRN\n");
    printf("7. Xuat du lieu cay theo RLN\n");
    printf("8. Tim kiem phan tu trong cay\n");
    printf("9. Tim kiem node co 2 con trong cay\n");
    printf("10. Tim kiem node co 1 con trong cay\n");
    printf("11. Tim kien node la trong cay\n");
    printf("12. Tim kiem gia tri lon nhat trong cay\n");
    printf("13. Tim kiem gia tri be nhat trong cay\n");
    printf("14. Xoa 1 node bat ki trong cay\n");
    printf("15. Ket thuc chuong trinh\n");
    printf("-------------------------------------\n");

    int luachon;
    printf("Nhap lua chon : ");
    scanf("%d", &luachon);
    
    if(luachon < 1 || luachon > 15){
        printf("Lua chon khong hop len \n");
        //system("pause");
    }
    else if (luachon == 1){
        int x;
        printf("Nhap so nguyen x :");
        scanf("%d", &x);
        *t = insert(*t, x);
    }
    else if (luachon == 2){
        printf("Duyet cay qua node NLR : \n");
        Duyet_NLR(*t);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 3){
        printf("Duyet cay qua node NRL : \n");
        Duyet_NRL(*t);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 4){
        printf("Duyet cay qua node LNR : \n");
        Duyet_LNR(*t);
        printf("\n");
        //system("pause");
    }    
    else if (luachon == 5){
        printf("Duyet cay qua node RNL : \n");
        Duyet_LNR(*t);
        printf("\n");
        //system("pause");
    }        
    else if (luachon == 6){
        printf("Duyet cay qua node LRN : \n");
        Duyet_LRN(*t);
        printf("\n");
        //system("pause");
    }     
    else if (luachon == 7){
        printf("Duyet cay qua node RLN : \n");
        Duyet_RLN(*t);
        printf("\n");
        //system("pause");
    } 
    else if (luachon == 8){
        int x;
        printf("Nhap gia tri can tim kiem \n");
        scanf("%d", &x);
        printf("Tim kiem gia tri %d  trong cay : \n", x);
        Find(*t, x);
        printf("\n");
        //system("pause");
    } 
    else if (luachon == 9){
        printf("Node co 2 con trong cay nhi phan :\n");
        Node_Has_2(*t);
        printf("\n");
        //system("pause");
    }   
    else if (luachon == 10){
        printf("Node co 1 con trong cay nhi phan :\n");
        Node_Has_1(*t);
        printf("\n");
        //system("pause");
    }      
    else if (luachon == 11){
        printf("Node la trong cay nhi phan :\n");
        Node_leaves(*t);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 12){
        printf("MAX trong cay nhi phan :\n");
        FindMax(*t);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 13){
        printf("MIN trong cay nhi phan :\n");
        FindMin(*t);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 14){
        int x;
        printf("Nhap gia tri can xoa :");
        scanf("%d ", &x);
        printf("cay nhi phan sau khi xoa %d :\n", x);
        Delete(*t, x);
        printf("\n");
        //system("pause");
    }
    else if (luachon == 15){
        break;
    }
}

}

int main(){
    Tree t = NULL;
    Menu(&t);

    system("pause");
    return 0;
}