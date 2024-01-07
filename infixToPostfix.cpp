#include <iostream>
#include <stack>
using namespace std;

int prec(char c){  // current elemet ki precedence bata raha
	
	if(c == '^'){
		return 3;
	}
	else if(c == '*' || c == '/'){
		return 2;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else{
		return -1;     //when expression has openeing bracket ( 
	}
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) { // Fixed the precedence comparison
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res; // Return the result after processing the entire input expression
}


int main(){
	cout<< infixToPostfix("(a-b/c)*(a/k-l)")<<endl;

}
