#pragma once

#include <string>
#include "Calculator.h"
#include "ContentProvider.h"

using namespace std;

class ChatBot {
public:

    ChatBot(string _username);

    void outputIntroduction();
    void enterChatBotLoop();
    void start();

    double doCalculations();
    string giveJokes();
    string giveQuotes();
    void takeResponse();
    void provideNegFeedback();
    void providePosFeedback();
    void clean(int time);
    void pausing(int time);

private:
    string username;
    bool keepTalking = true;
    Calculator* calculator;

    ContentProvider* jokeProvider;
    ContentProvider* quoteProvider;
};
