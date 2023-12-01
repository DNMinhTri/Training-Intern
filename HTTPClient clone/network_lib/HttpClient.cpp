#include <HttpClient.h>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = boost::asio::ssl;
using tcp = net::ip::tcp;
namespace pt = boost::property_tree;

std::string HttpClient::doGet(const std::string& host, const std::string& target, const int port, const std::map<std::string, std::string>& custom_headers) {
    //this is required for all IO
    net::io_context io_context;

    // The SSL context is required, and holds certificates
    ssl::context ctx(ssl::context::tlsv12_client);

    // Verify the remote server's certificate
    ctx.set_verify_mode(ssl::verify_peer);
    ctx.set_default_verify_paths();

    //these objects handle IO
    tcp::resolver resolver(io_context);
    beast::ssl_stream<beast::tcp_stream> stream(io_context, ctx);

    // Set SNI Hostname (many hosts need this to handshake successfully)
       if(! SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
    {
        boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
        throw boost::system::system_error{ec};
    }

    //get domain name
    auto const results = resolver.resolve(host, std::to_string(port));
    beast::get_lowest_layer(stream).connect(results);

    //ssl handshake
    stream.handshake(ssl::stream_base::client);

    //set up get request
    http::request<http::string_body> req{http::verb::get, target, 11};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Insert the map of custom headers in
    if (!custom_headers.empty()){
        for (const auto& header: custom_headers){
            req.set(header.first, header.second);
        }
    }

    //send get request
    http::write(stream, req);

    //buffer for reading
    beast::flat_buffer buffer;

    //declare a container to hold the response
    http::response<http::dynamic_body> res;

    //receive response
    http::read(stream, buffer, res);

    //return result
    return boost::beast::buffers_to_string(res.body().data());
}

std::string HttpClient::doPost(const std::string& host, const std::string& target, const pt::ptree& message,const int port, const std::map<std::string, std::string>& custom_headers) {
    
     //this is required for all IO
    net::io_context io_context;

    // The SSL context is required, and holds certificates
    ssl::context ctx(ssl::context::tlsv12_client);
    ctx.set_options(ssl::context::default_workarounds | ssl::context::no_sslv2 | ssl::context::no_sslv3);

    // Verify the remote server's certificate
    ctx.set_verify_mode(ssl::verify_peer);
    ctx.set_default_verify_paths();

    //these objects handle IO
    tcp::resolver resolver(io_context);
    beast::ssl_stream<beast::tcp_stream> stream(io_context, ctx);

    // Set SNI Hostname (many hosts need this to handshake successfully)
    if(! SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
    {
        boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
        throw boost::system::system_error{ec};
    }

    //get domain name
    auto const results = resolver.resolve(host, std::to_string(port));
    beast::get_lowest_layer(stream).connect(results);

    //ssl handshake
    stream.handshake(ssl::stream_base::client);

    //set up POST request
    http::request<http::string_body> req{http::verb::post, target, 11};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::content_type, "application/json");
    std::stringstream ss;
    boost::property_tree::write_json(ss, message);
    std::string request_body = ss.str();
    req.set(http::field::content_length, std::to_string(request_body.length()));
    req.body() = request_body;
    req.prepare_payload();
    
    
    
    // Insert the map of custom headers in
    if (!custom_headers.empty()){
        for (const auto& header: custom_headers){
            req.set(header.first, header.second);
        }
    }

    //send get request
    http::write(stream, req);

    //buffer for reading
    beast::flat_buffer buffer;

    //declare a container to hold the response
    http::response<http::dynamic_body> res;

    //receive response
    http::read(stream, buffer, res);

    //return result
    return boost::beast::buffers_to_string(res.body().data());
}

std::string HttpClient::doPut(const std::string& host, const std::string& target, const pt::ptree& message, const int port, const std::map<std::string, std::string>& custom_headers) {
    //this is required for all IO
    net::io_context io_context;

    // The SSL context is required, and holds certificates
    ssl::context ctx(ssl::context::tlsv12_client);
    ctx.set_options(ssl::context::default_workarounds | ssl::context::no_sslv2 | ssl::context::no_sslv3);

    // Verify the remote server's certificate
    ctx.set_verify_mode(ssl::verify_peer);
    ctx.set_default_verify_paths();

    //these objects handle IO
    tcp::resolver resolver(io_context);
    beast::ssl_stream<beast::tcp_stream> stream(io_context, ctx);

    // Set SNI Hostname (many hosts need this to handshake successfully)
    if(! SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
    {
        boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
        throw boost::system::system_error{ec};
    }

    //get domain name
    auto const results = resolver.resolve(host, std::to_string(port));
    beast::get_lowest_layer(stream).connect(results);

    //ssl handshake
    stream.handshake(ssl::stream_base::client);

    //set up PUT request
    http::request<http::string_body> req{http::verb::put, target, 11};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::content_type, "application/json");
    std::stringstream ss;
    boost::property_tree::write_json(ss, message);
    std::string request_body = ss.str();
    req.set(http::field::content_length, std::to_string(request_body.length()));
    req.body() = request_body;
    req.prepare_payload();
    
    
    
    // Insert the map of custom headers in
    if (!custom_headers.empty()){
        for (const auto& header: custom_headers){
            req.set(header.first, header.second);
        }
    }

    //send get request
    http::write(stream, req);

    //buffer for reading
    beast::flat_buffer buffer;

    //declare a container to hold the response
    http::response<http::dynamic_body> res;

    //receive response
    http::read(stream, buffer, res);

    //return result
    return boost::beast::buffers_to_string(res.body().data());
}

