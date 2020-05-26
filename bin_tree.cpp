// Demonstrate a binary tree implementation

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cassert>

template <typename T>
class Node
{
private:
    T _data;
    Node *_left;
    Node *_right;

public:
    Node()
        : _left(nullptr), _right(nullptr) {}
    Node(const T &data, Node *left = nullptr, Node *right = nullptr)
        : _data(data), _left(left), _right(right) {}
    Node *left() { return _left ? _left : nullptr; }
    Node *right() { return _right ? _right : nullptr; }
    T value() { return _data; }
    void value(const T &data) { this->_data = data; }
    Node<T>* max()
    {
        auto root = this;
        while (root->right())
        {
            root = root->right();
        }
        return root;
    }
    Node<T>* min()
    {
        auto root = this;
        while(root->left())
        {
            root = root->left();
        }
        return root;
    }
    void insert(T data)
    {
        this->insert(new Node(data));
    }
    void insert(Node *n)
    {
        if (n->value() > this->_data)
        {
            if (this->_right == nullptr)
            {
                this->_right = n;
            }
            else
            {
                this->_right->insert(n);
            }
        }
        else
        {
            if (this->_left == nullptr)
            {
                this->_left = n;
            }
            else
            {
                this->_left->insert(n);
            }
        }
    }
    Node *find(T data)
    {
        Node *result = this;

        while (result)
        {
            if (data < result->value())
            {
                result = result->left();
            }
            else if (data > result->value())
            {
                result = result->right();
            }
            else if (data == result->value())
            {
                return result;
            }
        }
        return nullptr;
    }
    friend std::ostream &operator<<(std::ostream &stream, const Node *n)
    {
        if (n)
            stream << n->_data;
        return stream;
    }
};

template <typename T>
void print_all(Node<T>* node, const char* order = "in-order")
{
    if (node && order == "pre-order")
    {
        std::cout << node << '\n';
        print_all(node->left(), order);
        print_all(node->right(), order);
    }
    else if (node && order == "in-order")
    {
        print_all(node->left(), order);
        std::cout << node << '\n';
        print_all(node->right(), order);
    }
    else if (node && order == "post-order")
    {
        print_all(node->left(), order);
        print_all(node->right(), order);
        std::cout << node << '\n';
    }
}

int main(int argc, char const *argv[])
{
    Node<int> *n = new Node<int>(5);
    n->insert(3);
    n->insert(4);
    n->insert(1);
    n->insert(23);
    n->insert(2);
    n->insert(6);
    n->insert(-40);

    int l = -102;
    auto findOne = [&]() {
        auto fiveOTwo = n->find(l);
        std::cout << "Found " << l << ": " << std::boolalpha << (!!fiveOTwo) << " (" << &fiveOTwo << ")" << std::endl;
    };

    std::vector<Node<int> *> res = {};
    print_all(n);


    findOne();

    std::cout << "Max: " << n->max() << std::endl;
    std::cout << "Min: " << n->min() << std::endl;
   
    return 0;
}
