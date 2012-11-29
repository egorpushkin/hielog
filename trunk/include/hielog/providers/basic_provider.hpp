//
// basic_provider.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_BASIC_PROVIDER_HPP
#define HIELOG_BASIC_PROVIDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Simplest provider.
class basic_provider
	: private boost::noncopyable
{
public:

	basic_provider()
		: boost::noncopyable()
		, indent(0)
		, buffer( new basic_buffer() )
	{
	}

	basic_buffer_ptr get_buffer() const
	{
		return buffer;
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

	/// Current indentation level.
	size_t indent;

	/// 
	basic_buffer_ptr buffer;

};

} // namespace iplog

#endif // HIELOG_BASIC_PROVIDER_HPP
