//
// remote_buffer.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_REMOTE_BUFFER_HPP
#define HIELOG_REMOTE_BUFFER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Remote buffer.
class remote_buffer
	: private boost::noncopyable
{
public:

	///
	typedef boost::asio::ip::tcp::socket socket_type;

	///
	typedef boost::shared_ptr< socket_type > socket_ptr_type;

	remote_buffer(const socket_ptr_type& io_socket)
		: boost::noncopyable()
		, socket(io_socket)
		, output_buffer()
		, output_stream(&output_buffer)
	{
	}

	~remote_buffer()
	{
		boost::asio::write(*socket, output_buffer, boost::asio::transfer_all());
	}

	std::ostream& get_output_stream()
	{
		return output_stream;
	}

private:

	///
	socket_ptr_type socket;

	///
	boost::asio::streambuf output_buffer;

	///
	std::ostream output_stream;

};

typedef boost::shared_ptr< remote_buffer > remote_buffer_ptr;

} // namespace iplog

#endif // HIELOG_REMOTE_BUFFER_HPP
