//
// log_message.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_LOG_MESSAGE_HPP
#define HIELOG_LOG_MESSAGE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// 
template <typename Log>
class log_message
	: private boost::noncopyable
{
public:

	/// The log type.
	typedef Log log_type;

	explicit log_message(log_type& message_log, const std::string& message)
		: boost::noncopyable()
	{
#if !defined(HIELOG_NO_LOG)
		// Put message.
		message_log << log_type::formatter_type::decorate_message(message);
#endif // !defined(HIELOG_NO_LOG)
	}

};

} // namespace iplog

#endif // HIELOG_LOG_MESSAGE_HPP
