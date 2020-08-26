#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "udp_server.h"
#include <iostream>
#include <string>

udp_server::udp_server()
{
    printf("Made it here.\n");
    try
    {
        printf("And Here.\n");
        boost::asio::io_context io_context;

        for (;;)
        {
            printf("In Loop.\n");
            boost::asio::ip::udp::socket socket(
                    io_context,
                    boost::asio::ip::udp::endpoint{boost::asio::ip::udp::v4(), 3303});

            boost::asio::ip::udp::endpoint client;
            boost::array<char, 65527> recv_str;
            std::size_t len = socket.receive_from(
                    boost::asio::buffer(recv_str),
                    client);
            std::string data(recv_str.begin(), recv_str.begin() + len);
            std::cout << client << ": " << data << '\n';
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << " UDP Server Error" << std::endl;
    }
}

