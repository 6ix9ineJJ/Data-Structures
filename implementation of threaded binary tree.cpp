#include <iostream>
using namespace std;

struct node{
	int info;
	node* left;
	node* right;	
    int leftthread;
    int rightthread;
	
};

class TBT{
	
	private:
		node *root, *temp, *dummy;
			
	public:	
		TBT();
		void create();
		void callprint();
		void insert(node * , node * );
		node *inorder_print(node *);
		void fastinorder();		
};

TBT::TBT(){
	
root = NULL;	
	
}

void TBT ::create(){
	
 temp = new node;
 cout<<"Enter the new info";
 cin>>temp->info;
 temp->left = NULL;
 temp->right = NULL;
 temp->leftthread=0;
 temp->rightthread = 0;
 
 if(root == NULL){
 	
 	root = temp;
 	dummy = new node;
 	dummy->info = 999;
 	dummy->right=dummy;
 	dummy->rightthread = 1;
 	dummy->left=root;
 	dummy->leftthread= 1;
 	root->right=dummy;
 	root->left=dummy;
 }
 
 else{
 	insert(root,temp);
 }
 
}

void TBT ::insert(node *root, node *temp ){
	
	if(temp->info < root->info){
		 if(root->left ==NULL){
		 	 root->left = temp;
		 	 temp->left=root->left;
		 	 root->leftthread=1;
		 	 temp->right=root;
		 }
		 else{
		insert(root->left,temp);
	}
	
}
	
	if(temp->info > root->info){
		 if(root->right ==NULL){
		 	 root->right = temp;
		 	 temp->right=root->right;
		 	 root->rightthread=1;
		 	 temp->right=root;
		 }
		 
		 else{
		 	 	
		    insert(root->right,temp);
	}
	
}


}

void TBT::callprint(){

	inorder_print(dummy);
}

 
node TBT::*inorder_print(node *temp){
	
if(temp->rightthread==0){
	return &(temp->right);
}

else{
	temp=temp->right;
}

while(temp->leftthread==1){
	temp=temp->left;
	return temp;
}

}
 
int main(){
	
	TBT t1;
	t1.create();
	
}
