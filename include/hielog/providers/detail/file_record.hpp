//
// file_record.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_FILE_RECORD_HPP
#define HIELOG_FILE_RECORD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// .
template<typename FilenameFormatterPtr>
class file_record
	: private boost::noncopyable
{
public:

	file_record(const FilenameFormatterPtr& formatter)
		: boost::noncopyable()
		, filename(formatter->filename())
		, indent(0)
	{
	}

	file_buffer_ptr get_buffer() const
	{
		return file_buffer_ptr( new file_buffer( filename ) );
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

	/// 
	std::string filename;

	/// Current indentation level.
	size_t indent;

};

} // namespace iplog

#endif // HIELOG_FILE_RECORD_HPP
