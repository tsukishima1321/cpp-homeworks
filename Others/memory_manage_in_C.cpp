// manage memory of linked list in C
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    node_t *next;
} node_t;

void *remove_first(node_t **head_list) {
    if (*head_list == NULL) {
        return NULL;
    }
    node_t *curr = *head_list;
    *head_list = (*head_list)->next;
    void *data = curr->data;
    free(curr);
    return data;
}

// 用10:{xxx}表示地址为10的内存块，{xxx}表示内存块中的数据

int main() {
    node_t *head = (node_t *)malloc(sizeof(node_t)); // 假设head为10，&head为100
    int *a = (int *)malloc(sizeof(int));             // 假设a为1000
    *a = 33854;
    head->data = a;
    node_t *next = (node_t *)malloc(sizeof(node_t)); // 假设next为20
    int *b = (int *)malloc(sizeof(int));             // 假设b为2000
    *b = 98562;
    next->data = b;
    head->next = next;
    next->next = NULL;
    // 那么现在内存中的情况是：
    // 10:{data=1000,next=20}
    // 20:{data=2000,next=null}
    // 100:10
    // 1000:33854
    // 2000:98562

    // 模拟调用remove_first(&head)

    node_t **head_list = &head;
    // head_list==100
    // 10:{data=1000,next=20}
    // 20:{data=2000,next=null}
    // 100:10
    // 1000:33854
    // 2000:98562

    node_t *curr = *head_list; // 用变量curr拷贝了地址100中储存的值
    // head_list==100
    // curr==10 <--------------------------
    // 10:{data=1000,next=20}
    // 20:{data=2000,next=null}
    // 100:10
    // 1000:33854
    // 2000:98562

    *head_list = (*head_list)->next; // 对*headlist赋值，就是改变地址100中储存的值
    // head_list==100
    // curr==10
    // 10:{data=1000,next=20},
    // 20:{data=2000,next=null}
    // 100:20 <----------------------------
    // 1000:33854
    // 2000:98562

    void *data = curr->data;
    // head_list==100,
    // curr==10
    // data==1000 <------------------------
    // 10:{data=1000,next=20},
    // 20:{data=2000,next=null}
    // 100:20
    // 1000:33854
    // 2000:98562

    free(curr);
    // head_list==100,
    // curr==10
    // data==1000
    // 10:被释放 <--------------------------
    // 20:{data=2000,next=null}
    // 100:20
    // 1000:33854
    // 2000:98562

    // return data;
    // 返回1000，局部变量head_list，curr，data被释放
    // 变量head已经指向地址为20的节点（就是地址100上储存的值变为20），即完成了删除第一个节点的操作

    void *receive = data; // 1000
    // 也就是void* receive = remove_first(&head);
    int get_value = *(int *)receive;
    // 接收储存在地址1000的数据，既原list的第一个节点的数据，拷贝33854到get_value
    free(receive);
    // 释放地址1000的内存，自此第一个节点本身和其拥有的数据都被释放

    // 现在内存中的情况是：
    // get_value==33854
    // head==20 (100:20)
    // 20:{data=2000,next=null}
    // 1000:被释放
    // 2000:98562

    printf("%d\n", get_value);

    system("pause");
    return 0;
}