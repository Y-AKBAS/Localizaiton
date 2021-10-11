#ifndef _COLLATE_EXAMPLE_H
#define _COLLATE_EXAMPLE_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <boost/locale.hpp>
#include "Timer.h"

void collate_example_boost_ms();
void collate_example_boost_vec();
void collate_example_boost_list();
void display_ms(const std::multiset<std::wstring, boost::locale::comparator<wchar_t>> &ms);
void display_vec(const std::vector<std::wstring> &vec);
void display_list(const std::list<std::wstring> &l);

#endif