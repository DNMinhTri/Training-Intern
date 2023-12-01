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
//namespace pt = boost::property_tree;

int main() {
    HttpClient* connect = new HttpClient;
    boost::property_tree::ptree pt;
    pt.put("hello", "hi");
    std::cout<<connect->doPut("httpbin.org","/put",pt,443,{});
}


//#############################################################################################

