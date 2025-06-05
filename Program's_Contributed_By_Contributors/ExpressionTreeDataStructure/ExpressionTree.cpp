#include <iostream>
using namespace std;

const int StackSize = 10;

class TreeNode
{
    char Data;
    TreeNode* left;
    TreeNode* right;
	public:
	    TreeNode()
		{
	        left = NULL;
	        right = NULL;
	    }
	    void SetData(char a)
	    {
	    	Data = a;
		}
		void SetLeft(TreeNode* temp)
		{
			left = temp;
		}
		void SetRight(TreeNode* temp)
		{
			right = temp;
		}
		char GetData()
		{
			return Data;
		}
		TreeNode* GetLeft()
		{
			return left;
		}
		TreeNode* GetRight()
		{
			return right;
		}
};

class Stack
{
	TreeNode *StackArray[StackSize];
	int Top;
	public:
		Stack()
		{
			Top = -1;
		}
		bool IsEmpty()
		{
			if(Top == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool IsFull()
		{
			if(Top + 1 == StackSize)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int Size()
		{
			return Top + 1;
		}
		void push(TreeNode *a)
		{
			if(IsFull())
			{
				cout << "Can't insert more elements ----- Stack is Full" << endl;
			}
			else
			{
				StackArray[++Top] = a;
			}
		}
		void pop()
		{
			if(IsEmpty())
			{
				cout << "Can't remove elements ---- Stack is empty" << endl;
			}
			else
			{
				Top--;
			}
		}
		TreeNode* top()
		{
			return StackArray[Top];
		}
		void Display()
		{
			for(int i = Size() - 1; i >= 0; i--)
			{
				cout << StackArray[i] << endl;
			}
		}
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
	{
        return true;
    }
    return false;
}

void inorderTraverse(TreeNode* root)
{
    if (root == NULL)
	{
        return;
    }
    else
    {
		inorderTraverse(root->GetLeft());
	    cout << root->GetData() << " ";
	    inorderTraverse(root->GetRight());
	}
    
}

void postorderTraverse(TreeNode* root)
{
    if (root == NULL)
	{
        return;
    }
    else
    {
	    postorderTraverse(root->GetLeft());
	    postorderTraverse(root->GetRight());
	    cout << root->GetData() << " ";
	}
    
}

void preorderTraverse(TreeNode* root)
{
    if (root == NULL)
	{
        return;
    }
    else
    {
	    cout << root->GetData() << " ";
	    preorderTraverse(root->GetLeft());
	    preorderTraverse(root->GetRight());
	}
    
}

TreeNode* ExpressionTree(char* postfix)
{
	int i = 0;
    Stack stack;
    while(postfix[i] != '\0')
	{
        char c = postfix[i++];
        if (isOperator(c))
		{
            TreeNode* op = new TreeNode();
            op->SetData(c);
            op->SetRight(stack.top());
            stack.pop();
            op->SetLeft(stack.top());
            stack.pop();
            stack.push(op);
        }
		else
		{
            TreeNode* temp = new TreeNode();
            temp->SetData(c);
            stack.push(temp);
        }
    }
    return stack.top();
}

int main()
{
    char postfix[] = "99*55*+447-/+";
    TreeNode* root = ExpressionTree(postfix);
    cout << "Inorder traversal: ";
    inorderTraverse(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorderTraverse(root);
    cout << endl;
    cout << "Preorder traversal: ";
    preorderTraverse(root);
    cout << endl;
    return 0;
}
