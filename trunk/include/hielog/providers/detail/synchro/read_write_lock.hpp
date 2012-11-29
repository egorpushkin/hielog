//
// read_write_lock.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_READ_WRITE_LOCK_HPP
#define HIELOG_READ_WRITE_LOCK_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

class read_write_lock
	: public boost::noncopyable
{
public:

	read_write_lock()
		: boost::noncopyable()
		, resource_lock()
		, counters_lock()
		, writers_count(0)
		, readers_count(0)
	{
	}

	void lock_read()
	{
		counters_lock.lock();
		if ( ( writers_count > 0 ) || ( readers_count == 0 ) )
		{
			counters_lock.unlock();
			resource_lock.lock();
			counters_lock.lock();
		}
		++readers_count;
		counters_lock.unlock();
	}

	void unlock_read()
	{
		counters_lock.lock();
		--readers_count;
		if ( 0 == readers_count )
		{
			resource_lock.unlock();
		}
		counters_lock.unlock();
	}

	void lock_write()
	{
		counters_lock.lock();
		++writers_count;
		counters_lock.unlock();
		resource_lock.lock();
	}

	void unlock_write()
	{
		counters_lock.lock();
		--writers_count;
		counters_lock.unlock();
		resource_lock.unlock();
	}

private:

	/// Prevents access to the resource from multiple threads. 
	boost::mutex resource_lock;

	/// Prevents access to counters from multiple threads.
	boost::mutex counters_lock;

	/// Number of actual writers. This property was made signed intentionally
	/// for debug purposes. This allows to alert if negative value is met here.
	long writers_count;

	/// Number of actual readers. 
	long readers_count;

};

} // namespace iplog

#endif // HIELOG_READ_WRITE_LOCK_HPP
