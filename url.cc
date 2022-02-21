// URL
// Written by Elliot Etches
// 2022/02/04
// UofL Comp Sci. - 3750

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <queue>
#include "url.h"

// Constructor
url::url(char * url) {  
  urlC = url; 
  urlG = url;
}

// Write Memory Callback
int 
url::WriteMemoryCallback(char *contents, size_t size, size_t nmemb, std::string *userp) {
  if(userp == NULL)
     return 0;

  userp->append(contents, size*nmemb);
  
  return size * nmemb; 
}

// Get HTML
// Interfaces with libcurl library
std::string url::getHTML(){
  std::string html;
  char* URL = urlC;
  CURL *curl;
  CURLcode res;
  
  // Initialize libcurl
  curl = curl_easy_init();
  
  if(curl) {
    // libcurl options
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0"); 
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);   
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);

    // Get HTML
    res = curl_easy_perform(curl);
    
    // Report any errors
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
        curl_easy_strerror(res));
    
    curl_easy_cleanup(curl);
  }
  return html; 
}

// Find Links
std::queue<std::string> url::findLinks() {
  std::queue<std::string> ret;
  std::string html = getHTML();
  std::string holder;
  
  while(html.find("href") != std::string::npos) {
    // Locate links
    html = html.substr(html.find("href=\"") + 6, html.size());
    holder = html.substr(0, html.find("\""));
    html = html.substr(html.find("\""), html.size());
    
    // Filter out non-http, non-uleth, and notice board links
    if(holder.find("http") != std::string::npos 
       && holder.find("ulethbridge.ca") != std::string::npos
       && holder.find("notice") == std::string::npos) {
    ret.push(holder);
    }
   }
  return ret;
}

// Site Name
std::string url::siteName() {
  std::string url = urlG;
  size_t i = 0;  
  
  i = url.find("http://");
  if(i != std::string::npos)
    url = url.substr(i + 7, url.size());  
  i = url.find("https://"); 
  if(i != std::string::npos)
    url = url.substr(i + 8, url.size());
  i = url.find("/");
  if(i != std::string::npos)
    url = url.substr(0, i);
  return url;
}

// Add Site
std::string url::addSiteName(std::string url) {
  std::string urlN = urlG;
  
  if(url.find("http") != std::string::npos) {
    if(url[0] == '/')
      urlN.append(url);
    else {
      urlN.push_back('/');
      urlN.append(url);
    }
  } else {
    urlN = url;
  }
  return urlN;
}


