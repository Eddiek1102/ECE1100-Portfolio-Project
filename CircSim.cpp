#include <iostream> 

using std::cout; 
using std::cin; 
using std::endl;



int main(){
	int a{}; 
	int b{};
	int c{};
	int d{};

	cout << "Enter value for a: ";
	cin >> a; 

	cout << "Enter value for b: "; 
	cin >> b; 

	cout << "Enter value for c: "; 
	cin >> c; 

	cout << "Enter value for d: "; 
	cin >> d; 

	cout<<"\n"; 
	cout<<"boolean expression: "; 

	if (a == 0){
		cout << "a' "; 
	}
	else if ((a > 1)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else if ((a < 0)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else{
		cout << "a "; 
	}


	if (b == 0){
		cout << "b' "; 
	}
	else if ((b > 1)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else if ((b < 0)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else{
		cout <<"b "; 
	}


	if (c == 0){
		cout << "c' "; 
	}
	else if ((c > 1)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else if ((c < 0)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else{
		cout << "c "; 
	}


	if (d == 0){
		cout << "d' ";
	}
	else if ((d > 1)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else if ((d < 0)){
		cout << "Enter a 0 or 1"<<endl; 
	}
	else{
		cout <<"d ";
	}

	

	
	return 0; 
}

