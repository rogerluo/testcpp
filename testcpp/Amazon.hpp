#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
namespace Amazon
{
	using namespace std;

	inline bool isSpace(char x){
		return x == ' ' || x == '\r' || x == '\n' || x == '\r' || x == '\b' || x == '\t';
	}

	char * rightTrim(char *str){
		int len = strlen(str);
		while(--len>=0){
			if(isSpace(str[len])){
				str[len] = '\0';
			}else{
				break;
			}
		}
		return str;
	}

	char * getInputLine(char *buffer, int length){
		if(fgets(buffer,length, stdin)==NULL){
			return NULL;
		}
		rightTrim(buffer);
		if(strlen(buffer)<=0){
			return NULL;
		}
		return buffer;
	}

	int splitAndConvert(char* strings,int *array){
		char*tokenPtr = strtok(strings,",");
		int i=0;
		while(tokenPtr!=NULL){
			array[i] = atoi(tokenPtr);
			i++;
			tokenPtr=strtok(NULL,",");
		}
		return i;
	}

	//your code is here  
	//下面才是让写代码的地方，其他的系统已经自动给出。主函数，只有一点点修改。
	static char* calculateOperationSequence(int * originalArray, int * resultArray, int length)
	{
		if (NULL == originalArray || NULL == resultArray || length <= 0)
			return NULL;
		//使用一个栈模拟入栈和出栈操作就ok了。
		string str;
		stack<int> st;
		int i = 0;
		int j = 0;
		st.push(originalArray[i]);


		char tmp[5] = "\0";
		str.append("push");
		sprintf(tmp, "%d", originalArray[i]);
		str.append(tmp);
		str.append("|");

		i++;

		while (!st.empty())
		{
			if (j < length && st.top() == resultArray[j])
			{
				str.append("pop");
				sprintf(tmp, "%d", resultArray[j]);
				str.append(tmp);
				str.append("|");
				st.pop();
				j++;

				if (i < length)
				{
					st.push(originalArray[i]);
					str.append("push");
					sprintf(tmp, "%d", originalArray[i]);
					str.append(tmp);
					str.append("|");
					i++;
				}
			}
			else
			{
				if (i < length)
				{
					st.push(originalArray[i]);
					str.append("push");
					sprintf(tmp, "%d", originalArray[i]);
					str.append(tmp);
					str.append("|");
					i++;
				}
				else
					break;
			}
		}


		if (!st.empty())
			return NULL;

		char *p = (char *)malloc(1 + str.length());
		if (NULL != p)
		{
			strcpy(p, str.c_str());
			p[str.length() - 1] = '\0';
			return p;
		}

		return NULL;
	}
	// myself
	static char* calculateOperationSequence2(int * in, int * out, int length)
	{
		int i = 0, j = 0;
		if (in[i] == 0) return NULL;

		stringstream ss;
		stack<int> s;

		s.push(in[i]);
		ss<<"push"<<in[i]<<"|";
		i++;

		while (!s.empty())
		{
			if (j < length && out[j] == s.top())
			{
				s.pop();
				ss<<"pop"<<out[j]<<"|";
				j++;
				if (s.empty() && in[i] != 0)
				{
					s.push(in[i]);
					ss<<"push"<<in[i]<<"|";
					i++;
				}
			}
			else
			{
				if (in[i] != 0)
				{
					s.push(in[i]);
					ss<<"push"<<in[i]<<"|";
					i++;
				}
				else
				{
					break;
				}
			}
		}
		if (j < length) 
			return NULL;
		string tmp(ss.str());
		char * final = new char[tmp.size()];
		strncpy(final, tmp.data(), tmp.size() - 1);
		final[tmp.size() - 1] = 0;
		return final;
	}

	static char* RunUT(char * in, char* out)
	{
		int originalArray[30] = {0};
		int resultArray[30] = {0};
		int originalArrayLength = splitAndConvert(in,originalArray);
		int resultArrayLength = splitAndConvert(out,resultArray);
		return calculateOperationSequence(originalArray, resultArray, resultArrayLength);
	}

	static char* RunUT2(char * in, char* out)
	{
		int originalArray[30] = {0};
		int resultArray[30] = {0};
		int originalArrayLength = splitAndConvert(in,originalArray);
		int resultArrayLength = splitAndConvert(out,resultArray);
		return calculateOperationSequence2(originalArray, resultArray, resultArrayLength);
	}

	static int Run(){
		char line[1000] = {0} ;
		while(getInputLine(line,1000)){
			int originalArray[30] = {0};
			int originalArrayLength = splitAndConvert(line,originalArray);
			if(originalArrayLength==0){
				break;
			}

			getInputLine(line, 1000);
			int resultArray[30] = {0};
			int resultArrayLength = splitAndConvert(line,resultArray);
			if(resultArrayLength==0){
				break;
			}
			char *operationSequence = calculateOperationSequence(originalArray, resultArray, resultArrayLength);

			if (NULL != operationSequence)
			{   // 原来系统提供的代码。这里没有NULL判断
				cout<< operationSequence <<endl;
				free(operationSequence); // 自己加的
			}
			else
				cout<< "None" <<endl; // 自己加的
		}
		return 0; 
	} 

	static void split(char* in, set<string>& out, char delm = ' ')
	{
		char * p = in, *q = NULL;
		char ch = 0;
		while (*p)
		{
			if (*p == delm)
			{
				if (q)
				{
					*p = 0;
					out.insert(string(q));
					q = NULL;
				}
			}
			else
			{
				if (q == NULL)
					q = p;
			}
			p++;
		}
		if (q)
		{
			out.insert(string(q));
		}
	}

	static int differ(string string1, string string2) {
		int same = 0, word1 = 0, word2 = 0;
		set<string> v1, v2;
		split(const_cast<char*>(string1.data()), v1);
		split(const_cast<char*>(string2.data()), v2);
		typedef set<string>::iterator myit;
		myit fst1 = v1.begin(), lst1 = v1.end();
		myit fst2 = v2.begin(), lst2 = v2.end();
		for (; fst1 != lst1 && fst2 != lst2; )
		{ 
			int ret = fst1->compare(*fst2);
			if (0 == ret)
			{
				same++;
				fst1++;
				fst2++;
			}
			else if (ret < 0)
			{
				fst1++;
			}
			else
			{
				fst2++;
			}
		}
		return max(v1.size(), v2.size()) - same;
	}

	static int MMchess(vector < int > Nscores, vector < int > Mnumbers) {
		// Nscores : the scores on the the board (the i-th integer corresponds to the score on the i-th grid) 
		// Mnumbers : the numbers on the M cards
		// return value : the most score that player can get
		typedef vector<int>::iterator myit;
		int max = 0;
		sort(Mnumbers.begin(), Mnumbers.end());
		do {
			myit fst = Mnumbers.begin(), lst = Mnumbers.end();
			int sum = Nscores[0], ith = 0;
			int nlen = Nscores.size();
			for (; fst != lst;fst++)
			{
				ith+=*fst;
				sum+=Nscores[ith];
			}
			if (max < sum) max = sum;
		} while ( std::next_permutation(Mnumbers.begin(), Mnumbers.end()));
		return max;
	}

#define N 5
#define M 3
	void ShowViceDialog(int v[][N])
	{
		int m = N, n = N;
		for(int d=0;d<m+n-1;d++)           //表示第d条次对角线
		{
			for(int i=0;i<=d;i++)          //行标
			{
				int j = d - i;              //列标
				if(i<m&&j<n)            //用于下三角，去除多余的
					cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void ShowMajorDialog(int v[][N])
	{
		int m = N, n = N;
		for(int d=-m+1;d<n;d++)           //因为这里只有n条主对角线，即列数
		{
			for(int i=0;i<n-d;i++)    //因为i = j - d,而j< n
			{
				int j = i + d;
				cout<<v[i][j]<<" ";      
			}
			cout<<endl;
		}
	}

	int GetMaxLine(int v[][N], vector<int>& maxs)
	{
		int ret[M] = {0};
		int max = 0, cur = 0, sum = 0;
		while (cur < M)
		{
			max = 0;
			for (int i = 0; i < N; i++)
			{
				sum = 0;
				for (int j = 0; j< N; j++)
				{
					if (cur == v[i][j]) sum++;
					else
					{
						if (sum > max) max = sum;
						if (sum >= N / 2) break;
						sum = 0;
					}
				}
				if (sum > max) max = sum;
			}
			if (max == N) 
			{
				ret[cur] = max;
				cur++;
				continue;
			}
			for (int j = 0; j < N; j++)
			{
				sum = 0;
				for (int i = 0; i < N; i++)
				{
					if (cur == v[i][j]) sum++;
					else
					{
						if (sum > max) max = sum;
						if (sum >= N / 2) break;
						sum = 0;
					}
				}
				if (sum > max) max = sum;
			}
			if (max == N) 
			{
				ret[cur] = max;
				cur++;
				continue;
			}
			for (int j = 0; j < N; j++)
			{
				sum = 0;
				for (int m = 0, n = j; m < N && n < N; m++, n++)
				{
					if (cur == v[m][n]) sum++;
					else
					{
						if (sum > max) max = sum;
						if (sum >= N / 2) break;
						sum = 0;
					}
				}
				if (sum > max) max = sum;
				if (sum >= N - j) break;
			}
			if (max == N) 
			{
				ret[cur] = max;
				cur++;
				continue;
			}
			for (int i = 0; i < N; i++)
			{
				sum = 0;
				for (int m = i, n = 0; m < N && n < N; m++, n++)
				{
					if (cur == v[m][n]) sum++;
					else
					{
						if (sum > max) max = sum;
						if (sum >= N / 2) break;
						sum = 0;
					}
				}
				if (sum > max) max = sum;
				if (sum >= N - i) break;
			}
			if (max == N) 
			{
				ret[cur] = max;
				cur++;
				continue;
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1 - i; j >= 0; j--)
				{
					sum = 0;
					for (int m = 0, n = j; m < N && n >= 0; m++, n--)
					{
						if (cur == v[m][n]) sum++;
						else
						{
							if (sum > max) max = sum;
							if (sum >= N / 2) break;
							sum = 0;
						}
					}
					if (sum > max) max = sum;
					if (sum >= N - j) break;
				}
			}
			if (max == N) 
			{
				ret[cur] = max;
				cur++;
				continue;
			}
			for (int i = 1; i < N; i++)
			{
				
			}
			ret[cur] = max;
			cur++;
		}

		max = 0;
		for (int i = 0; i < M; i++)
			if (ret[i] > ret[max]) {
				maxs.clear();
				maxs.push_back(i);
				max = i;
			}
			else if (ret[i] == ret[max]){
				maxs.push_back(i);
			}

		return ret[max];
	}
}