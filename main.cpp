/*                                               Simple console application
 
 Chat with one public (for all users) and many private (for two users) rooms
 Allow register new unique users & excahge messages with all users or only one
 Users have unique ID number, unique name, password (8 simbols, literal, numbers, spec simbols)
*/

/* general logic 
main -> user_reg
     -> user_login
     -> user_change
     -> room_select
     -> chat_info
room_select -> room_search_user
            -> room_search_all
room_search_user/
room_search_all / -> /room_print
                     /room_chat
*/

#include <iostream>

#include "Interface.h"
#include "User.h"
#include "Message.h"
#include "Room.h"

// global vars
chat::User    *user    = nullptr;         // current user
chat::Message *message = nullptr;         // current message
chat::Room    *room    = nullptr;         // current room

                                          // all users, messages and chat rooms
std::vector<chat::User>    all_users;     //
std::vector<chat::Message> all_messages;  //
std::vector<chat::Room>    all_rooms;     //

                                          

interface::Command cmd = interface::Command::NO_COMMAND;    // command to work with chat

/////////////////////////////////////////////  declaration block  /////////////////////////////////////////////////

void init_chat();                     // init chat with some users and messages

bool user_reg();                      // registration new user with unique name
bool user_login();                    // login existing user
void user_change();                   // change name or password for logining user

int  find_user_ID(std::string str);   // find user ID based on its name
std::string find_user_name(int ID);   // find user name basid on its ID

void room_select();                   // search and select private or public room
bool room_search_user();              // search and select or create private room with needed user
bool room_search_all();               // search and select public room for all users

void room_print();                    // print on console selected chat room
void room_chat();                     // main function to print messages in chat

void chat_greet();                    // chat greeting
void chat_info();                     // list of command

/////////////////////////////////////////////  main function block  /////////////////////////////////////////////////

int main(){

    chat_greet();
    chat_info();

    init_chat();
    
    while (true) {
        std::cout << "                      Welcome to chat\n\n";
        std::cout << "Input >>reg  >>log  >>chg  >>room  >>info  >>quit command: ";
        std::string str;
        std::cin >> str;
        cmd = interface::get_command(str);
        switch (cmd) {
        case interface::Command::REG:
            if (user_reg())
                std::cout << "User " << user->get_name() << " register in chat\n";
            break;
        case interface::Command::LOGIN:
            if (user_login())
                std::cout << "User " << user->get_name() << " login in chat\n";
            break;
        case interface::Command::CHANGE:
            if (!user)
                std::cout << "No user are login in chat!\n";
            else
                user_change();
            break;
        case interface::Command::ROOM:
            if (!user)
                std::cout << "No user are login in chat!\n";
            else
                room_select();
            break;
        case interface::Command::INFO:
            chat_info();
            break;
        case interface::Command::QUIT:
            return 0;
        default:
            break;
        }
    }

}

////////////////////////////                                                                    //////////////////////////////

void init_chat() {
    

    // Init some users
    chat::User cur_user;
   
    cur_user = chat::User("Ivan", "!234Qwer");  // ID = 1
    all_users.push_back(cur_user);
    cur_user = chat::User("Bob", "123$qweR");   // ID = 2
    all_users.push_back(cur_user);
    cur_user = chat::User("Inna", "1@34qWer");  // ID = 3
    all_users.push_back(cur_user);
    cur_user = chat::User("Sonya", "12#4qwEr"); // ID = 4
    all_users.push_back(cur_user);
    
    // Init chat for all users
    chat::Room cur_room;  

    // Fill with some messages
    chat::Message cur_message;
    cur_message = chat::Message(1, "Hello!");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(1, "This is our work chat!");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(3, "Order: Green street, 17");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(3, "Boiler repairing");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(2, "Where are instruments?");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(1, "In truck!");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(2, "OK, I go");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    cur_message = chat::Message(4, "Stop, get offer list!");
    all_messages.push_back(cur_message);
    cur_room.add_message_ID(cur_message.get_ID());
    
    all_rooms.push_back(cur_room);

    return;
}

bool user_reg() {
    chat::User cur_user;

    cur_user.set_name(all_users);
    cur_user.set_pass();
    cur_user.reg();
    all_users.push_back(cur_user);
    user = &(all_users[all_users.size() - 1]);

    return true;
}

bool user_login() {
    chat::User *cur_user = nullptr;
    std::string str;
    do {
        chat::user_name_req();
        std::cout << "Input user name:  ";
        std::cin >> str;
    } while (!chat::user_name_valid(str));

    for (int i = 0; i < all_users.size(); i++) {
        if (str == all_users[i].get_name()) {
            cur_user = &all_users[i];
            break;
        }
    }

    if (!cur_user) {
        std::cout << "No user \"" << str << "\" are register in chat!\n";
        return false;
    }

    std::cout << "Input password:  ";
    std::cin >> str;
    if (!cur_user->check_pass(str)) {
        std::cout << "Invalid password!\n";
        return false;
    }

    user = cur_user;
    return true;
}

void user_change() {
    
    std::cout << "          Change name or password\n\n";

    while (true) {
        std::cout << "Input >>name  >>pass  >>quit command:  ";

        std::string str;
        std::cin >> str;

        cmd = interface::get_command(str);
        switch (cmd) {
        case interface::Command::NAME:
            user->set_name(all_users);
            break;
        case interface::Command::PASSWORD:
            user->set_pass();
            break;
        case interface::Command::QUIT:
            return;
        default:
            break;
        }
    }
}

int find_user_ID(std::string str) {
    int num = -1;
    for (const auto& all_user : all_users) {
        if (all_user.get_name() == str) {
            num = all_user.get_ID();
            break;
        }
    }
    return num;
}

std::string find_user_name(int ID) {
    std::string name;
    for (const auto& all_user : all_users) {
        if (all_user.get_ID() == ID) {
            name = all_user.get_name();
            break;
        }
    }
    return name;
}

/////////////////////////////////////////////  room_select function block  /////////////////////////////////////////////////

void room_select() {

    std::cout << "             Select room\n\n";

    while (true) {
        if (all_rooms.size() == 0) {
            std::cout << "No rooms in chat!\n";
            return;
        }

        std::cout << "Input >>user  >>all  >>quit command:  ";

        std::string str;
        std::cin >> str;

        cmd = interface::get_command(str);
        switch (cmd) {
        case interface::Command::USER:
            if (room_search_user())
                room_chat();
            room = nullptr;
            break;
        case interface::Command::ALL:
            if (room_search_all())
                room_chat();
            room = nullptr;
            break;
        case interface::Command::QUIT:
            room = nullptr;
            return;
        default:
            break;
        }
    }
}

/////////////////////////                                                                       //////////////////////////

bool room_search_user() {
 
    std::string str;
    do {
        chat::user_name_req();
        std::cout << "Input user name:  ";
        std::cin >> str;
    } while (!chat::user_name_valid(str));
    
    int user_ID = find_user_ID(str);

    if (user_ID == -1) {
        std::cout << "No user \"" << str << "\" registered in chat!\n";
        return false;
    }

    // this block find private chat with two users ID : user->get_ID()  (global var)
    //                                                  user_ID          (local var)
    for (int i = 0; i < all_rooms.size(); i++) {
        if (all_rooms[i].get_private() && (
            (all_rooms[i].get_user_1_ID() == user->get_ID() && all_rooms[i].get_user_2_ID() == user_ID) ||
            (all_rooms[i].get_user_1_ID() == user_ID        && all_rooms[i].get_user_2_ID() == user->get_ID())
            ))
        {
            room = &all_rooms[i];
            break;
        }
    }
    //

    // private room found
    if (room)
        return true;

    // create new private room
    chat::Room new_priv_room(user->get_ID(), user_ID, true);
    all_rooms.push_back(new_priv_room);
    room = &(all_rooms[all_rooms.size() - 1]);
    return true;
}

bool room_search_all() {
    for (int i = 0; i < all_rooms.size(); i++)
        if (all_rooms[i].get_private() == false) {
            room = &(all_rooms[i]);
            break;
        }
    return true;
}

////////////////////////////////////////////////  room_chat function block  /////////////////////////////////////////////////

void room_chat() {
    
    std::cout << "         You in chat room\n\n";

    room_print();

    std::cout << "Input message or  >>quit  command:  ";

    while (true) {
             
        std::string str;
        std::getline(std::cin, str);
        if (str != "") {
            cmd = interface::get_command(str);
            switch (cmd) {
            case interface::Command::QUIT:
                return;
            default:
                chat::Message msg(user->get_ID(), str);
                all_messages.push_back(msg);
                room->add_message_ID(msg.get_ID());
                break;
            }
        }
    }

}

void room_print() {
    std::string name;
    std::string text;
    std::vector<int> cur_messages_ID = room->get_message_ID();
    std::cout << std::endl;
    for (int i = 0; i < cur_messages_ID.size(); i++) {
        for (int k = 0; k < all_messages.size(); k++) {
            if (all_messages[k].get_ID() == cur_messages_ID[i]) {
                name = find_user_name(all_messages[k].get_user_ID());
                text = all_messages[k].get_text();
                std::cout << name << ":  " << text << "\n\n";
            }

        }
    }
}

////////////////////////////////////////////  chat greeting and command list  //////////////////////////////////////////

void chat_greet() {
    std::cout << "                 Console chat\n\n";
}

void chat_info() {
    std::cout << "**************************************************\n";
    std::cout << "                  Commands:\n\n"
              << ">>reg   - register new user\n"
              << ">>log   - login for exist user\n"
              << ">>chg   - change user data\n"
              << ">>name  - change user name\n"
              << ">>pass  - change user password\n"
              << ">>user  - choose user for private chating\n"
              << ">>all   - choose public room\n"
              << ">>info  - list of chat command\n"
              << ">>quit  - quit form room or program\n\n";
    std::cout << "**************************************************\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

