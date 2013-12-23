#include "common.h"
using namespace std;
__int64 GetHeaderLenth(const char *url, const char *proxy = NULL, bool header = false, bool verbose = false){
	double downloadFileLenth = 0;
	CURL *handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, url);
	curl_easy_setopt(handle, CURLOPT_HEADER, 1);    
	curl_easy_setopt(handle, CURLOPT_NOBODY, 1);   
	curl_easy_setopt(handle, CURLOPT_TIMEOUT_MS, 1000);
	if (verbose)
		curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
	else
		curl_easy_setopt(handle, CURLOPT_VERBOSE, 0L);
	if (header)
		curl_easy_setopt(handle, CURLOPT_HEADER, 1L);
	else
		curl_easy_setopt(handle, CURLOPT_HEADER, 0L);
	if (proxy != NULL)
		curl_easy_setopt(handle, CURLOPT_PROXY, proxy);
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
	cout<<GetHeaderLenth("http://localhost/std/summary.ini", nullptr, true, true)<<endl;
	cout<<GetHeaderLenth("http://localhost/std/summary_2.ini")<<endl;
	cout<<GetHeaderLenth("http://localhost/std/summary_3.ini")<<endl;
	cout<<GetHeaderLenth("http://www.confusedbycode.com/curl/", "http://10.40.14.55:80")<<endl;
	cout<<GetHeaderLenth("http://www.confusedbycode.com/curl/", nullptr, true, true)<<endl;

	return 0;
}