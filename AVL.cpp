
#include <iostream>
#include <algorithm>   //balancing karne k liye left right chil se 
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		int height;
		
//		constructor
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
		height = 1;            // 1 se agy na ho
	}
};

class AVLTree{
	private:
		Node* root;   // creating element root
		
		int height(Node* node){
			if(node == NULL){
				return 0;
			}
			return node->height;    // height bhejdo jo bhi ayi hai 
		}
		
		int balanceFactor(Node* node){
			if(node == NULL){
				return 0;
			}
			return height(node->left) - height(node->right);      // |right - left| karwa k remainig height return 
		}
		
		Node* rotateLeft(Node* y){
			Node* x  = y->right;
			Node* T2 = x->left;
			
//			perform rotation
		x->left = y;
		y->right = T2;
		
//		update heights
		y->height = max(height(y->left), height(y->right)) + 1;
		
		x->height = max(height(x->left), height(x->right)) + 1;
		
		return x;
		}
		
		Node* insert(Node* node, int val){
			if(node == NULL){
				return new Node(val);
			}
			
			if(val < node->data){
				node->left = insert(node->left, val);
			}
			else if(val > node->data){
				node->right = insert(node->right, val);
			}
			else{
//				duplicate data is not allowed
			return node;
			}
			
//			update height
			node->height = 1 + max(height(node->left), height(node->right));
			
//			check balance fcator
			int balance = balanceFactor(node);
			
//			left left case
			if(balance > 1 && val < node->left->data){
				return rotateLeft(node);
			}
			return node;
		}
		
		void preOrderTraversal(Node* node){
			if(node != NULL){
				cout<<node->data<<" ";
				preOrderTraversal(node->left);
				preOrderTraversal(node->right);
			}
		}
		
	public:
		AVLTree(){
			root = NULL;
		}
		
		void insert(int data){
			root = insert(root, data);		
		}
	
	// usage of the rotateLeft function
	void shiftLeft(){
		if(root == NULL){
			cout<<"Tree is empty"<<endl;
			return;
		}
		root = rotateLeft(root);
		cout<<"Performed rotation left"<<endl;
		}
	void preOrder(){
		preOrderTraversal(root);
		cout<<endl;
	}
};

int main(){
	AVLTree avltree;
	
	avltree.insert(10);
	avltree.insert(20);
	avltree.insert(30);
	avltree.insert(40);
	avltree.insert(50);
	avltree.insert(60);
	
	cout<<"preorder traversal of the AVL tree is: ";
	avltree.preOrder();
	
	avltree.shiftLeft();
	
	avltree.preOrder();
	
	return 0;
}
