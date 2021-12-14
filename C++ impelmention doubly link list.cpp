#include <iostream>
using namespace std;

struct node{
	
	int info;
	node *next;
	node *prev;
};

class Doubly_linklist{
	
	private:
		node *head, *tail, *temp,*temp1;
	//	int total=0;
		
	public:
		
		Doubly_linklist();
		void Insert();
		void  Add();
		void Search();
		void Delete();
		void Length();
		void Delete_head();
		void Delete_last();
		void last_node();
		void first_node();
		void print();
};

Doubly_linklist::Doubly_linklist(){
    
    head = NULL;
    temp = NULL;
    temp1 = NULL;

}

void Doubly_linklist::Insert(){

  temp = new node;
  cout<<"enter the value "<<endl;
  cin>>temp->info;
  
  if(head == NULL){
    head = temp;
	temp->next= NULL;
	temp->prev= NULL;
	tail= temp;	
  }
  else{
  	temp->prev=tail;
  	tail->next=temp;
  	temp->next=NULL;
  	tail=temp;
  }
  
}     

void Doubly_linklist::Add(){
	if(head == NULL){
		cout<<"empty list "<<endl;
		return ;
	}
	
	int key;
	temp = head;
	cout<<endl;
	cout<<"Enter the key if it match it will add the key "<<endl;
	cin>>key;
	
	while(temp!=NULL){
		if(temp->info==key){
			temp1 = new node;
			cout<<"enter the value for new node "<<endl;
			cin>>temp1->info;
			
			temp1->next= temp->next;
			temp->next->prev=temp1;
			temp->next=temp1;
			temp1->prev=temp;
		}
		temp=temp->next;
	}
	
}

void Doubly_linklist::Delete_head(){
	
	int key;
	
  if(head == NULL){
  	
      cout<<"Empty !!! there is no head "<<endl;
     return ;
    }

   	    temp = head;
   	    
   	    if(temp->prev==NULL){
   	    	head = head->next;
   	    	temp1= temp;
   	    	delete temp1;
   	    	head->prev = NULL;
		
   }
   
      cout<<"Head Deleted "<<endl;
   
}


void Doubly_linklist::Delete_last(){
	
	  int key;
	
	if(head == NULL){
		cout<<" Sorry !! ,linklist is empty "<<endl;
		    return;
	}
	
   temp=head;
   cout<<"Enter the key to delete last node "<<endl;
   cin>>key;
   
   while(temp!=NULL){
   	if(temp->info==key){
   		cout<<"key Matched"<<endl;
   		  temp1=temp->prev;
   		  temp1=temp1->next;
   		  temp=temp->prev;
		 delete temp1;	
		 temp->next=NULL;
	   }
	   temp=temp->next;
}
  cout<<"Last Node Deleted "<<endl;

}
     


 void Doubly_linklist::Delete(){
	
	if(head == NULL){
		cout<<"Empty Linklist "<<endl;
		return;
	}
	
	temp= head;
	int key;
	cout<<"Enter the key you want to delete "<<endl;
	cin>>key;
	
	while(temp!=NULL){
		if(temp->info == key){
			cout<<"Key Matched"<<endl;
			
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			
			temp1=temp;
			delete temp1;
		}
		temp= temp->next;
	}
	cout<<"Deleted"<<endl;
	
}

void Doubly_linklist::print(){
	
	if(head == NULL){
		cout<<"Empty !!"<<endl;
		return ;
	}
	

	   temp = head;
	 cout<<"Doubly Linklist printed... "<<endl;
	 cout<<endl;
	  while(temp!=NULL){
	  	cout<<temp->info<<"<=>";
	  	temp =temp->next;
	  }
	  cout<<"NULL";	
}



int main(){
	Doubly_linklist d1;
	
	d1.Insert();
	d1.Insert();
	d1.Insert();
	d1.Insert();
	d1.Insert();
	d1.Add();
    cout<<"Before deleting l node "<<endl;
    d1.print();
    cout<<endl;
    d1.Delete();
  // d1.Delete_head();
   cout<<"After deleting  node "<<endl;
  // d1.Delete_last();
	d1.print();
	//cout<<endl;
	//cout<<"After deleting head"<<endl;
	
	return 0;
}


