//
// xml_formatter.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2009 Egor Pushkin (egor.pushkin at scientific-soft dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HIELOG_XML_FORMATTER_HPP
#define HIELOG_XML_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace iplog {

/// XML formatter.
template<typename XmlSchema = xml_schema>
class xml_formatter
{
private:

	xml_formatter();
	~xml_formatter();

public:

	typedef XmlSchema xml_schema_type;

	template <typename OutputStream, typename T>
	static void format(OutputStream& stream, size_t indent, const T& data)
	{
		// Push indent.
		std::fill_n( std::ostream_iterator< char >(stream), indent, '\t' );
		// Push data.
		stream << data;
		// Push delimiter (end of line).
		stream << std::endl;
	}

	static std::string decorate_message(const std::string& message)
	{
		return string_formatter()
			<< std::string("<")
			<< xml_schema_type::message_tag()
			<< std::string(" ")
			<< xml_schema_type::name_param()
			<< std::string("=\"")
			<< message
			<< std::string("\"/>");
	}

	static std::string decorate_scope_open(const std::string& message)
	{
		return string_formatter()
			<< std::string("<")
			<< xml_schema_type::scope_tag()
			<< std::string(" ")
			<< xml_schema_type::name_param()
			<< std::string("=\"")
			<< message
			<< std::string("\">");
	}

	static std::string decorate_scope_close(const std::string& /* message */)
	{
		return string_formatter()
			<< std::string("</")
			<< xml_schema_type::scope_tag()
			<< std::string(">");
	}

};

} // namespace iplog

#endif // HIELOG_XML_FORMATTER_HPP
