// DEMO: Queue
// This program demonstrates a queue, which is similar to a queue
// but uses FIFO as it's sequence of operation.

// Parts of this program is borrowed directly from queue.cpp

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

class Queue {
    Node* _nodes;

    public:
    Queue() :_nodes(nullptr){}
    Node* begin(){ 
        return _nodes;
    }
    Node* end(){
        auto n = _nodes;
        while(_nodes) 
            if (_nodes->_next) n = _nodes->_next;
        return n;
    }
    void push(const int& data){
        // create new node with next pointing to beginning
        auto n_node = new Node(data, this->begin());
        // replace at beginning
        _nodes = n_node;
    }
    Node* pop(){
        // start at beginning
        auto n_node = _nodes;
        // go to end - 1 element
        while (n_node->_next->_next) 
            n_node = n_node->_next;
        // select last element to return
        auto res = n_node->_next;
        // // dissassociate element
        n_node->_next = nullptr;
        // return removed item
        return res;
    }
    void printQueue(){
        // identical to print stack
        auto ptr = _nodes;
        while(ptr){
            std::cout << ptr << ' ';
            if (ptr) ptr = ptr->_next;
        }
        puts("");
    }
};

int main(int argc, char const *argv[])
{
    auto queue = new Queue();
    queue->push(7);
    printf("inserted: %d\n", 7);
    queue->push(12);
    printf("inserted: %d\n", 12);
    queue->push(23);
    printf("inserted: %d\n", 23);
    queue->push(33);
    printf("inserted: %d\n", 33);

    queue->printQueue();

    auto removed = queue->pop();
    printf("Removed: %d\n", removed->_data);
    removed = queue->pop();
    printf("Removed: %d\n", removed->_data);

    queue->printQueue();

    return 0;
}
