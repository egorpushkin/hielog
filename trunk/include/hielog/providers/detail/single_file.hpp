//
// single_file.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_SINGLE_FILE_HPP
#define HIELOG_SINGLE_FILE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

template<typename FileNameFormatter = basic_filename_formatter>
class single_file
{
public:

	typedef FileNameFormatter filename_formatter_type;

	typedef boost::shared_ptr< filename_formatter_type > filename_formatter_ptr_type;

	single_file()
		: indent(0)
		, filename( filename_formatter_ptr_type( new filename_formatter_type() )->filename() )
	{
	}

	explicit single_file(const filename_formatter_ptr_type& formatter)
		: indent(0)
		, filename( formatter->filename() )
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

	/// Current indentation level.
	size_t indent;

	///
	std::string filename;

};

} // namespace iplog

#endif // HIELOG_SINGLE_FILE_HPP
