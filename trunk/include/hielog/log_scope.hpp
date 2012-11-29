//
// log_scope.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_LOG_SCOPE_HPP
#define HIELOG_LOG_SCOPE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Wraps scope into a pair of log statements.
/**
 * The log_routine class wraps the scope of it's declaration into the pair of
 * log statements. This tool automatically increases indentation level for all
 * inner log messages.
 */
template <typename Log>
class log_scope
	: private boost::noncopyable
{
public:

	/// The log type.
	typedef Log log_type;

	/// Construct a log_scope.
	/**
  	 * This constructor creates scope statement.
	 *
	 * @param scope_log The log object that the log_scope will use to display
	 * its content.
	 *
	 * @param scope_message The scope's message. It usually includes scope name.
	 */
	explicit log_scope(log_type& scope_log, const std::string& scope_message)
		: boost::noncopyable()
		, log(scope_log)
		, message(scope_message)
	{
#if !defined(HIELOG_NO_LOG)
		// Put opening message.
		log << log_type::formatter_type::decorate_scope_open(message);
		// Increase indent.
		log.increase_indent();
#endif // !defined(HIELOG_NO_LOG)
	}

	/// Destructor.
	/**
  	 * Puts closing statement and decreases indentation level.
	 */
	~log_scope()
	{
#if !defined(HIELOG_NO_LOG)
		// Decrease indent.
		log.decrease_indent();
		// Put closing message.
		log << log_type::formatter_type::decorate_scope_close(message);
#endif // !defined(HIELOG_NO_LOG)		
	}

private:

	/// The log associated with the scope.
	log_type& log;

	/// The message associated with the scope.
	std::string message;

};

} // namespace iplog

#endif // HIELOG_LOG_SCOPE_HPP
