#include "ChatBot.h"
#include <string>

using namespace std;

int main() {
    string username;

    cout << "CHAT BOT: Please insert your name: ";
    getline(cin,username);

    cout << endl << "CHAT BOT: Nice to meet you, " << username  << "!" << endl;
    
    ChatBot* chatBot = new ChatBot(username);

    chatBot->start();

    return 0;
}
