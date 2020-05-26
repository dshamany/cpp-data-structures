#include <iostream>
#include <vector>
#include <string>

class Node {
    public:
    void insert(const std::string str) {
		if (!str.size()) return;

		_c = str[0];
		std::string _str;
		bool childExists = false;

		for (auto& e : _children) {
			if (e->value() == str[1]){
				_str = std::string(str.begin()+2, str.end());
				auto node = new Node(_str);
				e->_children.push_back(node);
				childExists = true;
			}
		}
		
		if (!childExists){
			_str = std::string(str.begin()+1, str.end());
			auto node = new Node(_str);
			_children.push_back(node);
		}
    }
    Node(){};
    ~Node(){};
    Node(const std::string str){ insert(str); };
    Node* child(const char& c){
		for (auto& e : _children){
			if (e->_c == c){
				return e;
			}
		}
		return nullptr;
	}
	char value(){ return _c; }
	friend std::ostream& operator<<(std::ostream& os, const Node* node){
		os << node->_c;
		return os;
	}
	private:
    char _c;
    std::vector<Node*> _children;

};

int main(int argc, char const *argv[])
{
    auto n = new Node("daniel");
	n->insert("david");

    return 0;
}
