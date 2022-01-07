#include <iostream>
using namespace std;

class que{
	
	private:
		int size;
		int rear,front;
		int *arr;	
	public:
		
		que();
		bool isempty();
		bool isFull();
		void dequeue();
		void enqueue(int );
		void print();
};

que::que(){
	rear = -1;
	front = -1;
	
	cout<<"Enter the size of queue"<<endl;
	cin>>size;
    int *arr = new int [size];
	
	for(int i=0; i<size; i++){
		arr[i]=0;
	}
	
}

bool que ::isempty(){
	
	if(rear == -1 && front == -1){
		cout<<"Queue is empty !!"<<endl;
		return true;
	}
	
	else{
		cout<<"Quene is not empty"<<endl;
		return false;
	}
}

bool que ::isFull(){
	
	if(rear == size[arr]-1){
		cout<<"Queue is Full!!";
		return false;
	}
	
	else{
		cout<<"Queue is not Full"<<endl;
		return true;
	}
}

void que::enqueue(int val){
	
	if(isFull()){
		cout<<"Queue is Full"<<endl;
		return ;
	}
	
	else if(isempty()){
		front = rear = 0;
		
	}
	else{
		rear++;
	}
	
	 arr[rear]=val;
	
}



void que ::dequeue(){
	
	int value;
	if(isempty()){
		cout<<"Quene is Empty Now"<<endl;
		return;
	}
	
	else if(rear == front){
		value = arr[front];
		 rear = -1;
		 front = -1;
	}
	
	else{
		value = arr[front];
		front++;
	}
	
	cout<<value<<endl;
	
}

int main(){
	
	que q1;
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(9);
	
	return 0;
}
