//
// remote_provider.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_REMOTE_PROVIDER_HPP
#define HIELOG_REMOTE_PROVIDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Provides support for remote logging.
class remote_provider
	: private boost::noncopyable
{
public:

	remote_provider(const std::string& ip_address, const std::string& port_number)
		: boost::noncopyable()
		, service()
		, record_data(ip_address, port_number, service)
		, storage(record_data)
	{
	}

	remote_buffer_ptr get_buffer() const
	{
		return storage.get_thread_record()->get_buffer();
	}

	void increase_indent()
	{
		storage.get_thread_record()->increase_indent();
	}

	void decrease_indent()
	{
		storage.get_thread_record()->decrease_indent();
	}

	size_t get_indent() const
	{
		return storage.get_thread_record()->get_indent();
	}

private:

	/// 
	boost::asio::io_service service;

	/// 
	remote_record_data record_data;

	/// 
	thread_storage< remote_record, remote_record_data > storage;

};

} // namespace iplog

#endif // HIELOG_REMOTE_PROVIDER_HPP
