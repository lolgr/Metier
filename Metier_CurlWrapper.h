#pragma once
#include <iostream>
#include <sstream>
#include <curl.h>

class CurlRequest 
{
    private:
        CURL* c;
        CURLcode HttpCode;

    public:
        CurlRequest() {
            c = curl_easy_init();
        }

        ~CurlRequest() {
            if (c) 
                curl_easy_cleanup(c);
        }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    std::string Get(std::string url) {
        if(!c) return "";

        std::string result = "";
        int retryCount = 5;
        while (result == "" && retryCount > 0) {
            curl_easy_setopt(c, CURLOPT_URL, url.c_str());
            curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(c, CURLOPT_WRITEDATA, &result);
            HttpCode = curl_easy_perform(c);
            retryCount -= 1;
        }
        return result;
    }

    CURLcode GetHttpCode(){
        return HttpCode;
    }
};