// DEMO: max heap
// the min heap is similar except that line 125 changes to the opposite operator (from '>' to '<')

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

enum DIR
{
    PARENT = 'P',
    LEFT = 'L',
    RIGHT = 'R',
};

class H_Node
{
    int _data;
    H_Node *_p;
    H_Node *_l;
    H_Node *_r;
public:
    H_Node(const int data, H_Node *parent = nullptr, H_Node *left = nullptr, H_Node *right = nullptr)
        : _data(data), _p(parent), _l(left), _r(right){};
    H_Node() {}
    bool isFull(){ return this->traverse(LEFT) && this->traverse(RIGHT); }
    bool hasLeft(){ return !!this->traverse(LEFT); }
    bool hasRight(){ return !!this->traverse(RIGHT); }
    friend std::ostream &operator<<(std::ostream &os, H_Node *H_Node)
    {
        if (H_Node->_data)
            os << H_Node->_data;
        return os;
    }
    const int value() { return _data; }
    void value(const int &data) { _data = data; }
    H_Node *traverse(const char &direction = PARENT)
    {
        switch (direction)
        {
        case PARENT:
            return this->_p;
        case LEFT:
            return this->_l;
        case RIGHT:
            return this->_r;
        }
        return this;
    }
    void insert(const int &data, const char &direction = RIGHT)
    {
        if (!_data)
        {
            _data = data;
            return;
        }
        switch (direction)
        {
        case LEFT:
            this->_l = new H_Node(data, this);
            break;
        case RIGHT:
            this->_r = new H_Node(data, this);
            break;
        default:
            return;
        }
    }
    void printAll(H_Node *node = nullptr, int row = 1, char branch = '-')
    {
        auto p = (node ? node : this);

        const size_t n = row * 2;
        std::cout.fill(' ');
        std::cout.width(n);
        if (p->_data)
            std::cout << branch << ": " << p << std::endl;

        if (p->_l)
            printAll(p->_l, (row + 1), LEFT);
        if (p->_r)
            printAll(p->_r, (row + 1), RIGHT);
    }
};

class Heap {
    std::vector<H_Node*> _data;
    public:
    Heap(){}
    ~Heap(){}
    void swap(H_Node *node1, H_Node *node2)
    {
        auto tmp = node2->value();
        node2->value(node1->value());
        node1->value(tmp);
    }
    int getIndex(H_Node* node) {
        int idx = 0;
        for (auto& e : _data) {
            if (e == node){
                return idx;
            }
            ++idx;
        }
    }
    H_Node* insert(const int& data){
        if (_data.size()){
            // go to the first empty location
            for (auto& e : _data){
                if (!e->isFull()){
                    // pick empty side
                    H_Node* side = nullptr;
                    if (e->hasLeft()) {
                        e->insert(data, RIGHT);
                        side = e->traverse(RIGHT);
                    } else{
                        e->insert(data, LEFT);
                        side = e->traverse(LEFT);
                    }

                    auto last = _data.at(_data.size()-1);
                    
                    // bubble up max
                   while (last->traverse(PARENT) && last->value() > last->traverse(PARENT)->value()){
                       swap(last, last->traverse(PARENT));
                       last = last->traverse(PARENT);
                   }
                    
                    _data.push_back(side);
                    return side;
                } else {
                }
            }
        } 

        _data.push_back(new H_Node(data));
        return _data[0];
    }
    void printAll(){
        _data[0]->printAll();
    }
};

// MAIN FUNCTION
int main(int argc, char const *argv[])
{
    auto r = new Heap();
    r->insert(2);
    r->insert(4);
    r->insert(16);
    r->insert(14);
    r->insert(8);
    r->insert(10);
    r->insert(6);
    r->insert(12);
    r->insert(43);
    r->insert(1);
    r->insert(23);
    r->insert(27);
    r->insert(88);
    r->insert(-1);

    puts("- - - -");
    r->printAll();

    return 0;
}
