//
// thread_storage.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_THREAD_STORAGE_HPP
#define HIELOG_THREAD_STORAGE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// Maintains container of records of certain type.
template <typename ThreadRecord, typename RecordData>
class thread_storage
	: private boost::noncopyable
{
public:

	typedef ThreadRecord record_type;

	typedef boost::shared_ptr< record_type > record_ptr_type;

	typedef RecordData record_data_type;

	thread_storage(const record_data_type& record_data)
		: boost::noncopyable()
		, lock()
		, records()
		, data(record_data)
	{
	}

	///
	/**
	 * This routine utilizes read/write locking technique to provide safe
	 * access to pool of thread records and with it to prevent additional 
	 * undesirable application synchronization by this tool. Taking into account
	 * the fact, that all threads of a process refer to this tool to acquire
	 * corresponding thread records, it is highly unrecommended to use simple 
	 * mutex for synchronization. This decreases application performance and
	 * may potentially hide application synchronization vulnerabilities. 
	 */
	record_ptr_type get_thread_record() const
	{
		// Lock thread pool for reading and test whether thread record for
		// current thread has already been created.
		// Note: This does not prevent other threads to read the pool. This
		// prevents only writing attempts (lock_write blocks execution until
		// at least one reader or writer exists). 
		lock.lock_read();
		boost::thread::id self_id = boost::this_thread::get_id();
		typename records_type::iterator record_pos = records.find(self_id);
		if ( records.end() != record_pos )
		{
			// If a record is found, acquire it from pool and unlock it
			// for further referencing. 
			record_ptr_type record = (*record_pos).second;
			lock.unlock_read();
			return record;
		}
		// If a record is not found, read locking is not required any more. 
		lock.unlock_read();
		
		// Thread pool should be locked for writing to add new record into it. 
		// This prevents from both reading and writing the pool.
		lock.lock_write();
		// Create new record and register it. 
		record_ptr_type record(new record_type(data));
		records[self_id] = record;
		// Remove locking. 
		lock.unlock_write();
		return record;

		// Note: There is no problem with separating checking and adding code. 
		// It is not necessary to wrap it into the same critical section. 
		// The reason is that nobody (except caller) can register thread record, 
		// which corresponds to the current thread. That is why this routine can
		// be sure, that it is still necessary to add new record even, if it's
		// execution was interrupted somewhere inside by other thread, even if 
		// the last one has modified the pool. 
	}		

private:

	/// 
	mutable read_write_lock lock;

	/// 
	typedef std::map< boost::thread::id, record_ptr_type > records_type;

	/// 
	mutable records_type records;

	/// 
	const record_data_type& data;

};

} // namespace iplog

#endif // HIELOG_THREAD_STORAGE_HPP
