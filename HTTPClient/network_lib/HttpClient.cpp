#include <HttpClient.h>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = boost::asio::ssl;
using tcp = net::ip::tcp;
namespace pt = boost::property_tree;


//HTTP CLIENT SESSION
HttpClient::HttpClient(){
    host = new std::string;
    target = new std::string;
    port = new int;
    //custom_headers = new std::map<std::string, std::string>({});
    
    return;
}

HttpClient::~HttpClient(){
    delete host;
    delete target;
    delete port;
    //delete custom_headers;
    return;
}
std::string HttpClient::doTask() const {
    return "no task given";
}

void HttpClient::createRequest() const {
    return;
}

void HttpClient::Connect(const std::string& hos, const std::string& tar, const int po, const std::map<std::string, std::string>& additional_headers){

    //HttpClient* curr;
    custom_headers = new std::map<std::string, std::string>(additional_headers);
    *target = tar;
    *port = po;
    *host = hos;
    
    //this is required for all IO
    net::io_context io_context;
    
    // The SSL context is required, and holds certificates
    ssl::context ctx(ssl::context::tlsv12_client);
    
    // Verify the remote server's certificate
    ctx.set_verify_mode(ssl::verify_peer);
    ctx.set_default_verify_paths();
    

    //these objects handle IO
    tcp::resolver resolver(io_context);
    stream = new beast::ssl_stream<beast::tcp_stream>(io_context, ctx);

    // Set SNI Hostname (many hosts need this to handshake successfully)
       if(! SSL_set_tlsext_host_name(stream->native_handle(), host->c_str()))
    {
        boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
        throw boost::system::system_error{ec};
    }
    
    //get domain name
    auto const results = resolver.resolve(*host, std::to_string(*port));
    beast::get_lowest_layer(*stream).connect(results);

    //ssl handshake
    stream->handshake(ssl::stream_base::client);

    return;
}


//DO GET SESSION
doGet::doGet() {
    //create buffer for result
    buffer = new beast::flat_buffer;
    //set up get request
    req = new http::request<http::string_body>;
}
void doGet::createRequest() const {
    req->method(http::verb::get);
    req->target(*target);
    req->version(11);
    req->set(http::field::host, *host);
    req->set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Insert the map of custom headers in
    if (!custom_headers->empty()){
        for (const auto& header: *custom_headers){
            req->set(header.first, header.second);
        }
    }
    return;
}

doGet::~doGet(){
    delete req;
    delete buffer;
    return;
}

std::string doGet::doTask() const {
    http::write(*stream, *req);

    //buffer for reading
    beast::flat_buffer buffer;
    
    //declare a container to hold the response
    http::response<http::dynamic_body>res;

    //receive response
    http::read(*stream, buffer, res);

    //return result
    return boost::beast::buffers_to_string(res.body().data());
}

//DO POST SESSION
doPost::doPost() {
    //create buffer for result
    buffer = new beast::flat_buffer;
    //set up get request
    req = new http::request<http::string_body>;
    //set up message
    message = new std::string;
}

doPost::~doPost(){
    delete req;
    delete buffer;
    delete message;
    return;
}

void doPost::createRequest() const {
    req->method(http::verb::post);
    req->target(*target);
    req->version(11);
    req->set(http::field::host, *host);
    req->set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    //prepare message
    std::cout<<"What is your message: ";    std::cin.ignore();      std::getline(std::cin,*message);

    req->set(http::field::content_length, std::to_string(message->length()));
    req->body() = *message;
    req->prepare_payload();

    // Insert the map of custom headers in
    if (!custom_headers->empty()){
        for (const auto& header: *custom_headers){
            req->set(header.first, header.second);
        }
    }

    return;
}

std::string doPost::doTask() const {
    http::write(*stream, *req);

    //buffer for reading
    beast::flat_buffer buffer;

    //declare a container to hold the response
    http::response<http::dynamic_body>res;

    //receive response
    http::read(*stream, buffer, res);

    //return result
    return boost::beast::buffers_to_string(res.body().data());
}

//DO PUT SESSION
doPut::doPut() {
    //create buffer for result
    buffer = new beast::flat_buffer;
    //set up get request
    req = new http::request<http::string_body>;
    //set up message
    message = new std::string;
}

doPut::~doPut(){
    delete req;
    delete buffer;
    delete message;
    return;
}

void doPut::createRequest() const {
    req->method(http::verb::put);
    req->target(*target);
    req->version(11);
    req->set(http::field::host, *host);
    req->set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    //prepare message
    std::cout<<"What is your message: ";    std::cin.ignore();      std::getline(std::cin,*message);

    req->set(http::field::content_length, std::to_string(message->length()));
    req->body() = *message;
    req->prepare_payload();

    // Insert the map of custom headers in
    if (!custom_headers->empty()){
        for (const auto& header: *custom_headers){
            req->set(header.first, header.second);
        }
    }
    
    return;
}

std::string doPut::doTask() const {
    http::write(*stream, *req);
    
    //buffer for reading
    beast::flat_buffer buffer;
    
    //declare a container to hold the response
    http::response<http::dynamic_body>res;
    
    //receive response
    http::read(*stream, buffer, res);
   
    //return result
    return boost::beast::buffers_to_string(res.body().data());
}