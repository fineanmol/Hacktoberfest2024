#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class treenode{
	public:
	T data;
	vector<treenode<T>*> children;
	
	treenode(T data){
		this->data = data;
	}
};

using namespace std;

treenode<int> * takeinput(){
	int rootdata;
	cout<<"Enter data:";
	cin>>rootdata;
	
	treenode<int> *root = new treenode<int>(rootdata);
	
	int numchild;
	cout<<"Enter num of children:";
	cin >> numchild;
	
	for(int i=0; i < numchild; i++){
		treenode<int> *child = takeinput();
		root->children.push_back(child);
	}
	return root;
}

treenode<int> *takeinputlevelwise(){
	int rootdata;
	cout << "Enter root data:";
	cin >> rootdata;
	
	treenode<int> *root = new treenode<int>(rootdata);
	queue<treenode<int>*> pendingnodes;
	pendingnodes.push(root);

	while(pendingnodes.size()!=0){
		treenode<int> *front = pendingnodes.front();
		pendingnodes.pop();
		int num;
		cout<< "Enter num of children of " <<front->data <<endl;
		cin>>num;
		for(int i=0; i < num; i++){
			int childdata;
			cout << "Enter " << i <<"th child of " << front->data <<endl;
			cin >> childdata;
			treenode<int> *child = new treenode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}

print(treenode<int> *root){
	cout << root->data << ":";
	for(int i=0; i < root->children.size(); i++){
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for(int i=0; i < root->children.size(); i++){
		print(root->children[i]);
	}
}

int main(){
	treenode<int> *root = takeinputlevelwise();
	print(root);
	return 0;
}