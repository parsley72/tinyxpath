/*
www.sourceforge.net/projects/tinyxpath
Copyright (c) 2002-2004 Yves Berquin (yvesb@users.sourceforge.net)

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

/**
   \file xml_util.h
   \author Yves Berquin
*/

#ifndef __XML_UTIL_H
#define __XML_UTIL_H

#include "tinyxml.h"

namespace TinyXPath
{
extern int i_xml_cardinality (const TiXmlElement* XEp_elem, bool o_by_name);
extern int i_xml_family_size (const TiXmlElement* XEp_elem);
}

#endif	 // __XML_UTIL_H
