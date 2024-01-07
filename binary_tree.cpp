#include <iostream>
#include <queue>
using namespace std;

class BinaryNode {
public:
    int data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(int data){
    	this->data = data;
    	this->left = NULL;
    	this->right = NULL;
	}
};

class BinaryTree {
public:
    BinaryNode* root;

    BinaryTree(){
    	root = NULL;
	}

    void InsertNode(int data) {
        if (root == NULL) {     //agar root null hai to ek root node banao or us main data pass karwa do 
            root = new BinaryNode(data);
            return;
        }

        queue<BinaryNode*> q;
        q.push(root);

        while (!q.empty()) {   //jab tak queue epty na ho jaye
            BinaryNode* frontNode = q.front();    //queue k front ko uthao  or usy pop kardo
            q.pop();

            if (frontNode->left == NULL) {       // ab front k left or right empty hain to us main node pass karwa do object bana kar 
                frontNode->left = new BinaryNode(data);
                return;
            } else if (frontNode->right == NULL) {
                frontNode->right = new BinaryNode(data);
                return;
            } else {
                if (frontNode->left) {         //pehli front node ki left node pe bhi insert karo us k left se or right se bhi 
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
        }
    }

    void InorderTraversal(BinaryNode* node) {
        if (node != NULL) {
            InorderTraversal(node->left);
            cout << " " << node->data;
            InorderTraversal(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    cout <<"Binary Tree in Inorder Traversal: ";
    tree.InsertNode(3);
    tree.InsertNode(2);
    tree.InsertNode(9);
    tree.InsertNode(0);
    tree.InsertNode(8);
    tree.InsertNode(13);
    tree.InsertNode(12);
    tree.InsertNode(20);
    tree.InsertNode(1);

    tree.InorderTraversal(tree.root);

    return 0;
}

