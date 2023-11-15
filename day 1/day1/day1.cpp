#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <iterator>

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
  	case '+':
  		for(int i = 0; i < size; i++)
  			total = total + values[i];
  		std::cout<<"Result: "<<total;
  	break;
  	
  	case '-':
  		total = values[0];
  		for(int i = 1; i < size; i++)
  			total = total - values[i];
  		std::cout<<"Result: "<<total;
  	break;
  	
  	case '*':
  		total++;
  		for(int i = 0; i < size; i++)
  			total = total * values[i];
  		std::cout<<"Result: "<<total;
  	break;
  	
  	case '/':
  		total2 = values[0];
  		for(int i = 1; i < size; i++)
  			total2 = total2 / values[i];
  		std::cout<<"Result: "<<total2;
  	break;
  	
  	default:
  		std::cout<<"Invalid input"<<std::endl;
  		iflag = 1;
  	break;
  }
  }
}
