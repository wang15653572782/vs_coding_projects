//输入第1行为1个正整数n，表示当前单链表长度；第2行为n个空格间隔的整数，为该链表n个元素的数据域值。第3行为1个正整数m，表示对该链表施加
//的操作数量；接下来m行，每行表示一个操作，为2个或3个整数，格式为0 k d或1 k。0 k d表示在链表第k个结点后插入一个数据域值为d的结点，
//若k = 0则表示表头插入。1 k表示删除链表中第k个结点，此时k不能为0。
//注：操作序列中若含有不合法的操作（如在长度为5的链表中删除第8个结点、删除第0个结点等），则忽略该操作。n和m不超过100000。
//
//输出格式 :输出为一行整数，表示实施上述m个操作后的链表，每个整数后一个空格。输入数据保证结果链表不空。
//5
//1 2 3 4 5
//59
//0 2 8
//0 9 6
//0 0 7
//1 0
//1 6
#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;             
    struct Node* next;          
}Node;
Node* head;

void Insert(int k, int d,Node* P) {
    if (k < 0) {
        
        return;
    }
    if (k == 0) {
        
            head = (Node*)malloc(sizeof(Node));
            head->data = d;
            head->next = NULL;
        }

    Node* p =P; int i = 0;
    while (p != NULL && i < k) {
        p = p->next;
        i = i + 1;
    }
    if (p==NULL) {
        
        return;
    }
    Node* s;
   s = (Node*)malloc(sizeof(Node));
   s->data = d;
   s->next = p->next;
   p->next = s;
}
void Delete(int k, Node* P) {
    if (k <1) {
        
        return;
    }
    if (k == 1) {
        
        Node* p = head;
        head = head->next;
        free(p);
    }

    Node* p = P; 
   
    int i = 0;
    while (p!= NULL && i < k - 1) {
        p = p->next; i = i + 1;
    }
    if (p == NULL)return;
    Node* q = p->next;
    p->next = q->next;
    free(q);
}
int main(){
    int n;
    scanf_s("%d\n", &n);
    
    Node* head = (Node*)malloc(sizeof(Node));   
        
     Node* L =head;
     
        int x;                        
        for (int i = 1; i <= n; i++) {
            scanf_s("%d ", &x);
            Node* p;
            p = (Node*)malloc(sizeof(Node));   
            p->data = x;                    
             
            L->next = p;
            L = p;
            
        }
        L->next = NULL;
     
    
    int m;
    scanf_s("%d", &m);
    for (int j =0; j < m; j++) {
        int M,k,d;
        scanf_s("%d ", &M);
        if (M == 0) {
            scanf_s("%d %d", &k, &d);
            Insert(k,d,head);
           
        }
        if (M == 1) {
            scanf_s("%d", &k);
            Delete(k,head);
        }
    }
    head= head->next;
    while(head){
        printf("%d ", head->data);
        head= head->next;
    }
    return 0;
}




