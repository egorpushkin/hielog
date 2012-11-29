//
// basic_formatter.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_BASIC_FORMATTER_HPP
#define HIELOG_BASIC_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Simplest formatter.
class basic_formatter
{
private:

	basic_formatter();
	~basic_formatter();

public:

	template <typename OutputStream, typename T>
	static void format(OutputStream& stream, size_t indent, const T& data)
	{
		// Push indent.
		std::fill_n( std::ostream_iterator< char >(stream), indent, ' ' );
		// Push data.
		stream << data;
		// Push delimiter (end of line).
		stream << std::endl;
	}

	static std::string decorate_message(const std::string& message)
	{
		return message;
	}

	static std::string decorate_scope_open(const std::string& message)
	{
		return message;
	}

	static std::string decorate_scope_close(const std::string& message)
	{
		return std::string("\\") + message;
	}

};

} // namespace iplog

#endif // HIELOG_BASIC_FORMATTER_HPP
