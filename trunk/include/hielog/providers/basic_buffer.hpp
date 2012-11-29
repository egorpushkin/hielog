//
// basic_buffer.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_BASIC_BUFFER_HPP
#define HIELOG_BASIC_BUFFER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Simplest buffer.
class basic_buffer
	: private boost::noncopyable
{
public:

	std::ostream& get_output_stream()
	{
		return std::cout;
	}

};

typedef boost::shared_ptr< basic_buffer > basic_buffer_ptr;

} // namespace iplog

#endif // HIELOG_BASIC_BUFFER_HPP
