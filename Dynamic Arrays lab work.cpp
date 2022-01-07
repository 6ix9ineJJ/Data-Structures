#include <iostream>
using namespace std;

class list{
	
	private:
		int *arr = 0; 
		int *curr, *temp, pos, last;
		int total;
		int length, size;
		
	public:
		list();
	void insert(int );
	void remove(int);
	int get(int );
	void update(int, int );
	bool find(int );
	int leng();
    void back();
    void next();
    void start();
    void end();
	void print();
		
};

list::list(){
	
	//intialize the size of array
	cout<<"Enter the size "<<endl;
	cin>>size;
	
	arr =  new int [size];
	curr = arr;
	
	for(int i=0; i<size; i++){
		*curr =0;
		curr=curr+1;
	}
	
  curr = NULL;
}

void list::insert( int x)
{
	if(length == 0){
		curr= arr;
		*curr=x;
		length++; 
		return;
	}
	
	if(length == size){
		cout<<"Array is Full !!"<<endl;
	}
	
	curr = arr;
	curr = curr + length; 
	*curr = x;
	length++;
	return ;
	
}

void list::remove(int x){
	curr = arr;
	int sum = 0;
	for (int i = 0; i<size; i++){
		if(*curr == x){
			sum++;
			*curr = 0;
			
		}
		curr++;
	}
	for (int i = 0; i<sum ; i++){
		curr = arr;
		
		for(int i=0; i<length; i++){
		     if(*curr== 0){
     	*curr = *(curr+1);
        *(curr+1)=0;
			 }
			 curr++;
			 	
		length = length - sum;
	
}
	cout<<" deleted = "<<x<<endl;

}

}
	
	
int list ::get(int pos ){
	
	if(pos>length){
		cout<<"Position not found"<<endl;
	}
	
	else{
	
		curr = arr;
}
	for(int i=0; i<pos; i++){
		
		*curr = *curr +1;
	}
	cout<<"value of this position = "<<pos<<" is "<<*curr<<endl;
     	
}

void list::update(int val, int pos){
	
	
	if(pos>length ){
		cout<<"Sorry there is no position "<<endl;
	}

else{
	curr = arr;
 for(int i=0; i<pos; i++){
 	*curr= *curr+1;
 }	
 *curr = val;

cout<<"value has changed and updated on this position "<<endl;
   	
   }

}

bool list ::find(int val){
	
	
	curr = arr;

	  for(int i = 0; i<length; i++){
		
		if(*curr ==val){
			curr++;
				cout<<"value found = "<<val<<endl;
				return true;
		}
		
	}

		cout<<"Value not found "<<endl;
		return false;

		
}

int list:: leng(){
	curr = arr;
	
	for(int i= 0; i<size; i++){
		if(*curr != 0)
		total++;
	}
	cout<<"total length = "<<total <<endl;

}

void list::start(){
	
	curr = arr;
	cout<<"Starting value = "<<*curr<<endl;
}
void list::end(){
	
	curr = arr;
	
	for(int i =0; i<length-1; i++){
		curr++;
	}
	cout<<"ending of array "<<*curr<<endl;
}
void list ::print(){
	
	curr = arr;
	for(int i =0 ; i<size; i++){
		cout<<*curr<<endl;
		curr++;
	}
	
}

void list::next(){
	
	temp = arr;
	
	for(int i =0; i<length ; i++){
		*temp = last;
		temp++;
	}
	
	if (*curr!= last ){
		for(int i= 0; i<1; i++){
			*curr++;
		}
		cout<<"next value "<<*curr<<endl;
	}
	
  else{
  	cout<<"there is no next value "<<endl;
  }

}


int main() {
	list l1;
	list l2 = l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.print();
	l1.remove(3);
	l1.remove(1);
	l1.start();
	l1.end();
	l1.print();



	return 0;
}
