//
// file_buffer.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_FILE_BUFFER_HPP
#define HIELOG_FILE_BUFFER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Remote buffer.
class file_buffer
	: private boost::noncopyable
{
public:

	explicit file_buffer(const std::string& filename)
		: boost::noncopyable()
		, file(filename.c_str(), std::ios_base::app)
	{
		if ( file.bad() )
			throw invalid_filename_exception(filename);
	}

	virtual ~file_buffer()
	{
		// Close file.
		file.close();
	}

	std::ostream& get_output_stream()
	{
		return file;
	}

private:

	///
	std::ofstream file;

};

typedef boost::shared_ptr< file_buffer > file_buffer_ptr;

} // namespace iplog

#endif // HIELOG_FILE_BUFFER_HPP
