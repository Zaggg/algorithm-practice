#include "stdafx.h"
#include <assert.h>
#include <sstream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <iostream>
#include<Windows.h>
#include <thread>
#include<mutex>
#include <process.h>  

#define M_PI 3.14159265358979323846  /* pi */
//Help the bookseller !
std::string Printer::dotest(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
{
	if (lstOfArt.empty() || categories.empty()) return "";
	std::string ret;
	std::unordered_map<std::string, int> book_map;
	for (auto itor = categories.cbegin(); itor != categories.cend(); itor++)
	{
		for (auto c_itor : lstOfArt)
		{
			if (c_itor[0]==(*itor)[0])
			{
				int i = 0;
				while (c_itor[i] != ' ')
				{
					i++;
				}
				std::string t = c_itor.substr(i+1, t.length() - i);
				book_map[*itor] += std::stoi(t);
			}
		}
	}
	seems it works bad on this test wheel
	/*for (auto i = book_map.begin(); i != book_map.end(); i++)
	{
		ret += "(" + (*i).first + " : " + std::to_string((*i).second) + ") - ";
	}*/
	for (auto itor = categories.cbegin(); itor != categories.cend(); itor++)
	{
		ret += "(" + *itor + " : " + std::to_string(book_map[*itor]) + ") - ";
	}
	return ret.substr(0, ret.length() - 3);
}


//Validate Credit Card Number
static bool validate(long long int n) {
	long long m_digits = n,counter = 0,sum=0;
	while (m_digits>0)
	{
		int t = m_digits % 10;
		m_digits /= 10;
		if (counter % 2 == 1)
			t *= 2;
		if (t > 9)
			t -= 9;
		sum += t;
		counter++;
	}
	if (sum % 10 == 0)
		return true;
	else
		return false;
}


//PI approximation
std::string PiApprox::iterPi(double epsilon)
{
	double pi=0;
	long counter = 0;
	long deno = 1;
	std::ostringstream stream;
	while (M_PI - 4*pi > epsilon || M_PI - 4*pi < -1 * epsilon)
	{
		pi += (counter % 2 == 1 ? -1 : 1) * 1.0 / deno;
		deno += 2;
		counter++;
	}
	stream << "[" << std::to_string(counter) << ", " << std::setprecision(11) << 4 * pi << "]";
	std::string ret = "[" + std::to_string(counter) + "," + stream.str() + "]";
	return stream.str();
}

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
	std::vector<std::string> ret_vec;
	for (auto itor1 : array2)
	{
		for (auto itor2 : array1)
		{
			if (itor1.find(itor2) != std::string::npos)
			{
				ret_vec.push_back(itor2);
			}
		}
	}
	std::sort(ret_vec.begin(), ret_vec.end());
	return ret_vec;
}


//Find the smallest
std::vector<long long> ToSmallest::smallest(long long n)
{
	if(n<0)
		n = abs(n);
	std::vector<long long> ret;
	std::string s = std::to_string(n);
	NumList lowest_num = getNum(s);
	ret.push_back(lowest_num.num);
	ret.push_back(lowest_num.move_index);
	ret.push_back(lowest_num.insert_index);
	return ret;
}
NumList ToSmallest::getNum(std::string &s)
{
	std::vector<NumList> query_list;
	for (int i = 0; i < s.size(); i++)
	{
		getNumImpl(s, i, query_list);
	}
	return getLowestNum(query_list);
}
void ToSmallest::getNumImpl(std::string &s,int index, std::vector<NumList> &query_list)
{
	for (int si = 0; si < s.size(); si++)
	{
		std::string t("");
		NumList num;
		for (int i = 0; i<s.size(); i++)
		{
			
			if (i == si)
			{
				if (si < index)
				{
					t += s[index];
					t += s[i];
				}
				else if (si == index)
				{
					t += s[i];
				}
				else
				{
					t += s[i];
					t += s[index];
				}
				continue;
			}
			if (i == index)
				continue;
			t += s[i];
		}
		num.num = std::stoll(t);
		num.move_index = index;
		num.insert_index = si;
		query_list.push_back(num);
	}
}
NumList ToSmallest::getLowestNum(std::vector<NumList> &query_list)
{
	std::sort(query_list.begin(), query_list.end(), [](const NumList &i1, const NumList &i2) {
		if (i1.num > i2.num)
			return false;
		else if (i1.num == i2.num)
		{
			if (i1.move_index > i2.move_index)
				return false;
			else if (i1.move_index == i2.move_index)
			{
				return i1.insert_index < i2.insert_index;
			}
			else
				return true;
		}
		else
			return true;
	});
	return *query_list.begin();
}
//which is more good
std::vector<long long> ToSmallest::smallest(long long n)
{
	std::string str = std::to_string(n);
	std::vector<std::vector<long long>> vec = { { n, 0, 0 } };
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length(); j++)
		{
			std::string tmpStr = str;
			tmpStr.erase(i, 1);
			tmpStr.insert(j, 1, str[i]);
			vec.push_back({ std::stoll(tmpStr), i, j });
		}
	}
	return *(std::min_element(vec.begin(), vec.end()));
}


double phi = (1 + sqrt(5)) / 2;
unsigned long long fib_first=0, fib_second = 0;
std::vector<ull> ProdFib::productFib(ull prod)
{
	double num;
	auto n = log(num*sqrt(5)) / log(phi);
	std::vector<ull> ret;
	fib_first = 0;
	fib_second = 0;
	unsigned long long num1=0,num2=0;
	bool flag=false;
	while (true)
	{
		if (num1*num2 == prod)
		{
			flag = true;
			break;
		}
		if (num1*num2 > prod)
			break;
		num1 = num2;
		num2 = getFibMum();
	}
	ret.push_back(num1);
	ret.push_back(num2);
	ret.push_back(flag==true?1:0);
	return ret;
}

unsigned long long ProdFib::getFibMum()
{
	if (fib_second == 0)
	{
		return fib_second++;
	}
	auto temp = fib_first + fib_second;
	fib_first = fib_second;
	fib_second = temp;
	return temp;
}