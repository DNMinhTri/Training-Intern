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

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = boost::asio::ssl;
using tcp = net::ip::tcp;
namespace pt = boost::property_tree;

class HttpClient {
public:
    std::string* host;
    std::string* target;
    int* port;
    std::map<std::string,std::string>* custom_headers;
    beast::ssl_stream<beast::tcp_stream>* stream;
//methods
    HttpClient();
    ~HttpClient();
    virtual void createRequest() const;
    virtual std::string doTask() const;
    void Connect(const std::string& host, const std::string& target, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
};

class doGet : public HttpClient {
public:
    http::request<http::string_body>* req; 
    beast::flat_buffer* buffer;
//methods
    doGet();
    ~doGet();
    void createRequest() const override;
    std::string doTask() const override;
    void Connect(const std::string& host, const std::string& target, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
};

class doPost : public HttpClient {
public:
    http::request<http::string_body>* req; 
    beast::flat_buffer* buffer;
    std::string* message;
//methods
    doPost();
    ~doPost();
    
    void createRequest() const override;
    std::string doTask() const override;
    void Connect(const std::string& host, const std::string& target, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
};

class doPut : public HttpClient {
public:
    http::request<http::string_body>* req; 
    beast::flat_buffer* buffer;
    std::string* message;
//methods
    doPut();
    ~doPut();

    void createRequest() const override;
    std::string doTask() const override;
    void Connect(const std::string& host, const std::string& target, const int port=80, const std::map<std::string,std::string>& additional_headers = {});
};
#endif // HTTPCLIENT_H
