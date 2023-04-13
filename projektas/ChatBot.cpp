#include <iostream>
#include <limits>
#include "ChatBot.h"
#include "Calculator.h"
#include "ContentProvider.h"

void ChatBot::start()
{
    outputIntroduction();
    enterChatBotLoop();
}

void ChatBot::outputIntroduction() {
    cout << endl << endl <<"CHAT BOT: Welcome to the Chatbot!" << endl << endl;

    cout << "This chatbot is designed to have conversations with you on a variety of" << endl;
    cout << "topics. It can help you with simple calculations, ask you trivia" << endl;
    cout << "questions, and even tell you a joke or two!" << endl << endl;

    cout << "To get started, simply type your name when prompted and the" << endl;
    cout << "chatbot will use your name throughout the conversation." << endl << endl;

    cout << "Please note that this chatbot is not a real person, but rather a" << endl;
    cout << "computer program designed to simulate conversation. As such, it may" << endl;
    cout << "not always understand what you are saying or respond in the way that you expect." << endl << endl;

    cout << "We hope you enjoy chatting with our chatbot!" << endl << endl;
}

void ChatBot::enterChatBotLoop() {
    clean(6000);

    cout << endl << "ATTENTION! PLEASE WRITE EVERYTHING WITHOUT ANY MISTAKES, EVERYTHING SHOULD BE WRITTEN AS IN THE BRACKETS!!!" << endl << endl;

    while (keepTalking == true)
    {
        cout << endl <<"CHAT BOT: " << username << ", please choose one of the options (calculations; jokes; quotes; bye)"<< endl << endl;

        string mainResponse;
        cout << username << ": ";
        cin >> mainResponse;

        if (mainResponse == "calculations")
        {
            cout <<endl << "CHAT BOT: Great! Let's do some simple calculations." << endl << endl;
            cout << calculator->calculate() << " is the answer to your mathematic expression." << endl << endl;
            takeResponse();
        }
        else if (mainResponse == "jokes")
        {
            cout << jokeProvider->giveJokes() << endl << endl;
            takeResponse();
        }
        else if (mainResponse == "quotes")
        {
            cout << quoteProvider->giveQuotes() << endl << endl;
            takeResponse();
        }
        else if (mainResponse == "bye")
        {
            cout << "CHAT BOT: BYYEE :)" << endl;
            keepTalking = false;
        }
        else
        {
            cout << endl << "CHAT BOT: I didn't understand your Input... Please try again." << endl;
        }
            
    }
}

void ChatBot::takeResponse()
{
    string mainResponse;

    cout << "CHAT BOT: Did you like it? (Yes, No): " << endl;
    cout << username << ": "; cin >> mainResponse;

    if (mainResponse == "Yes")
        providePosFeedback();
    
    else if (mainResponse == "No")
        provideNegFeedback();
    
    else
    {
        cout << "CHAT BOT: I didn't understand your Input..." << endl;
        enterChatBotLoop();
    }
}

void ChatBot::provideNegFeedback()
{
    string mainResponse;

    cout << endl <<"CHAT BOT: I am sorry that you didn't like my response, can we talk still? (Yes, No)" << endl << endl;
    cout << username << ": "; cin >> mainResponse;

    if (mainResponse == "Yes")
    {
        cout << endl <<"CHAT BOT: I hope next time you gonna love it." << endl;
        enterChatBotLoop();
    }

    else if (mainResponse == "No")
    {
        cout << "CHAT BOT: I'm sorry that it went that way, have a good day. :))";
        exit(0);
    }

    else
        cout << "CHAT BOT: I didn't understand your Input... Please try again." << endl;
}

void ChatBot::providePosFeedback()
{
    string mainResponse;

    cout << "CHAT BOT: I am happy that you are happy with the response, do you want to continue the talking with me? (Yes, No)" << endl;
    cout << username << ": "; cin >> mainResponse;

    if (mainResponse == "Yes")
        enterChatBotLoop();

    else if (mainResponse == "No")
    {
        cout << "CHAT BOT: BYEE ! :))";
        exit(0);
    }

    else
        cout << "CHAT BOT: I didn't understand your Input... Please try again." << endl;
}

void ChatBot::clean(int time) {
    _sleep(time);
    system("cls");
}

ChatBot::ChatBot(string _username)
{
    username = _username;
    calculator = new Calculator(username);
    jokeProvider = new ContentProvider(username);
    quoteProvider = new ContentProvider(username);
}


   