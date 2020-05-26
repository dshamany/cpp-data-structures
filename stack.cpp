// DEMO: stack
// This will be implemented using a LinkedList
// to add to the challenge. An array could be used 
// but is not ideal

#include <iostream>

struct Node {
    int _data;
    Node* _next;
    Node() : _next(nullptr){}
    Node(const int& data, Node* next = nullptr) : _data(data), _next(next){}
    ~Node(){}
    friend std::ostream& operator<<(std::ostream& os, Node* node){
        os << node->_data;
        return os;
    }
};

class Stack {
    Node* _root;
    public:
    Stack() :_root(nullptr){}
    Stack(const int& data) : _root(new Node(data)){}
    Node* next(){ return _root->_next; }
    void push(const int& data){
        // Insert at the beginning because a stack
        // uses LIFO (Last-In-First-Out) method
        auto n_node = new Node(data, _root);
        _root = n_node;
    }
    Node* pop(){
        // delete from beginning
        auto tmp = _root;
        _root = _root->_next;
        return tmp;
    }
    void printStack(){
        auto r = _root;

        while (r) {
            std::cout << r << ' ';
            r = r->_next;
        }
        puts("");
    }
};

int main(int argc, char const *argv[])
{
    auto stack = new Stack();
    stack->push(7);
    stack->push(12);
    stack->push(23);

    stack->printStack();

    auto removed = stack->pop();
    printf("Removed: %d\n", removed->_data);

    stack->printStack();

    return 0;
}
