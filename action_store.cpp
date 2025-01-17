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
   \file action_store.cpp
   \author Yves Berquin
*/

#include "action_store.h"

namespace TinyXPath
{

/// Allocation unit
const int i_alloc_size = 100;

/// constructor
action_store::action_store ()
{
  _i_size = 0;
  _i_position = 0;
  _i_alloc = 0;
  _aipp_list = nullptr;
}

/// destructor
action_store::~action_store ()
{
  int i_item;

  if (_i_size)
  {
    for (i_item = 0; i_item < _i_size; i_item++)
      delete _aipp_list [i_item];
    delete [] _aipp_list;
  }
}

/// add an element on the placeholder, given its details
void action_store::v_add (int i_1, int i_2, int i_3, const char *cp_string)
{
  int i_new_size;
  action_item **aipp_new_list;

  if (_i_size == _i_alloc)
  {
    i_new_size = _i_size + i_alloc_size;
    aipp_new_list = new action_item *[i_new_size];
    memset (aipp_new_list, 0, i_new_size * sizeof (action_item *));
    if (_i_size)
    {
      memcpy (aipp_new_list, _aipp_list, _i_size * sizeof (action_item *));
      delete [] _aipp_list;
    }
    _aipp_list = aipp_new_list;
    _i_alloc = i_new_size;
  }
  _aipp_list [_i_size++] = new action_item (i_1, i_2, i_3, cp_string);
}

/// Get one element from the placeholder
void action_store::v_get (int i_entry, int &i_1, int &i_2, int &i_3, TIXML_STRING &S_out)
{
  assert (i_entry >= 0 && i_entry < _i_size);
  assert (_aipp_list [i_entry]);
  _aipp_list [i_entry]->v_get (i_1, i_2, i_3, S_out);
}

}
