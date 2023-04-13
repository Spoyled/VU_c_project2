#include <iostream>
#include <limits>
#include <cmath>
#include "ContentProvider.h"

string ContentProvider::giveQuotes()
{
    clean(0);
    string quote;
    int userInput;

    cout << endl << "CHAT BOT: " << username << ", please enter a number between 1 and 10:" << endl;
    cout << username << ": ";
    while (!(cin >> userInput && userInput <=10 && userInput >=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "CHAT BOT: Please enter a valid number: ";
    }

    if(userInput >= 1 && userInput <= 10)
    {
        string quotes[10] = {
            "The only way to do great work is to love what you do. - Steve Jobs.",
            "The best preparation for tomorrow is doing your best today. - H. Jackson Brown Jr.",
            "Be the change you wish to see in the world. - Mahatma Gandhi.",
            "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle. - Christian D. ",
            "Success is not final, failure is not fatal: it is the courage to continue that counts. - Winston Churchill.",
            "The biggest adventure you can ever take is to live the life of your dreams. - Oprah Winfrey.",
            "Be kind, for everyone you meet is fighting a battle you know nothing about. - Wendy Mass.",
            "The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela.",
            "Happiness is not something ready-made. It comes from your own actions. - Dalai Lama.",
            "The only limit to our realization of tomorrow will be our doubts of today. - Franklin D. Roosevelt."
        };
        quote = quotes[userInput - 1];
    }

    return "CHAT BOT: " + quote;
}

string ContentProvider::giveJokes()
{
    clean(0);
    string joke;
    int userInput;
    
    cout << endl << "CHAT BOT: " << username << ", please enter a number between 1 and 10:" << endl;
    cout << username << ": ";
    while (!(cin >> userInput && userInput <=10 && userInput >=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "CHAT BOT: Please enter a valid number between 1 and 10: ";
    }

    if(userInput >= 1 && userInput <= 10)
    {
        string jokes[10] = {
            "What do you call a fake noodle? An impasta!",
            "Why did the tomato turn red? Because it saw the salad dressing!",
            "What do you call a can opener that doesn't work? A can't opener!",
            "Why did the math book look sad? Because it had too many problems!",
            "Why did the hipster burn his tongue? He drank his coffee before it was cool.",
            "Why did the chicken cross the playground? To get to the other slide!",
            "What do you call a fake stone in Ireland? A sham rock!",
            "Why did the bike fall over? Because it was two-tired!",
            "How do you organize a space party? You planet!",
            "What did the grape say when it got stepped on? Nothing, it just let out a little wine."
        };
         joke = jokes[userInput - 1];
    }

    return "CHAT BOT: " + joke;
}

ContentProvider::ContentProvider(string _username)
{
    username = _username;
}

void ContentProvider::clean(int time) {
    _sleep(time);
    system("cls");
}