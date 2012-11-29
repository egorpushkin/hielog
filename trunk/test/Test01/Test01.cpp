// Test01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// typedef iplog::log< iplog::basic_provider > log_type;
// typedef iplog::log< iplog::file_provider< iplog::multiple_files >, iplog::basic_formatter > log_type;
// typedef iplog::log< iplog::file_provider< iplog::single_file >, iplog::basic_formatter > log_type;
typedef iplog::log< iplog::file_provider< iplog::single_file >, iplog::xml_formatter<> > log_type;
log_type log_instance;	

struct callable1
{
	void operator()()
	{
		for (int i = 0 ; i < 10 ; ++i)
			iplog::log_message< log_type > msg(log_instance, "Simple message from callable1");
	}
};

struct callable2
{
	void operator()()
	{
		for (int i = 0 ; i < 10 ; ++i)
			iplog::log_message< log_type > msg(log_instance, "Simple message from callable2");
	}
};

struct callable3
{
	void operator()()
	{
		for (int i = 0 ; i < 10 ; ++i)
			iplog::log_message< log_type > msg(log_instance, "Simple message from callable3");
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
/*	callable1 c1;
	callable2 c2;
	callable3 c3;
	boost::thread thread1(c1);
	boost::thread thread2(c2);
	boost::thread thread3(c3); */

 	{
		iplog::log_scope< log_type > scope(log_instance, iplog::string_formatter() << "scope" << 1);		
		
		iplog::log_message< log_type > msg(log_instance, "Simple message");

		{
			iplog::log_scope< log_type > scope(log_instance, iplog::string_formatter() << "scope" << 2);		
			{
				iplog::log_scope< log_type > scope(log_instance, iplog::string_formatter() << "scope" << 3);					
			}

			iplog::log_message< log_type > msg(log_instance, iplog::string_formatter() << "Formatted message: " << 3.7f);
		}
	}
	
/*	thread1.join();
	thread2.join();
	thread3.join(); */

	return 0;
}

