#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <iterator>
class operators{
	private:
		double result;
		bool initialized;
	public:
		operators(){
			if (!initialized) {
				this->result = 0;
				initialized = true;
			}

		}
		virtual void calculate(std::vector<int> array) {};
		double get(){
			return this->result;
		}
		
		void resetVal(){
			this->result = 0;
		}
		
		void upd(double tempRe){
			this->result = tempRe;
		}
};

class plus : public operators{
	private:
		int size;
		double tempRe;
	public:
	plus(){
		this->size = 0;
		this->tempRe = 0;
	}	
		
	void calculate(std::vector<int> array, int method) {
	this->size = array.size();
	
  	for(int i = 0; i < this->size; i++)
  		this->tempRe = this->tempRe + array[i];	
		upd(this->tempRe);
	}
};

class minus : public operators{
	private:
		int size;
		double tempRe;
	public:
	minus(){
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->tempRe = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->tempRe = this->tempRe - array[i];
  		upd(this->tempRe);
	}	
};

class mult : public operators{
	private:
		int size;
		double tempRe;
	public:
	mult(){
		this->size = 0;
		this->tempRe = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->tempRe = 1;
	
  	for(int i = 0; i < this->size; i++)
  		this->tempRe = this->tempRe * array[i];
  		upd(this->tempRe);
  }
};

class divid : public operators{
	private:
		int size;
		double tempRe;
	public:
	divid(){
		this->size = 0;
		this->tempRe = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->tempRe = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->tempRe = this->tempRe / array[i];
  		upd(this->tempRe);
	}		
};

class calculator{
	private:
		double oldRe;
		std::vector<int> array;
		char op;
		int size;
	public:
		calc(){
			this->oldRe = 0;
		}
		
		void getArray(std::vector<int> arr){
			this->array = arr;
			this->size = arr.size();
		}
		
		double result(){
			return this->oldRe;
		}
		
		void MethodAUpd(){
			array.insert(array.begin(), this->result());
		}
		
		void Work(char op, int method){
			switch(op){
				case '+':{
				plus p;
				p.calculate(this->array, method);
				if (method == 1)
				this->oldRe = this->oldRe + p.get();
				else
				this->oldRe = p.get();
				}
				break;
				
				case '-':{
				minus m;
				m.calculate(this->array, method);
				if (method == 1)
				this->oldRe = this->oldRe - m.get();
				else
				this->oldRe = m.get();
				}
				break;	
				
				case '*':{
				mult mu;
				mu.calculate(this->array, method);
				if (method == 1)
				this->oldRe = this->oldRe * mu.get();
				else
				this->oldRe = mu.get();
				}
  				break;
  				
  				case '/':{
				divid d;
				d.calculate(this->array, method);
				if (method == 1)
				this->oldRe = this->oldRe / d.get();
				else
				this->oldRe = d.get();
				}
  				break;
			}
		}
				
};

int main () {
	//flags for looping and old result
  int rflag = 1;
  int firsttime = 1;
  	//calc constructor
  calculator calc;
  
  	//loop start
  while (rflag == 1) {
  	

  	
	//get numbers via string
  std::string string = "";
  std::cout<<"Enter your numbers : ";
  std::getline(std::cin,string);
  
  	//convert string to string stream to vector
  std::istringstream iss (string);
  std::vector<int> values((std::istream_iterator<int>(iss)),{});
  calc.getArray(values);
  
    //method for rerun, default 0/0
  int method = 0;
  
  
	//ON RERUN: select method, old -> totalnew or old -> new -> new -> new  
	if (firsttime == 0) {
		int invalid = 1;
		while (invalid == 1){
		invalid = 0;
		char choice;
		std::cout<<"Select a method: "<<std::endl<<"A - Insert the old result to the front of the vector"<<std::endl<<"B - Calculate the old result with the total result from the new vector"<<std::endl<<"--> ";
		std::cin>>choice;
			if (choice == 'A') {
				method = 0;
				calc.MethodAUpd();
			}
			else if (choice == 'B') method = 1;
			else {
				std::cout<<"Invalid choice!"<<std::endl;
				invalid = 1;
			}
		}
	}
	
  	//input operation
  char op;
  int iflag = 1;
  
  	//LOOP GET OP
  while (iflag == 1) {

	//get op
  std::cout<<"Enter Operator: ";
  std::cin>>op;
 	//stop loop from rerunning
  if (op == '+' || op == '-' || op == '*' || op == '/') iflag = 0;
  else iflag = 1;
	}
  calc.Work(op, method);
  std::cout<<"Result: "<<calc.result()<<std::endl;


  while (iflag == 0) {
  iflag = 1;
  std::cout<<std::endl<<"Again? (Y/N)"<<std::endl;
  char re;
  std::cin>>re;
  switch(re) {
  	case 'Y':
  		rflag = 1;
  		break;
  	case 'N':
  		rflag = 0;
  		break;
  	default:
  		std::cout<<"Invalid Respond"<<std::endl;
  		iflag = 0;
  		break;
  		}
  	}
  firsttime = 0;
  std::cin.ignore();
	}
}
	


