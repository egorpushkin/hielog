//
// remote_record.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_REMOTE_RECORD_HPP
#define HIELOG_REMOTE_RECORD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// .
class remote_record
	: private boost::noncopyable
{
public:

	remote_record(const remote_record_data& record_data)
		: boost::noncopyable()
		, data(record_data)
		, indent(0)
		, socket(new remote_buffer::socket_type(record_data.get_service()))
	{
		// Establish connection.
		boost::asio::ip::tcp::resolver resolver(data.get_service());
		boost::asio::ip::tcp::resolver::query query(data.get_ip(), data.get_port());
		boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(query);
		boost::asio::ip::tcp::resolver::iterator end;

		// Try each endpoint until we successfully establish a connection.
		boost::system::error_code error = boost::asio::error::host_not_found;
		while ( error && endpointIterator != end )
		{
			socket->close();
			socket->connect(*endpointIterator++, error);
		}

		// Check whether connection attempt failed.
		if ( error )
		{
			// Throw an exception to notify client on failure.
			throw std::exception();
		}
	}

	remote_buffer_ptr get_buffer() const
	{
		return remote_buffer_ptr(new remote_buffer(socket));
	}

	void increase_indent()
	{
		++indent;
	}

	void decrease_indent()
	{
		--indent;
	}

	size_t get_indent() const
	{
		return indent;
	}

private:

	/// 
	const remote_record_data& data;

	/// Current indentation level.
	size_t indent;

	/// 
	remote_buffer::socket_ptr_type socket;

};

} // namespace iplog

#endif // HIELOG_REMOTE_RECORD_HPP
