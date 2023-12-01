#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include "boost/lexical_cast.hpp"
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
//#include <boost/lexical_cast.hpp>

//#include <context.hpp>
#include <map>
#include <boost/property_tree/json_parser.hpp> // Use Boost.PropertyTree for JSON
#include <boost/property_tree/ptree.hpp>

class HttpClient {
public:
    static std::string doGet(const std::string& host, const std::string& target, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
    static std::string doPost(const std::string& host, const std::string& target, const boost::property_tree::ptree &message, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
    static std::string doPut(const std::string& host, const std::string& target, const boost::property_tree::ptree &message, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
};

#endif // HTTPCLIENT_H

