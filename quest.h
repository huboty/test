#include <iostream>
#include <memory>
#include <map>

enum ACTION
{
    MOVE,
    INTERACT
};

class quest 
{
public:
    static quest& get_quest()
    {
        std::cout << "Building quest" << std::endl;
        static quest q;
        return q;
    }

    quest(quest&) = delete;
    quest& operator=(const quest&) = delete;


private:
    room current_room_;
    quest()
    {

    }
};

class room
{
public:
    std::shared_ptr<room> room::create(std::string name);
    std::shared_ptr<room> enter_room(std::string next_room);
    void do_action(std::string interaction);

private:
    std::string enter_phrase_;
    std::map<std::string, move> move_list_; 
    std::map<std::string, interact> interact_list_;
    room(std::string phrase) : enter_phrase_(phrase){};   
};

class item
{
public:
    std::shared_ptr<item> item::create(std::string name);
    get_name();

private:
    std::string item_name_;
    item(std::string name) : item_name_(name){};
};


class action
{
public:
    std::shared_ptr<action> action::create(enum ACTION code, std::string phrase, std::string item);

private:
    std::string action_phrase_;
};

class move : public action
{
private:
    std::shared_ptr<room> move_to_;
    std::string action_;
public:
    std::shared_ptr<room> get_room();
    move(std::string phrase, std::string room) : move_to_(room::create(room)), action_(phrase){};
};

class interact : public action
{
private:
    std::shared_ptr<item> interact_with_;
    std::string action_;
public:
    std::shared_ptr<item> get_action();
    interact(std::string phrase, std::string item) : interact_with_(item::create(item)), action_(phrase){};
};