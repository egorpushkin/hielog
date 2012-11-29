//
// invalid_filename_exception.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_INVALID_FILENAME_EXCEPTION_HPP
#define HIELOG_INVALID_FILENAME_EXCEPTION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

class invalid_filename_exception
	: public std::exception 
{
public:

	explicit invalid_filename_exception(const std::string& io_filename)
		: std::exception()
		, filename(io_filename)
	{
	}

	std::string get_filename() const
	{
		return filename;
	}

private:

	std::string filename;

};

} // namespace iplog

#endif // HIELOG_INVALID_FILENAME_EXCEPTION_HPP
