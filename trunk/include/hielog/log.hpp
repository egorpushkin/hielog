//
// log.hpp
// ~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_LOG_HPP
#define HIELOG_LOG_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Provides logging functionality.
/**
 * The log class template provides logging functionality.
 */
template 
<
	typename Provider = basic_provider, 
	typename Formatter = basic_formatter
>
class log 
	: private boost::noncopyable
{
public:

	/// The I/O provider type.
	typedef Provider provider_type;

	/// The I/O provider pointer type.
	typedef boost::shared_ptr< provider_type > provider_ptr_type;

	/// The formatter type.
	typedef Formatter formatter_type;

	/// The log type.
	typedef log<provider_type, formatter_type> log_type;

	/// Construct a log.
	log()
		: boost::noncopyable()
		, provider( new provider_type() )
	{
	}

	/// Construct a log.
	log(const provider_ptr_type& io_provider)
		: boost::noncopyable()
		, provider(io_provider)
	{
	}

	/// Destructor.
	~log()
	{
	}

	void increase_indent()
	{
		provider->increase_indent();
	}

	void decrease_indent()
	{
		provider->decrease_indent();
	}

	template <typename T>
	log& operator << (const T& data)
	{
		formatter_type::format(
			provider->get_buffer()->get_output_stream(), 
			provider->get_indent(), 
			data);
		return *this;
	}

private:

	/// The provider of output streams utilized by the log.
	provider_ptr_type provider;

};

} // namespace iplog

#endif // HIELOG_LOG_HPP
