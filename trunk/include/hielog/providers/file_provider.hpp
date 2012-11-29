//
// file_provider.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_FILE_PROVIDER_HPP
#define HIELOG_FILE_PROVIDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Provides support for file logging.
template <template <class> class StorageMethod = single_file, typename FileNameFormatter = basic_filename_formatter >
class file_provider
	: private boost::noncopyable
	, private StorageMethod<FileNameFormatter>
{
public:

	typedef StorageMethod<FileNameFormatter> storage_method;

	typedef typename storage_method::filename_formatter_ptr_type filename_formatter_ptr_type;

	file_provider()
		: boost::noncopyable()
		, storage_method()
	{
	}

	explicit file_provider(const filename_formatter_ptr_type& formatter)
		: boost::noncopyable()
		, storage_method(formatter)
	{
	}

	file_buffer_ptr get_buffer() const
	{
		return storage_method::get_buffer();
	}

	void increase_indent()
	{
		storage_method::increase_indent();
	}

	void decrease_indent()
	{
		storage_method::decrease_indent();
	}

	size_t get_indent() const
	{
		return storage_method::get_indent();
	}

};

} // namespace iplog

#endif // HIELOG_FILE_PROVIDER_HPP
