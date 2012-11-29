//
// string_formatter.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_STRING_FORMATTER_HPP
#define HIELOG_STRING_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// String formatter.
class string_formatter
{
public:

	/// Default constructor.
	string_formatter()
		: buffer()
	{
	}

	/// Default constructor.
	string_formatter(const std::string& data)
		: buffer()
	{
		buffer << data;
	}

	/// Utility to put data into internal buffer.
	template <typename T>
	string_formatter& operator << (const T& data)
	{
		buffer << data;
		return *this;
	}

	/// Provides automatic conversion to std::string.
	operator std::string()
	{
		return buffer.str();
	}

private:

	/// Contains buffer during formatting.
	std::stringstream buffer;

};

} // namespace iplog

#endif // STRING_FORMATTER_HPP
