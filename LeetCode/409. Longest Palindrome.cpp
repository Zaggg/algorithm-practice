// 409. Longest Palindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include <algorithm>
#include <functional>
#include "map"
#include "set"
#include<iostream>
#include"unordered_set"

using namespace std;

int longestPalindrome(string s);
int longestPalindrome2(string s);

int main()
{
	string a = "bbaaab";
	cout << longestPalindrome2(a) << endl;;
    return 0;
}


int longestPalindrome(string s) {
	int i=0,sum=0;
	bool _odd = false;;
	//map<char, int> char_map;
	unordered_set<char> char_set;
	int s_length=0;
	while (s[i] != '\0')
	{
		auto a = char_set.insert(s[i]);
		s_length++;
		i++;
	}

	cout << s_length << endl;
	for(auto p = char_set.cbegin();p!= char_set.cend();++p)
	{
		int _sum = count(s.begin(), s.end(), *p);

		if (_sum >= 2)
		{
			if (_sum % 2 != 0)
				_odd = true;
			sum += ((_sum / 2) * 2);
			cout << *p<<" "<<sum<<endl;
		}
		else
			_odd = true;
		cout << _odd << endl;
	}

	return _odd ?(++sum):sum;
}

int longestPalindrome2(string s) {
	int odds = 0;
	for (char c = 'A'; c <= 'z'; ++c) {
		odds += count(s.begin(), s.end(), c) & 1;//与1作与运算算出奇数
	}
	return s.size() - max(0, odds - 1);
}
