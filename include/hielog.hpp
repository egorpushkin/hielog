//
// iplog.hpp
// ~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_HPP
#define HIELOG_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

/// Standard library dependencies
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>

/// Boost dependencies
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
// Required for file naming purposes.
#include <boost/interprocess/detail/os_thread_functions.hpp>

/// HieLog source code
#include <include/hielog/config.hpp>
#include <include/hielog/log.hpp>
#include <include/hielog/log_scope.hpp>
#include <include/hielog/log_message.hpp>
#include <include/hielog/formatters/string_formatter.hpp>
#include <include/hielog/formatters/basic_formatter.hpp>
#include <include/hielog/formatters/detail/xml_schema.hpp>
#include <include/hielog/formatters/xml_formatter.hpp>
#include <include/hielog/providers/basic_buffer.hpp>
#include <include/hielog/providers/basic_provider.hpp>
#include <include/hielog/providers/detail/synchro/read_write_lock.hpp>
#include <include/hielog/providers/detail/remote_record_data.hpp>
#include <include/hielog/providers/detail/remote_buffer.hpp>
#include <include/hielog/providers/detail/remote_record.hpp>
#include <include/hielog/providers/detail/thread_storage.hpp>
#include <include/hielog/providers/remote_provider.hpp>
#include <include/hielog/providers/detail/invalid_filename_exception.hpp>
#include <include/hielog/providers/detail/basic_filename_formatter.hpp>
#include <include/hielog/providers/detail/file_buffer.hpp>
#include <include/hielog/providers/detail/single_file.hpp>
#include <include/hielog/providers/detail/file_record.hpp>
#include <include/hielog/providers/detail/multiple_files.hpp>
#include <include/hielog/providers/file_provider.hpp>

#endif // HIELOG_HPP
