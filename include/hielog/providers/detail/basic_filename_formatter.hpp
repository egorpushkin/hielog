//
// file_provider.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_BASIC_FILENAME_FORMATTER_HPP
#define HIELOG_BASIC_FILENAME_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Formats file name for given thread of the process.
class basic_filename_formatter
{
public:

	/**
	 * This tool should not be const because it may potentially modify state
	 * of the object (for example, to generate unique filenames).
	 */ 
	std::string filename()
	{
		return string_formatter() 
			<< std::string("./")
			<< boost::interprocess::detail::get_current_process_id()
			<< std::string("_")
			<< boost::this_thread::get_id()
			<< std::string(".hielog");
	}

};

} // namespace iplog

#endif // HIELOG_BASIC_FILENAME_FORMATTER_HPP
