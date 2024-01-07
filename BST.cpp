#include <iostream>
#include <queue>
using namespace std;

class Node{
	public: 
	    int data;
	    Node* left;
	    Node* right;
	    
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};


void levelOrderTraversal(Node* root){
	queue<Node*> q;       //queue banany se traversing easy ho jati
	q.push(root);         // sab se pehlay ek root daldo push se 
	q.push(NULL);
	
	while(!q.empty()){        //jab tak empty na ho dalty raho
		Node* temp = q.front();  //temp varaible banao jo queue k front ko dikhaye 
		//yahan ek choti se cout <<temp->data wali line ki changing kari kyon k yahan hone se agar tem agy ja kar null jo ta to first order k bad hi agy ki noddes print nhi ho saken gi
		q.pop();                 // or pop kardo
		
		if(temp==NULL){           // matlab ek level compltet traverse ho chuka 
			cout<<endl;          // to enter mardo ek line ka 
			if(!q.empty()){      // agar queue me abhi bhi kuch para hoa hai matlab child node hain 
				q.push(NULL);     // to wahan null laga kar seperate kardo taky tree format me answer ajaye
			}
		}
		
		else{                    // nhi to yeh kardo
		
		cout<<temp -> data<<" ";   //usy print karwao jo temp ne queue k front se uthaya hai   / main usy tab print karwaon ga jab patah ho k temp null nhi hai
		
		if(temp -> left){         // agar temp ka left non NULL hai to us pe push kardo
			q.push(temp -> left);
		}
		
		if(temp -> right){        // agar temp ka right non NULL hai to us pe push kardo   
			q.push(temp -> right);
		}
	}
	}
}

void preOrder(Node* root){
//	base case 
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root){
//	base case 
	if(root == NULL){
		return;
	}
	
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node* root){
//	base case 
	if(root == NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

//searching 
bool searchBST(Node* root, int x){
//	base case 
	if(root == NULL){
		return false;
	}
//	2nd base case 
	if(root->data == x){
		return true;
	}
	
	if(root->data > x){
		return searchBST(root->left, x);
	}
	if(root->data < x){
		return searchBST(root->right, x);
	}
}

//fining minimum value in BST 

Node* minValue(Node* root){
	Node* temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

//fining maximum value in BST 

Node* maxValue(Node* root){
	Node* temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

Node* insert_in_to_BST(Node* &root, int data){
//	base case 
	if(root == NULL){           // agar root hi nhi hai matlab null hai 
		root = new Node(data);     // to pehlay root node banado or usme value pass karwao
		return root;            // or phr return kardo or agy code run karo
	}
	
	if(data > root->data){        //agar data node root data node se bari hai to right part me insert kardo using (insert_in_to_BST)
		root->right = insert_in_to_BST(root->right, data);
	}
	else{                         //agar data node root data node se choti hai to left part me insert kardo using (insert_in_to_BST)
		root->left = insert_in_to_BST(root->left, data);
	}
	return root;
}

void takeInput(Node* &root){
	int data;
	cin >> data;
	
	while(data != -1){
		root = insert_in_to_BST(root, data);
		cin >> data;
	}
}


//deletion 
Node* deleteFromBST(Node* root, int val){
//	1st base case
	if(root == NULL){
		return root;
	}
	
//	2nd base case
	if(root->data == val){
//		0 child
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
	
//		1 child

//	    left child
		if(root->left != NULL && root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
//		right child
		if(root->left == NULL && root->right != NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}

//		2 child min value replace
		if(root->left != NULL && root->right != NULL){
			int mini = minValue(root->right)->data;       // sab se oehlay right side se minimum value save karwadi mini me
			root->data = mini;                            // phr data ki value ko mini ki value se replace karwadia 
			root->right = deleteFromBST(root->right, mini);   // phr delete karwa dia right side root data wali value ko relace karwany k bad
			return root;                                     // phr return karwa dia 
		}
		
////		2 child max value replace
//		if(root->left != NULL && root->right != NULL){
//			int max = maxVal(root->left) -> data;
//			root->data = max;
//			root->left = deleteFromBST(root->left, max);
//			return root;
//		}
	}
	
	else if(root->data > val){      // root data ki value bari to left part me jana hai
//		goto left side
		root->left = deleteFromBST(root->left, val);
		return root;
	}
	else{
//		goto right side 
		root->right = deleteFromBST(root->right, val);
		return root;
	}
}


int main(){
	Node* root = NULL;
	cout<<"Enter data to create Binary Search Tree "<<endl;
    takeInput(root);
    
    cout<<"print the binary search tree: "<<endl;
    levelOrderTraversal(root);
    
    cout<<"inOrder traversal is: ";
	inOrder(root);
	cout<<endl;
	
	cout<<"preOrder traversal is: ";
	preOrder(root);
	cout<<endl;
	
	cout<<"postOrder traversal is: ";
	postOrder(root);
	
	cout<<endl;
	
//	max / min 
	cout<<"min value in BST is: "<< minValue(root)->data<<endl;
	cout<<"max value in BST is: "<< minValue(root)->data<<endl;
	
//	searching code 
	cout << "Search for an element: ";
    int element;
    cin >> element;
    
    if (searchBST(root, element)) {
        cout << "Element " << element << " found in the tree." << endl;
    } else {
        cout << "Element " << element << " not found in the tree." << endl;
    }
    
    	
//	deletion 
	deleteFromBST(root, 3);
	
	cout<<"printing the level order traversal output "<<endl;
	levelOrderTraversal(root);
	
	cout<<"inorder traversal is: ";
	inOrder(root);
	cout<<endl;
	
	cout<<"preorder traversal is: ";
	preOrder(root);
	cout<<endl;
	
	cout<<"postorder traversal is: "<<endl;
	postOrder(root);
	cout<<endl;
	
	cout<<"min value in BST is: "<<minValue(root) -> data <<endl;
	cout<<"max value in BST is: "<<maxValue(root) -> data <<endl;
	
	return 0;
	
	
     
}
