#include <iostream>

#include <boost/asio.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <boost/asio/connect.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>

#include <boost/property_tree/json_parser.hpp> // Use Boost.PropertyTree for JSON
#include <string>

#include <sstream>
#include <iomanip>

#include "HttpClient.h"
#include <vector>
#include <thread>

//using namespace cms;
namespace beast = boost::beast;    // from <boost/beast.hpp>
namespace http = beast::http;      // from <boost/beast/http.hpp>
namespace net = boost::asio;       // from <boost/asio.hpp>
using tcp = net::ip::tcp;          // from <boost/asio/ip/tcp.hpp>
namespace pt = boost::property_tree;

int main() {
    //target info
    std::string host = "";
    std::string target = "";
    int port;
    
    //loop entire program
    int* flag2; flag2 = new int(1);
    int* flag; flag = new int(1);
    do {

    //get website
    if (*flag2 == 1) {
    std::cout<<"Host: "; std::getline(std::cin,host);
    std::cout<<"Target: "; std::getline(std::cin,target);
    std::cout<<"Port: "; std::cin>>port;

    std::cout<<std::endl;
    }

        int* loop; loop = new int(1);
        int* i; i = new int(100);
        while (*loop == 1) {
        std::cout<<"Pick a request to send"<<std::endl;
        std::cout<<"1 - Get"<<std::endl;
        std::cout<<"2 - Post"<<std::endl;
        std::cout<<"3 - Put"<<std::endl;
        std::cout<<"Option: ";
        std::cin>>*i;
        if (*i == 1 || *i == 2 || *i == 3) *loop = 0;
        }
        delete loop;
        HttpClient* Obj;
        switch(*i){
            case 1:
            {
                Obj = new doGet;

                break;
            }
            case 2:
            {
                Obj = new doPost;
                
                break;
            }
            case 3:
            {
                Obj = new doPut;

                break;
            }
            default: {
                std::cout<<"Retry please"<<std::endl;
                break;
            }
        }
        delete i;

        Obj->Connect(host,target,port,{});

        Obj->createRequest();

        std::cout<<Obj->doTask();

        //done with obj
        delete Obj;


    //CONTINUE PROGRAM Y/N
    int* loop2; loop2 = new int(1);
    int* e; e = new int(100);

    while (*loop2 == 1) {
    std::cout<<std::endl<<"Again?"<<std::endl;
    std::cout<<"1 - Again - Same target"<<std::endl;
    std::cout<<"2 - Again - Different target"<<std::endl;
    std::cout<<"3 - End"<<std::endl;
    std::cout<<"Option: ";
    std::cin>>*e;
    if (*e == 1 || *e == 2 || *e == 3) *loop2 = 0;
    }
    delete loop2; 

    //LOOP
    switch(*e)
    {
        case 1:{    //same website
            *flag = 1;
            *flag2 = 0;
            break;
        }
        case 2:{    //new website
            *flag = 1;
            *flag2 = 1;
            break;
        }
        default:{   //end
            *flag = 0;
            *flag2 = 0;
            break;
        }
    }
    delete e;

    std::cin.ignore();

    } while (*flag == 1);
    delete flag;
    delete flag2;
}


//#############################################################################################
