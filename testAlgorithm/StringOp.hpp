#pragma once
#include <cstring>
#include <stack>
using namespace std;
namespace StringOP
{
	inline char HighHexByte(char in)
	{
		char _t = (in >> 4);
		if (_t > 9)
			return _t - 0xa + 'a';
		else 
			return _t + 0x30;
	}
	inline char LowHexByte(char in)
	{
		char _t = (in & 0xf);
		if (_t > 9)
			return _t - 0xa + 'a';
		else
			return _t + 0x30;			
	}

	void URLReplace(const char * src, char * dst, const char* sp)
	{
		char *p = dst;
		const char *q = sp;
		while (*src)
		{
			q = sp;
			while (*q)
			{
				if (*src == *q)
				{
					*p++ = '%';
					*p++ = HighHexByte(*src);
					*p++ = LowHexByte(*src);
					break;
				}
				q++;
			}
			if (!*q) *p++ = *src;
			src++;
		}
		*p = 0;
	}

	

	void URLReplaceS(const char * src, char * dst, int len, const char* sp)
	{
		if (!src || !dst || len == 0) return;
		char * p = dst;
		int n = 0;
		const char *q = sp;
		while (*src  && n < len - 1)
		{
			q = sp;
			while (*q)
			{
				if (*src == *q)
				{
					if (n < len - 4)
					{
						*p++ = '%';
						*p++ = HighHexByte(*src);
						*p++ = LowHexByte(*src);
						n+=3;
					}
					else
					{
						// not enough space
						*p = 0;
						return;
					}
					break;
				}
				q++;
			}
			if (!*q) 
			{
				*p++ = *src;
				n++;
			}
			src++;
		}
		*p = 0; // null
	}

	void URLReplaceS(char * url, int len, const char* sp)
	{
		char * temp = (char*)malloc(sizeof(char) * len);
		strcpy(temp, url);
		URLReplaceS(temp, url, len, sp);
		free(temp);
	}

	void URLReplaceFinal(char * dst, int len, const char * sp)
	{
		if (!dst || len == 0) return;
		int _index = 0;
		stack<char> _queue;
		char * p = dst;
		const char * q = sp;
		while (*p)
		{
			q = sp;
			while (*q && *q != *p) q++;
			if (*q) 
			{
				_queue.push(*p);
			}
			_index++;
			p++;
		}
		if (_queue.size() == 0) return; // nothing to do
		if (len < _index + 2 * _queue.size() + 1) return; // no enough space
		char * m = dst + _index + 2 * _queue.size();
		do 
		{
			if (!_queue.empty() && _queue.top() == *p)
			{
				_queue.pop();
				*m-- = LowHexByte(*p);
				*m-- = HighHexByte(*p);
				*m-- = '%';
			}
			else
			{
				*m-- = *p;
			}
		} while (p-- != dst);
	}

	bool HasChar(const char * psz, char ch)
	{
		if (!psz || !*psz) return false;
		const char * p = psz;
		while (*p)
		{
			if (*p==ch)
				return true;
			p++;
		}
		return false; 
	}
}