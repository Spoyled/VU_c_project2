#pragma once

#include <iostream>
#include <limits>
#include <string>

using namespace std;

class ContentProvider {
    string username;
public:

    string giveJokes();
    string giveQuotes();
    ContentProvider(string username);
    void clean(int time);
};