#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *prev;
};

class Ring_list{
	
		private:
		node *head, *tail, *temp,*temp1;
		
		
	public:
		
		Ring_list();
		void Insert();
		void  Add();
		void Search();
		void Delete();
		void delete_last();
		void delete_head();
		void print();
		
};

Ring_list::Ring_list(){
	
	head=temp=temp1=NULL;
	int total=0;
}

void Ring_list::Insert(){
	
	 temp = new node;
     cout<<"enter the value "<<endl;
     cin>>temp->info;
  
  if(head == NULL){
    head = temp;
    tail = temp;

  }
  
  else{
  
  	temp->next=head;
  	temp->prev=tail;
  	tail->next=temp;
  	tail=tail->next;
  }
  
}

void Ring_list::Add(){
	
	if(head == NULL){
		cout<<"empty list "<<endl;
		return ;
	}
	
	int key;
	temp = head;
	cout<<endl;
	cout<<"Enter the key if it match it will add the key "<<endl;
	cin>>key;
	
	while(temp->next!=head){
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

void Ring_list::delete_last(){
	
		  int key;
	
	if(head == NULL){
		cout<<" Sorry !! ,linklist is empty "<<endl;
		    return;
	}
	
   temp=head;
   cout<<"Enter the key to delete last node "<<endl;
   cin>>key;
   
   temp= head;
     
        do {
        	
          if(temp->info==key){
          cout<<"IN"<<endl;	   	
   		  cout<<"key Matched"<<endl;
   		  temp1=temp->prev;
   		  temp1=temp1->next;
   		  temp=temp->prev;
		  delete temp1;	
		  temp->next=head;
		  head->prev=temp;
	   }
	   temp=temp->next;
        }while(temp!=head);
        cout<<"Last Node Deleted "<<endl;
}
  



void Ring_list::delete_head(){
	
	int key;
	
  if(head == NULL){
  	
      cout<<"Empty !!! there is no head "<<endl;
     return ;
    }

   	    temp = head;
   	     cout<<"Enter the value for head"<<endl;
		 cin>>key;
		 
		 if(head->info==key){
		    cout<<"Key matched"<<endl;
   	    	cout<<endl;
   	    	head = head->next;
   	    	temp1=temp;
   	    	delete temp1;
   	    	head->prev=tail;
   	    	tail->next=head;
   	    	cout<<"Head Deleted "<<endl;
   }
   
}

void Ring_list::Delete(){
	
	if(head == NULL){
		cout<<"Empty Linklist "<<endl;
		return;
	}
	
	
	int key;
	cout<<"Enter the key you want to delete "<<endl;
	cin>>key;
	temp= head;	
	
	while(temp->next!=head){
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


void Ring_list::print(){
	
		if(head == NULL){
	   cout<<"Sorry Ringlist is empty "<<endl;
		    return;
	}
	
	temp= head;
     
        do {
            cout<<temp->info<<"->";
			 temp = temp->next;
        }while(temp!=head);
        cout<<"Ringlist printed "<<endl;
}



int main(){
	
	Ring_list r1;
	
	r1.Insert();
	r1.Insert();
	r1.Insert();
	r1.Insert();
	r1.Insert();
	r1.Insert();
//	r1.Add();
	cout<<endl;
	cout<<"Before Deleting Node "<<endl;
//	r1.delete_head();
	cout<<endl;
	r1.Delete();
	r1.delete_last();
	r1.print();
	cout<<endl;
	cout<<"After Deleting Node"<<endl;
    //cout<<"Before deleting l node "<<endl;
    r1.print();
    cout<<endl;
    	
	return 0;
}

