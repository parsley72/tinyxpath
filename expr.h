/*
www.sourceforge.net/projects/tinyxpath
Copyright (c) 2002 Yves Berquin (yvesb@users.sourceforge.net)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef __EXPR_H
#define __EXPR_H

#include "tinyxml.h"

typedef enum {e_bool, e_string, e_int, e_invalid} e_expression_type;

class expression_result
{
protected :	
	TIXML_STRING S_content;
	bool o_content;
	int i_content;

public :
	e_expression_type e_type;
	expression_result ()
	{
		e_type = e_invalid;
	}
	void v_set_bool (bool o_in)
	{
		e_type = e_bool;
		o_content = o_in;
	}
	void v_set_int (int i_in)
	{
		e_type = e_int;
		i_content = i_in;
	}
	void v_set_string (const char * cp_in)
	{
		e_type = e_string;
		S_content = cp_in;
	}
	void v_set_string (TIXML_STRING S_in)
	{
		e_type = e_string;
		S_content = S_in;
	}
	int i_get_int ()
	{
		assert (e_type == e_int);
		return i_content;
	}	
	TIXML_STRING S_get_string ()
	{
		assert (e_type == e_string);
		return S_content;
	}	
	const char * cp_get_string ()
	{
		assert (e_type == e_string);
		return S_content . c_str ();
	}	
	bool o_get_bool ()
	{
		assert (e_type == e_bool);
		return o_content;
	}	
} ;

#endif


