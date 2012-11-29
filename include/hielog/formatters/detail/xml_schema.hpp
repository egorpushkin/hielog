//
// xml_schema.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_XML_SCHEMA_HPP
#define HIELOG_XML_SCHEMA_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// XML schema.
class xml_schema
{
private:

	xml_schema();
	~xml_schema();

public:

	static std::string scope_tag()
	{
		return std::string("scope");
	}

	static std::string message_tag()
	{
		return std::string("message");
	}

	static std::string name_param()
	{
		return std::string("name");
	}

};

} // namespace iplog

#endif // HIELOG_XML_SCHEMA_HPP
