//�����1��Ϊ1��������n����ʾ��ǰ�������ȣ���2��Ϊn���ո�����������Ϊ������n��Ԫ�ص�������ֵ����3��Ϊ1��������m����ʾ�Ը�����ʩ��
//�Ĳ���������������m�У�ÿ�б�ʾһ��������Ϊ2����3����������ʽΪ0 k d��1 k��0 k d��ʾ�������k���������һ��������ֵΪd�Ľ�㣬
//��k = 0���ʾ��ͷ���롣1 k��ʾɾ�������е�k����㣬��ʱk����Ϊ0��
//ע�����������������в��Ϸ��Ĳ��������ڳ���Ϊ5��������ɾ����8����㡢ɾ����0�����ȣ�������Ըò�����n��m������100000��
//
//�����ʽ :���Ϊһ����������ʾʵʩ����m�������������ÿ��������һ���ո��������ݱ�֤��������ա�
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




