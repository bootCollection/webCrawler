// URL
// Written by Elliot Etches
// 2022/02/04
// UofL Comp Sci. - 3750

// URL downloads the raw HTML of a given URL and parses it for links.

#ifndef URL_H
#define URL_H
#include <queue>

class url {
  private:
    // URL to be parsed
    char* urlC;
    std::string urlG;
    
    // Provides memory management for the HTML page being downloaded
    static int 
    WriteMemoryCallback(char *contents, size_t size, size_t nmemb, std::string *userp);
    
    // Downloads the HTML content of a given URL using libcurl
    std::string getHTML();
  public:
    // Constructor
    url(char *);
    
    // Extracts links from a given URL
    std::queue<std::string> findLinks();
    
    // Returns the root URL for a given URL
    // ex: ulethbridge.ca/ross --> ulethbridge.ca
    std::string siteName();
    
    // Adds the root URL to relative links found in HTML
    // ex: /ross --> ulethbridge.ca/ross
    std::string addSiteName(std::string);
};

#endif
