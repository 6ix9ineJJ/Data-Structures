#include <iostream>
using namespace std;

class stack{
	
	   private:
		
	        int *arr;
			int count;
			int top;  
			int size;
	
	   public:
	   	
	   	 stack();
	   	 void push(int );
	   	 void pop();	
	   	 void print();
};

stack::stack(){
	
	top = -1;
	cout<<"Enter the size of the stack"<<endl;
	cin>>size;
	arr = new int[size];
	
	count =0;
}

void stack::push(int val){
	
	if(top==size-1){
		cout<<"Stack Overflow"<<endl;
	      return;
	}
	
	else{
		top++;
		arr[top]=val;
		cout<<"value added to stack"<<arr[top]<<endl;
	}
	
}

void stack::pop(){
	
	  int v;
	if(top == -1){
		cout<<"Stack is empty"<<endl;
		
	}
	else{
		v=arr[top];
		top--;
		cout<<"Value deteled "<<v<<" "<<endl;
	}
}

void stack::print(){
	if(top == -1){
	 cout<<"Stack is empty"<<endl;
	 return;
	}
	else{
		cout<<arr[top]<<endl;
		top--;
	}
	
}
int main(){

stack s1;
s1.push(1);
s1.push(2);
s1.push(3);
s1.pop();
s1.print();
 
}


