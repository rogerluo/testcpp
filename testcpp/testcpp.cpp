#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

char* calculateOperationSequence(int *originalArray, int *resultArray, int length);

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

int main(){
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

//your code is here  
//下面才是让写代码的地方，其他的系统已经自动给出。主函数，只有一点点修改。
char* calculateOperationSequence(int * originalArray, int * resultArray, int length)
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