//
// remote_record_data.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_REMOTE_RECORD_DATA_HPP
#define HIELOG_REMOTE_RECORD_DATA_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Contains data required to initialize new record.
class remote_record_data
	: private boost::noncopyable
{
public:

	remote_record_data(const std::string& ip_address, const std::string& port_number, boost::asio::io_service& io_service)
		: boost::noncopyable()
		, ip(ip_address)
		, port(port_number)
		, service(io_service)
	{
	}

	std::string get_ip() const
	{
		return ip;
	}
	
	std::string get_port() const
	{
		return port;
	}

	boost::asio::io_service& get_service() const
	{
		return service;
	}

private:

	/// 
	const std::string ip;
	
	/// 
	const std::string port;

	/// 
	boost::asio::io_service& service;

};

} // namespace iplog

#endif // HIELOG_REMOTE_RECORD_DATA_HPP
