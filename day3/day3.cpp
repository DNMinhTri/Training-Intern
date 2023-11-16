#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <iterator>
class operators{
	private:
		double* result;
	public:
		operators(){
			result = new double(0);
		}
		
		~operators(){
			delete result;	
		}
		
		double get(){
			return *result;
		}
				
		void upd(double* tempRe){
			*result = *tempRe;
		}

		
		virtual double simpcalc(double A, double B) const {
			return 0;
		}
};

class plus : public operators{
	public:
	plus(){
	}
	
	~plus(){
	}	
	
	double simpcalc(double A, double B) const override {
		return A + B;
	}
};

class minus : public operators{
	public:
	minus(){
	}	
	
	~minus(){
	}
	
	double simpcalc(double A, double B) const override {
	return A - B;
	}
		
};

class mult : public operators{
	public:
	mult(){
	}	
	
	~mult(){
	}
  	
  	double simpcalc(double A, double B) const override {
	return A * B;
	}
  	
};

class divid : public operators{
	public:
	divid(){
	}
	
	~divid(){
	}
	
	double simpcalc(double A, double B) const override {
	return A / B;
	}
			
};

class calculator{
	private:
		double* oldRe;
		int* size;
		std::vector<int>* array;
	public:
		calculator(){
			oldRe = new double;
			size = new int;
			array = NULL;
		}
		
		~calculator(){
			delete oldRe;
			delete size;
			delete array;
		}
		
		void getArray(std::vector<int>* arr){
			this->array = arr;
			*size = arr->size();
		}
		
		double result(){
			return *oldRe;
		}
		
		void MethodAUpd(){
			array->insert(array->begin(), this->result());
			*size = array->size();
		}
		
		void Work(char* op, int* method){
			operators* action;
			
			switch(*op){
				case '+':{
				action = new plus;
				}
				break;
				
				case '-':{
				action = new minus;
				}
				break;	
				
				case '*':{
				action = new mult;
				}
  				break;
  				
  				case '/':{
				action = new divid;
				}
  				break;
			}
			
			//calculate by array
			double* tempRe = new double((*array)[0]);
			for (int i = 1; i < (*size); i++){
				*tempRe = action->simpcalc(*tempRe, (*array)[i]); 
			}
			
			//Update stored value and delete temp
			action->upd(tempRe);
			delete tempRe;
			
			//handlng old value if needed
			if (*method == 1) {
			*oldRe = action->simpcalc(*oldRe, action->get());
			}
			else *oldRe = action->get();
			
			//done with operation
			delete action;
		}
				
};

int main () {
	//flags for looping and old result
  int* rflag = new int(1);
  bool firsttime = true;
  	//calc constructor
  calculator* calc = new calculator;
  	//loop start
  while (*rflag == 1) {
  	

  	
	//get numbers via string
  std::string string = "";
  std::cout<<"Enter your numbers : ";
  std::getline(std::cin,string);
  
  	//convert string to string stream to vector
  std::istringstream iss (string);
  	//no longer need string
  string.clear();
  
  std::vector<int>* vaptr = new std::vector<int>((std::istream_iterator<int>(iss)),{});
  
  calc->getArray(vaptr);
  
    //method for rerun, default 0/0
  int* method = new int(0);
  
  
	//ON RERUN: select method, old -> totalnew or old -> new -> new -> new  
	if (!firsttime) {
		int invalid = 1;
		while (invalid == 1){
		invalid = 0;
		char choice;
		std::cout<<"Select a method: "<<std::endl<<"A - Insert the old result to the front of the vector"<<std::endl<<"B - Calculate the old result with the total result from the new vector"<<std::endl<<"--> ";
		std::cin>>choice;
			if (choice == 'A') {
				*method = 0;
				calc->MethodAUpd();
			}
			else if (choice == 'B') *method = 1;
			else {
				std::cout<<"Invalid choice!"<<std::endl;
				invalid = 1;
			}
		}
	}
	
  	//input operation
  char* op = new char;
  int* iflag = new int(1);
  
  	//loop to get op with iflag
  while (*iflag == 1) {

	//get op
  std::cout<<"Enter Operator: ";
  std::cin>>*op;
 	//stop loop from rerunning
  if (*op == '+' || *op == '-' || *op == '*' || *op == '/') *iflag = 0;
  else *iflag = 1;
	}
	//calc work
  calc->Work(op, method);
  
 	//delete method
  delete method;
  
  	//print result
  std::cout<<"Result: "<<calc->result()<<std::endl;

	//loop check for continue, reusing iflag
  while (*iflag == 0) {
  *iflag = 1;
  std::cout<<std::endl<<"Again? (Y/N)"<<std::endl;
  char* re;
  re = new char;
  std::cin>>*re;
  switch(*re) {
  	case 'Y':
  		*rflag = 1;
  		break;
  	case 'N':
  		*rflag = 0;
  		break;
  	default:
  		std::cout<<"Invalid Respond"<<std::endl;
  		*iflag = 0;
  		break;
  		}
  	
  	//no longer need char
  	delete re;	
  	}	
  	
  	//delete iflag, first time false
  	delete iflag;
  	firsttime = false;
  	std::cin.ignore();
	}
	//no longer looping
	delete rflag;
	delete calc;
}
	


