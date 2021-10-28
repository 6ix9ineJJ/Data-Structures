#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};


class Circular_linklist{

   private:
   
   	node *head,*tail,*temp,*temp1;
   	
   public:
  
  Circular_linklist();
  void Insert();
  void Add();
  void Beg_node();
  void end_node();
  void 	Delete();
  void Search();
  void Delete_head();
  void Delete_tail();
  void print();
  void length();
  void Last_node();
  void First_node();
   
};


Circular_linklist::Circular_linklist(){
	head - NULL;
	temp = NULL;
	temp1 = NULL;
}

void Circular_linklist::Insert(){
	
	temp = new node;
	cout<<"Value please !!"<<endl;
	cin>>temp->info;
	
	if(head == NULL){
		head = temp;
		tail = temp;
	}
	else{
	  tail->next= temp;
	  temp->next=head;
	  tail=tail->next;
	  
	}
	
}

void Circular_linklist::Add(){
	
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
	
	while(temp->next!=head){
		if(temp->info==key){
			cout<<"Key Matched "<<endl;
			cout<<endl;
			
			temp1 = new node;
			cout<<"Enter the value for temp1 new node "<<endl;
			cin>>temp1->info;
             temp1->next = temp->next;
			temp->next = temp1;
		}
		temp=temp->next;
		
	}
	
}

void Circular_linklist::Beg_node(){

temp=new node;
cout<<"Enter new value "<<endl;
cin>>temp->info;

if(head == NULL){
	cout<<"call insert function "<<endl;
	return;
}

temp->next=tail->next;
tail->next=temp;


}

void Circular_linklist::end_node(){
	
	temp=new node;
	cout<<"Enter the value for new node "<<endl;
	cin>>temp->info;
	
	
	if(head == NULL){
		cout<<"Mera put chuti kr "<<endl;
		return;
	}
	
	
		temp->next=tail->next;
		tail->next = temp;
		tail=tail->next;
		
}

void Circular_linklist::Delete_head(){
	
	int key;
	
	if(head==NULL){
	  cout<<"Sorry !! "<<endl;
		return;
	}
	
	cout<<"Enter the key  to delete the head"<<endl;
	  cin>>key;
	
	temp=head;
	
	if(temp->info==key){
		
		head = head->next;
		tail->next=head;
		delete temp;
        
	}
	cout<<"deleted node";
	
}

void Circular_linklist::Delete(){
	
	if(head == NULL){
		cout<<"Can't be deleted because its empty "<<endl;
		   return ;
	}
	
	temp = head;
	int key;
	
	cout<<"Enter the value to delete "<<endl;
	cin>>key;
	
	while(temp->next!=head){
		if(temp->next->info==key){
			cout<<"value founded !!!"<<endl;
			
			temp1= temp->next;
			temp->next=temp->next->next;
		
			delete temp1;
		}
		temp= temp->next;
	}
	cout<<endl;
	cout<<"VALUE DELETED "<<endl;
}

void Circular_linklist::Delete_tail(){
		if (head == NULL){
		cout<<"Sorry can't be search because its empty "<<endl;
		   return;
			   }		   	
	int key;
	
   temp=head;
   cout<<"Enter the key to delete last node "<<endl;
   cin>>key;
   
   while(temp->next!=head){
   	if(temp->next->next==head){
	if(temp->next->info==key){
			   
   		cout<<"key Matched"<<endl;	
   		temp1=temp->next;
   		delete temp1;
   		temp->next=head;	
   	}
	   }
	   temp=temp->next;
}
  cout<<"Last Node Deleted "<<endl;
}

void Circular_linklist::print()
{
     
	if(head == NULL){
		cout<<"Sorry linnklist is empty "<<endl;
		return;
	}
	
	temp= head;
     
        do {
            cout<<temp->info<<" -> ";
			 temp = temp->next;
        }while(temp!=head);
        cout<<"Linklist printed "<<endl;
}
	 


int main(){
	
	Circular_linklist c1;
	c1.Insert();
	c1.Insert();
	c1.Insert();
	c1.Insert();
	c1.Insert();
//	c1.Insert();
//	c1.Insert();
//	c1.Insert();
//    c1.Add();
cout<<"Before Deleting "<<endl;
	c1.print();
	c1.Delete_head();
	c1.Delete_tail();
//	c1.Delete();
cout<<"After Deleting"<<endl;
  // c1.Beg_node();
  // c1.end_node();
	c1.print();
	
	
	return 0;
	
}
