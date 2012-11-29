//
// syntax.cpp
// ~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <include/hielog.hpp>

class syntax_test
{
public:

	void use_case_1()
	{
		typedef iplog::log< iplog::basic_provider, iplog::basic_formatter > log;
		log log_instance;		
		iplog::log_scope< log::log_type > scope(log_instance, "syntax_test::use_case_1()");		
		log_instance.increase_indent();
	}

	void use_case_2()
	{
		typedef iplog::log< iplog::remote_provider, iplog::basic_formatter > log;
		log::provider_ptr_type provider( new log::provider_type("192.168.12.24", "8555"));		
		log log_instance( provider );		
		iplog::log_scope< log > scope(log_instance, "syntax_test::use_case_1()");		
		log_instance.increase_indent();
	}

	void use_case_3()
	{
		typedef iplog::log< iplog::file_provider<>, iplog::basic_formatter > log;
		log log_instance;		
		iplog::log_scope< log > scope(log_instance, "syntax_test::use_case_1()");		
		log_instance.increase_indent();
	}

	void use_case_4()
	{
		typedef iplog::log< iplog::file_provider< iplog::multiple_files >, iplog::basic_formatter > log;
		log log_instance;		
		iplog::log_scope< log > scope(log_instance, "syntax_test::use_case_1()");		
		log_instance.increase_indent();
	}
	
};
