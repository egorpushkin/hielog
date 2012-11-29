//
// multiple_files.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_MULTIPLE_FILES_HPP
#define HIELOG_MULTIPLE_FILES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

template<typename FileNameFormatter = basic_filename_formatter>
class multiple_files
{
public:

	typedef FileNameFormatter filename_formatter_type;

	typedef boost::shared_ptr< filename_formatter_type > filename_formatter_ptr_type;

	multiple_files()
		: indent(0)
		, filename_formatter(filename_formatter_ptr_type(new filename_formatter_type()))
		, storage(filename_formatter)
	{
	}

	explicit multiple_files(const filename_formatter_ptr_type& formatter)
		: indent(0)
		, filename_formatter(formatter)
		, storage(filename_formatter)
	{
	}

	file_buffer_ptr get_buffer() const
	{
		return storage.get_thread_record()->get_buffer();
	}

	void increase_indent()
	{
		storage.get_thread_record()->increase_indent();
	}

	void decrease_indent()
	{
		storage.get_thread_record()->decrease_indent();
	}

	size_t get_indent() const
	{
		return storage.get_thread_record()->get_indent();
	}

private:

	/// Current indentation level.
	size_t indent;

	///
	filename_formatter_ptr_type filename_formatter;

	/// 
	thread_storage< file_record<filename_formatter_ptr_type>, filename_formatter_ptr_type > storage;

};

} // namespace iplog

#endif // HIELOG_MULTIPLE_FILES_HPP
