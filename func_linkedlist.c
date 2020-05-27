#include <stdio.h>

struct Node {
    int _data;
    struct Node* _next;
};

void insert(struct Node* node, const int value){
    struct Node* hdl = node;
    struct Node n_node = { value, NULL };
    while (hdl->_next) hdl = hdl->_next;
    hdl->_next = &n_node;
}

void printAll(struct Node* node){
    struct Node* n = node;
    while (n->_next){
        printf("%d ", n->_data);
        if (n->_next){
            n = n->_next;
        } else {
            n = NULL;
        }
    }
}

int main(int argc, char const *argv[])
{
    int iA[] = {1,2,3,4,5,6,7,8,9,0};

    printf("Size of Array: %d\n", sizeof(iA)/sizeof(iA[0]));
    // struct Node n1;
    // insert(&n1, 7);
    // insert(&n1, 12);
    // // printAll(&n1);
    // printf("%d ", n1._next->_data);
    // printf("%d ", n1._next->_next->_data);
    // printf("%d \n", n1._next->_next->_next->_data);
    
    return 0;
}
