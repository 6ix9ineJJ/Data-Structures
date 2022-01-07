#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class Linklist{	
	private:
		int total;
		node *head, *temp,*temp1,*last,*curr,*move,*prev;
	
	public:
		Linklist();
		
		void Insert();
		void Add();
		void length();
		void Delete();
		void Head_Delete();
		void repeat();
		void Search();
		void count_even();
		void print();
		void last_delete();
		void reverse();	
		void sorting();
};

Linklist::Linklist(){
	
	head =temp=temp1=NULL;
	total=0;
}

void Linklist::Insert(){
	
 temp = new node;
 cout<<"enter the value "<<endl;
 cin>>temp->data;
 temp->next=NULL;
 
 if(head == NULL){
 	 head = temp;
 	 last = temp;
 }
else{
	last->next= temp;
	last= last->next;
}
	
}

void Linklist::Head_Delete(){
	
	if(head == NULL){
		cout<<"Head cant be deleted because its empty "<<endl;
		return;
	}
	
	  int key;
	cout<<"Enter the key for head "<<endl;
	cin>>key;
	
	temp =head;
	
	if(head->data==key){
		cout<<" key Founded"<<endl;
		head = head->next;
		delete temp;
		cout<<"Head Deleted "<<endl;
	}
	else{
		cout<<"This is not a value of head "<<endl;
	}
	
}


void Linklist::Add(){


    if(head == NULL)
	{
	    cout<<"Sorry !!! linklist is empty "<<endl;
	      return;
    }

	temp = head;
	
	int key;   
	cout<<endl;
	cout<<"Enter the value to add the number  if it is matched "<<endl;
	cin>>key;
	
	while(temp!=NULL){
		if(temp->data==key){
			cout<<"Key Matched "<<endl;
			cout<<endl;
			
			temp1 = new node;
			cout<<"Enter the value for temp1 new node "<<endl;
			cin>>temp1->data;
             temp1->next = temp->next;
			temp->next = temp1;
		}
		temp=temp->next;
		
	}
}

void Linklist ::Delete(){
	
	if(head == NULL){
		cout<<"Can't be deleted because its empty "<<endl;
		   return;
	}
	
	int key;
	
	cout<<"Enter the value to delete "<<endl;
	cin>>key;
		temp = head;
	while(temp->next!=NULL){
		if(temp->next->data==key){
			cout<<"valuke founded !!!"<<endl;
			
			temp1= temp->next;
			temp->next = temp1->next;
			
			delete temp1;
		}
		temp= temp->next;
	}
	cout<<endl;
	cout<<"VALUE DELETED "<<endl;
}

void Linklist::last_delete(){
	if (head == NULL){
		cout<<"Sorry can't be search because its empty "<<endl;
		   return;
			   }		   	
	int key;
	
   temp=head;
   cout<<"Enter the key to delete last node "<<endl;
   cin>>key;
   
   while(temp!=NULL){
   	if(temp->next->next==NULL){
	if(temp->next->data==key){
			   
   		cout<<"key Matched"<<endl;	
   		temp1=temp->next;
   		delete temp1;
   		temp->next=NULL;	
   	}
	   }
	   temp=temp->next;
}
  cout<<"Last Node Deleted "<<endl;

}

void Linklist::repeat(){
	
	temp=head;
	while(temp!=NULL){	
	while(temp->next!=NULL){
		if(temp->data==temp->next->data){
			total++;
		}
		temp=temp->next;
	}
	temp=temp->next;
}
	cout<<"Repeated Values are "<<total<<endl;
}

void Linklist::sorting(){

int temp_var;

if(head == NULL){
	cout<<"Empty Link List"<<endl;
}

temp=head;

while(temp!=NULL){
	
	if(temp->data>temp->next->data){
	 temp_var= temp->next->data;
	 temp->next->data=temp->data;
	 temp->data=temp_var;	
	}
	
	temp=temp->next;	
}

}

void Linklist::count_even(){
	
	temp=head;
	while(temp!=NULL){
		if(temp->data%2==0){
			total++;
		}
		temp=temp->next;
	}
	if(total>=3){
	cout<<"Even Numbers : "<<total<<endl;
	
}  else{
	cout<<"Even Numbers is less then 3 in linklist :"<<total<<endl;
}

}
void Linklist::Search(){
	
	if (head == NULL){
		cout<<"Sorry can't be search because its empty "<<endl;
		   return;
	}
	
	   temp = head;
	   int key;
	   cout<<"Enter the key to search "<<endl;
	   cin>>key;
	   cout<<"KEY ENTERED"<<endl;
	
	while(temp!=NULL){
		if(temp->data==key){
			cout<<"Key Founded !!!"<<endl;
		}
		temp=temp->next;
	}
}

void Linklist::length(){
	
	if (head == NULL){
		cout<<"Sorry Because its empty "<<endl;
		   return;
	}
	
	temp = head;
	
	while(temp!=NULL){
        total++;
        temp=temp->next;
			
	}
	cout<<"Total lenght of the linklist is "<<total<<endl;
}

void Linklist::reverse(){
	
   prev = NULL;	
	curr = head;
	
	while(curr!= NULL){
		
		move = curr->next;
		curr->next=prev;
		prev = curr;
	    curr = move;
	}
	head = prev;
	
	cout<<"Linklist reversed"<<endl;
}
	

void Linklist::print(){
	
	if(head == NULL){
		cout<<"Sorry linnklist is empty "<<endl;
		return;
	}
	
	temp= head;
	 cout<<"Linklist printed "<<endl;
	while(temp!=NULL){
		 
		
		 cout<<temp->data<<"->";
		 temp=temp->next;
	}
	cout<<"NULL";
	cout<<endl;
}


int main(){
	
	Linklist l1;
	
	l1.Insert();
	l1.Insert();
	l1.Insert();
	l1.Insert();
	l1.Insert();
	l1.Insert();
//	l1.Add();
//	l1.Add();
//	l1.Add();
//	l1.Add();
//l1.print();
	cout<<endl;
//	cout<<"Linklist before deleted head"<<endl;
  //   l1.Delete();
   //l1.Head_Delete();
  //  cout<<"Linkilist after deleted head"<<endl;
    cout<<endl;
   // l1.last_delete();
   //l1.repeat();
	l1.print();
//	cout<<"Linklist reversed"<<endl;
	l1.reverse();
	l1.print();
	//l1.count_even();
//	cout<<endl;
//	l1.Search();
//	cout<<endl;
//	l1.length();
	
	return 0;
}
