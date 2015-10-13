
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node* root = NULL;
	
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
 
 
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       
	printf("%d ",root->data);  
	Inorder(root->right);      
}
 
 
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
void Create(int tab[])
{
	int n=sizeof(tab);
	for(int k=0; tab[k]!=NULL; ++k){
		root = Insert(root,tab[k]); 
	}	
} 
bool Find(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		cout<<"Element "<<data<<" odnaleziono!\n";
		return true;
	}
	else if(data <= root->data) {
		return Find(root->left,data);
	}
	else {
		return Find(root->right,data);
	}
}
 
int main() {
	cout<<"-------------------------------------------------------------\n";
	cout<<"------Mateusz Buczynski-------------------03.IV.2015---------\n";
	cout<<"-------------------------------------------------------------\n";
	cout<<"-------------------------BST---------------------------------\n";
	cout<<"\n\n\n";
	int tab[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
	Create(tab);
	
	root = Insert(root, 20); 
	root = Insert(root,24); 
	root = Insert(root,23); 
	root = Insert(root,22); 
	
	
	root = Delete(root,10);
	root = Delete(root,5);
	
	Find(root,11);
	Find(root,22);
	Find(root,1);
	Find(root,2);
	
	cout<<"\n\n\n";
	
	cout<<"BST: ";
	Inorder(root);
	
	
	
	cout<<"\n";
	cout<<"\n\n\n";
	cout<<"----------------------------------------------KONIEC---------\n";
	cout<<"-------------------------------------------------------------\n";
}
