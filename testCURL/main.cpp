#include "common.h"
using namespace std;
__int64 GetHeaderLenth(const char *url){
	double downloadFileLenth = 0;
	CURL *handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, url);
	curl_easy_setopt(handle, CURLOPT_HEADER, 1);    
	curl_easy_setopt(handle, CURLOPT_NOBODY, 1);   
	if (curl_easy_perform(handle) == CURLE_OK) {
		curl_easy_getinfo(handle, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &downloadFileLenth);
	} else {
		downloadFileLenth = -1;
	}
	curl_easy_cleanup(handle);
	return downloadFileLenth;
}
int main()
{
	cout<<GetHeaderLenth("http://www.confusedbycode.com/curl/")<<endl;
	return 0;
}