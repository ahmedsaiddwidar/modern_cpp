//basically same as ptr bu do not take size
//can not be initialized to null
//it must reference for an existing variable or object
//ref is just an alias of the variable or object
//is more simple than ptr related to the syntax

int x;
int &refX = x;

int &ref ; // error 
//the ampersand is just used for type definition
//we can not use same ref to ref another var or object, we just declare another ref
int a = 5;
int b = 6;
int &ref = a;
ref = b; // error

// do not use deferencing for reading or writing
// must be initialized at declaration

//we can define const ref means it will not be able to modify the var but it does not mean the variable itself is const

//one of the uses for ref is in range based loops to change the actual data by references(aliases)
//as in range based loops we do not modify the actual elements but c++ take a copy of that element and perform the operation

-- Can we have a reference to a pointer in C++?
	YES 
	
	  int*& ptr2 = ptr;

1- you can pass arguments by reference 
	
		void func(int &x) // note here : nta ma5tdsh msa7a fel memeory 
	{
		x = 6;
	}



	int main()
	{
		int arg = 7;

		func(arg);

		cout<<arg<<endl;  // prints 6
	}


-- nta hena bt2olo in da const , fa nta msh hat8yer feeh, fa nta lw b3t const= value .. howa damn ink msh ta5yer feeh 
-- low shelt const.. msh hat2dr tb3t 


	void func(const int& z){

           cout<<z<<endl;  // it works l7d hena
	    z = 5;      // error 

		}
		
	int main(){
	
	 func(5); // it works because of const, without const == error 
	}

    			------------ return by reference ----------
			
1- 
	int x;  // global varaible 
	
	int& func(){

	  return x;
	}




        func() = 6;  // it works  == x = 6
	 int y = func();  // warning but still works 	   
	cout<<y<<endl;   // 6
	
	y = 10;
	cout<<x<<endl;   // still 6 not 10
	
	int& z = func();
	z = 10;
	cout<<x<<endl;  // 10 
	
	
2-  

	int& func(){
	 
	 int x  = 5;
	  return x;   // Errrrror 
	}
	



3- 
	int& func(){

	  return 5; // compiler error 
	}
	
	
	

4- 	
	int x = 5;  // global varaible

	int func() {
	  return x; // rvlaue
	}

	
	int && y = func(); // it works 
	
	
but : 	
	int& func(){
	return x;
	}
	
	int&& y = func(); // error .. it need rvalue not lvalue( x)