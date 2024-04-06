#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h> 

struct Student {
    char name[100];
    char id[20];
    double gpa;
};

struct SV {
    struct Student s;
    struct SV *next;
};

typedef struct SV* sv;

sv makeStudent(int x){
    struct Student s;
    printf("Nhap thong tin sinh vien :\n");
    printf("Nhap ID : "); 
    fgets(s.id, sizeof(s.id), stdin);
    printf("Nhap ten : ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Nhap GPA : "); scanf("%lf", &s.gpa);
    sv tmp = (sv)malloc(sizeof(struct SV));
    tmp->s = s;
    tmp->next = NULL;
    return tmp;
}

// Kiem tra rong
bool empty(sv a){
    return a = NULL;
}

int Size(sv a) {
    int cnt = 0;
    while(a != NULL){
        ++ cnt;
        a = a->next;
    }
    return cnt;
}

// Them 1 sinh vien vao dau danh sach SV
void insertFirst(sv *a){
    sv tmp = makeStudent(1);
    if(*a == NULL){
        *a = tmp;
    }
    else{
        tmp->next = *a;
        *a = tmp;
    }
}

// Them 1 phan sinh vien vao cuoi danh sach
void insertLast(sv *a){
    sv tmp = makeStudent(1);
    if(*a == NULL){
        *a = tmp;
    }
    else {
        sv p = *a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

// Them 1 sinh vien vao vi tri giua
void insertMiddle(sv *a, int pos) {
    int n = Size(*a); 
if(pos <= 0 || pos > n + 1){
    printf("Vi tri khong hop le !\n");
}
if(pos == 1){
    insertFirst(a); return;
}
if(pos == n + 1){
    insertLast(a); return;
}
sv p = *a;
for(int i = 1; i < pos - 1; i++){
    p = p->next;
}
  sv tmp = makeStudent(1);
  tmp->next = p->next;
  p->next = tmp;
}

// Xoa 1 sinh vien o dau
void deleteFirst(sv *a) {
   if(*a == NULL) return;
   *a = (*a)->next;
}

// Xoa 1 sinh vien o cuoi
void deleteLast(sv *a) {
    if(*a == NULL) return;
sv truoc = NULL, sau = *a;
while(sau->next != NULL){
    truoc = sau;
    sau = sau->next;
}
if(truoc == NULL){
    *a = NULL;
}
else{
    truoc->next = NULL;
}
}

// Xoa 1 sinh vien o giua
void deleteMiddle(sv *a, int pos){
    if(pos <= 0 || pos >= Size(*a)) return;
    sv truoc = NULL, sau = *a;
    for(int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        *a = (*a)->next;
    }
    else{
        truoc->next = sau->next;
    }
}

void in(struct Student s){
    printf("--------------------------------\n");
    printf("ID :");
    fgets(s.id, sizeof(s.id), stdin);
    printf("Name :");
    fgets(s.name, sizeof(s.name), stdin);
    printf("GPA : ");
    scanf("%lf", &s.gpa);
    printf("--------------------------------\n");
}

void inds(sv a){
    printf("Danh sach sinh vien : ");
    while(a != NULL){
    in(a->s);
    a = a->next;
    }
}

void sapxep(sv *a){
    for(sv p = *a; p->next != NULL; p = p->next){
        sv min = p;
        for(sv q = p->next; q != NULL; q = q->next){
            if(q->s.gpa < min->s.gpa){
                min = q;
            }
        }
        struct Student tmp = min->s;
        min->s = p->s;
        p->s = tmp;
    }
}

int main() {
    sv head = NULL;
    while(1){
        printf("-----------------MENU---------------\n");
        printf("1. Chen sinh vien vao dau danh sach\n");
        printf("2. Chen sih vien vao cuoi danh sach\n");
        printf("3. Chen sinh vien vao giua danh sach\n");
        printf("4. Xoa sinh vien o dau\n");
        printf("5. Xoa sinh vien o cuoi\n");
        printf("6. Xoa sinh vien o giua\n");
        printf("7. Duyet danh sach lien ket\n");
        printf("8. Sap xep cac danh sach lien ket\n");
        printf("0. Ket thuc chuong trinh\n");
        printf("------------------------------------\n");
        printf("Nhap lua chon\n");
        int lc; scanf("%d", &lc);
        if(lc == 1){ //Chen phan tu vao dau danh sach
            insertFirst(&head);
        }
        else if(lc == 2){  //Chen phan tu vao cuoi danh sach
            insertLast(&head);
        }
        else if(lc == 3){  //Chen phan tu vao giua danh sach
            int pos; printf("Nhap vi tri can chan : ");
            scanf("%d", &pos);
            insertMiddle(&head,pos);
        }
        else if(lc == 4){  //Xoa phan tu o dau
            deleteFirst(&head);
        }
        else if(lc == 5){  //Xoa phan tu o cuoi
            deleteLast(&head);
        }
        else if(lc == 6){  //Xoa phan tu o giua
            int pos; printf("Nhap vi tri can xoa : ");
            scanf("%d", &pos);
            deleteMiddle(&head, pos);
        }
        else if(lc == 7){  //Duyet danh sach lien ket
            inds(head);
        }
        else if(lc == 8){
            sapxep(&head);
        }
        else if(lc == 0) {
            break;
        }
    }
    // printf("%zu", sizeof(node)); // kich thuoc cua node 
    return 0;
}