#include <iostream>
#include <queue>
using namespace std;

//same as binary tree bas is ki 3 child hoty har node k 
class TernaryNode {
public:
    int data;
    TernaryNode* left;
    TernaryNode* right;
    TernaryNode* middle;

    TernaryNode(int data){
    	this->data = data;
    	this->left = NULL;
    	this->right = NULL;
    	this->middle = NULL;
	}
};

class TernaryTree {
public:
    TernaryNode* root;

    TernaryTree(){
    	root = NULL;
	}

    void InsertNode(int data) {
        if (root == NULL) {
            root = new TernaryNode(data);
            return;
        }

        queue<TernaryNode*> q;
        q.push(root);

        while (!q.empty()) {
            TernaryNode* frontNode = q.front();
            q.pop();

            if (frontNode->left == NULL) {
                frontNode->left = new TernaryNode(data);
                return;
            } else if (frontNode->middle == NULL) {
                frontNode->middle = new TernaryNode(data);
                return;
            } else if (frontNode->right == NULL) {
                frontNode->right = new TernaryNode(data);
                return;
            } else {
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->middle) {
                    q.push(frontNode->middle);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
        }
    }

    void InorderTraversal(TernaryNode* node) {
        if (node != NULL) {
            InorderTraversal(node->left);
            cout << node->data << " ";
            InorderTraversal(node->middle);
            InorderTraversal(node->right);
        }
    }

    void SearchInTernary(TernaryNode* node, int searchNode) {
        if (node == NULL) {
            cout << "Tree is empty!"<<endl;
            return;
        }
        
        if (node->data == searchNode) {
            cout << searchNode << " Node found";
            return;
        }
        if (node->left) {
            SearchInTernary(node->left, searchNode);
        }
        if (node->middle) {
            SearchInTernary(node->middle, searchNode);
        }
        if (node->right) {
            SearchInTernary(node->right, searchNode);
        }
    }
};

int main() {
    TernaryTree tree;
    tree.InsertNode(10);
    tree.InsertNode(50);
    tree.InsertNode(30);
    tree.InsertNode(90);
    tree.InsertNode(70);
    tree.InsertNode(80);
    tree.InsertNode(40);
    tree.InsertNode(20);
    tree.InsertNode(55);
    tree.InsertNode(75);
    tree.InsertNode(89);
    tree.InsertNode(74);
    tree.InsertNode(52);
    tree.InsertNode(1);
    tree.InsertNode(18);
    tree.InsertNode(19);

    tree.InorderTraversal(tree.root);
    cout<<endl;
    tree.SearchInTernary(tree.root, 555);

    return 0;
}

