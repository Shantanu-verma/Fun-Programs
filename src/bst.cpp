#include <iostream>

template<typename T>
class bst{
	template<typename U = T>
	struct node{
	U data;
	node<U> *left,*right;
	node():data(0),left{nullptr},right{nullptr}{ }
	node(const U& data):data{data},left{nullptr},right{nullptr}{}
	};
	node<T>* root;
	typedef T value_type;
public:
	bst():root(nullptr){ }
	bst(const T& data):root{new node<T>(data)}{ }
	bool insert(const T& data){
		node<T>* cur = new node<T>(data);
		if(root == nullptr){
		 root = cur; return true;
		}
		bool direction = false;
		node<T>* parent = nullptr;
		node<T>* child  = root;
		while(child != nullptr){
			parent = child;
			if(child->data == data) return false;
			else if(child->data < data){
				direction = true;
				child = child->right;
			}
			else child = child->left;
		}
		direction ? parent->right = cur : parent->left = cur;	
		return true;
	}
	bool find(const T& data){
		node<T>* temp = root;
		while(temp != nullptr){
			if(temp->data == data) return true;
			else if(temp->data < data) temp = temp->right;
			else temp = temp->left;
		}
		return false;
	}
	std::size_t get_height(){
		std::size_t h1 = root?1:0, h2 = h1;
		node<T>* leftn  = root;
		node<T>* rightn = root;
		while((leftn   = leftn->left)   != nullptr) h1++;
		while((rightn  = rightn->right) != nullptr) h2++;
		return std::max(h1,h2);
	}
	void traverse(){
		node<T>* leftn  = root;
		node<T>* rightn = root;
		std::cout<<"\nRoot\n";
		if(root != nullptr) std::cout<<root->data<<'\n';
		std::cout<<"\nLeft:\n";
		while((leftn  = leftn->left)   != nullptr) std::cout<<"-> "<<leftn->data;
		std::cout<<"\n\nRight:\n";
		while((rightn = rightn->right) != nullptr) std::cout<<"-> "<<rightn->data;
	}
	node<T>* getroot(){ return root; }
	void erase(){
		node<T>* leftn = root->left;
		node<T>* rightn = root->right;
		delete root;
		while(leftn != nullptr){
			node<T>* temp = leftn;
			leftn = leftn->left;
			delete temp;
		}
		while(rightn != nullptr){
			node<T>* temp = rightn;
			rightn = rightn->left;
			delete temp;
		}
	}
	~bst(){ erase(); }
};
template<typename T>
void print(T data){
	std::cout<<data;
}
int main(){
	bst<int> tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(9);
	tree.insert(8);
	tree.insert(25);
	std::cout<<tree.get_height();
	tree.traverse();
	std::cin.get();
}
