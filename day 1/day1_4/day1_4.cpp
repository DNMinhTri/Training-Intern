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
		double update(double newRe, int method){
		switch(method){
			case 0:
				this->result = newRe;
			break;
			case 1:
				this->result = this->result + newRe;
			break;
			
			case 2:
				this->result = this->result - newRe;
			break;
			
			case 3:
				this->result = this->result * newRe;
			break;
			
			case 4:
				this->result = this->result / newRe;
			break;
		}
		}
		
		void resetVal(){
			this->result = 0;
		}
};

class plus : public operators{
	private:
		int size;
		double newRe;
	public:
	plus(){
		this->size = 0;
		this->newRe = 0;
	}	
	
	void calculate(std::vector<int> array, int method) {
	this->size = array.size();
	
  	for(int i = 0; i < this->size; i++)
  		this->newRe = this->newRe + array[i];
  	if (method == 1)
  	update(this->newRe, 1);
  	else
  	update(this->newRe, 0);
	}
			
};

class minus : public operators{
	private:
		int size;
		double newRe;
	public:
	minus(){
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->newRe = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->newRe = this->newRe - array[i];
  	if (method == 1)
  	update(this->newRe, 2);
  	else
  	update(this->newRe, 0);
	}
	
};

class mult : public operators{
	private:
		int size;
		double newRe;
	public:
	mult(){
		this->size = 0;
		this->newRe = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->newRe = 1;
	
  	for(int i = 0; i < this->size; i++)
  		this->newRe = this->newRe * array[i];
  	if (method == 1)
  	update(this->newRe, 3);
  	else
  	update(this->newRe, 0);
	}	
};

class divid : public operators{
	private:
		int size;
		double newRe;
	public:
	divid(){
		this->size = 0;
		this->newRe = 0;
	}	
	
	void calculate(std::vector<int> array, int method){
	this->size = array.size();
	this->newRe = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->newRe = this->newRe / array[i];
  	if (method == 1)
  	update(this->newRe, 4);
  	else
  	update(this->newRe, 0);
	}		
};

int main () {
	//flags for looping and old result
  int rflag = 1;
  int firsttime = 1;
  double oldRe = 0;
  
  	//loop start
  while (rflag == 1) {
  	
	//get numbers via string
  std::string string = "";
  std::cout<<"Enter your numbers : ";
  std::getline(std::cin,string);
  
  	//convert string to string stream to vector
  std::istringstream iss (string);
  std::vector<int> values((std::istream_iterator<int>(iss)),{});
  
    //method and position for rerun, default 0/0
  int method = 0;
  
  
	//ON RERUN: select method, old -> totalnew or old -> new -> new -> new  
	if (firsttime == 0) {
		int invalid = 1;
		while (invalid == 1){
		invalid = 0;
		char choice;
		std::cout<<"Select a method: "<<std::endl<<"A - Squeeze the old result in the middle of the vector pre-calculation"<<std::endl<<"B - Calculate the old result with the total result from the new vector"<<std::endl<<"--> ";
		std::cin>>choice;
			if (choice == 'A') {
				method = 0;
				values.insert(values.begin(), oldRe);
				
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
  
  	//operator loop
  while (iflag == 1) {
  	//stop loop from rerunning
  iflag = 0;
	//get op
  std::cout<<"Enter Operator: ";
  std::cin>>op;
  
  	//calculate
  int size = values.size();
  switch(op) {
  	
  	//plus
  	case '+':{
	plus p;
	p.calculate(values, method);
	std::cout<<"Result: "<<p.get();
	oldRe = p.get();
	}
  	break;  
	  
	//minus	
  	case '-':{
	minus m;
	m.calculate(values, method);
	std::cout<<"Result: "<<m.get();
	oldRe = m.get();
	}
	break;
  	
  	
  	//multiply
  	case '*':{
	mult mu;
	mu.calculate(values, method);
	std::cout<<"Result: "<<mu.get();
	oldRe = mu.get();
	}
  	break;
  	
  	
  	//divide
  	case '/':{
	divid d;
	d.calculate(values, method);
	std::cout<<"Result: "<<d.get();
	oldRe = d.get();
	}
  	break;
  	
  	//unrecognize, keep looping
  	default:
  		std::cout<<"Invalid input"<<std::endl;
  		iflag = 1;
  	break;
  }
  }
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
  firsttime = 0;
  std::cin.ignore();
}
}
return 0;
}
