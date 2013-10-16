#include "stdafx.h"
#include "Common.h"
#include <cstdlib>
#include <iostream>
void ReadLinuxFile(const string& file)
{
	char buf[1024] = {0};
	
	FILE * h = fopen(file.data(), "r");
	if (!h) return;
	cout << file << ":" << endl;

	if (fseek(h, 0, SEEK_END))
	{
		cout << "Failed to seek" << endl;
	}
	long size = ftell(h);
	cout << "size: " << size << endl;

	fseek(h, 0, SEEK_SET);
	int read = fread(buf, 1, 1024, h);
	cout << "read: " << read << endl;
	fclose(h);

	HANDLE hFile = CreateFileA( file.data(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		cout << "Fail to open in CreateFileA" << endl;
		return;
	}
	LARGE_INTEGER liSize = {0};
	if (FALSE == GetFileSizeEx(hFile, &liSize))
	{
		cout << "Failed to GetFileSizeEx" << endl;
	}
	cout << "size: " << liSize.QuadPart << endl;

	DWORD dwread = 0;
	ReadFile(hFile, buf, 1024, &dwread, NULL); 
	cout << "read: " << dwread << endl;

	CloseHandle(hFile);
}