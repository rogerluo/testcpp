#include "common.h"
using namespace std;
int GetHeader(const char * url)
{
	CURL* curl = curl_easy_init();
	curl_easy_cleanup(curl);
	return 0;
}
int main()
{
	GetHeader("");
	return 0;
}