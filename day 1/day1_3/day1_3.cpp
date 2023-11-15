#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <iterator>

class operators{
	public:
		virtual void calculate(std::vector<int> array) {};
};

class plus : public operators{
	private:
		int result;
		int size;
	public:
	plus(){
		this->result = 0;
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array) {
	this->size = array.size();
	
  	for(int i = 0; i < this->size; i++)
  		this->result = this->result + array[i];
	}
	
	int get(){
		return this->result;
	}
		
};

class minus : public operators{
	private:
		int result;
		int size;
	public:
	minus(){
		this->result = 0;
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array){
	this->size = array.size();
	this->result = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->result = this->result - array[i];
	}
	
	int get(){
		return this->result;
	}
		
};

class mult : public operators{
	private:
		long int result;
		int size;
	public:
	mult(){
		this->result = 0;
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array){
	this->size = array.size();
	this->result = 1;
	
  	for(int i = 0; i < this->size; i++)
  		this->result = this->result * array[i];
	}
	
	long int get(){
		return this->result;
	}
		
};

class divid : public operators{
	private:
		float result;
		int size;
	public:
	divid(){
		this->result = 0;
		this->size = 0;
	}	
	
	void calculate(std::vector<int> array){
	this->size = array.size();
	this->result = array[0];
	
  	for(int i = 1; i < this->size; i++)
  		this->result = this->result / array[i];
	}
	
	float get(){
		return this->result;
	}
		
};

int main () {
	//get numbers via string
  std::string string;
  std::cout<<"Enter your numbers : ";
  std::getline(std::cin,string);
  	//convert string to string stream to vector
  std::istringstream iss (string);
  std::vector<int> values((std::istream_iterator<int>(iss)),{});
  
  	//input operation
  char op;
  int iflag = 1;
  while (iflag == 1) {
  iflag = 0;
  std::cout<<"Enter Operator: ";
  std::cin>>op;
  	//calculate
  long int total = 0;
  float total2 = 1;
  int size = values.size();
  switch(op) {
  	
  	case '+':{
	plus p;
	p.calculate(values);
	std::cout<<"Result: "<<p.get();
	}
  	break;  	
  	case '-':{
	minus m;
	m.calculate(values);
	std::cout<<"Result: "<<m.get();
	}
	break;
  	
  	case '*':{
	mult mu;
	mu.calculate(values);
	std::cout<<"Result: "<<mu.get();
	}
  	break;
  	
  	case '/':{
	divid d;
	d.calculate(values);
	std::cout<<"Result: "<<d.get();
	}
  	break;
  	
  	default:
  		std::cout<<"Invalid input"<<std::endl;
  		iflag = 1;
  	break;
  }
  }
}
