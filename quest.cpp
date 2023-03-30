#include "quest.h"

std::shared_ptr<room> room::create(std::string phrase)
{
    return std::shared_ptr<room> (new room(phrase));
}

std::shared_ptr<room> move::get_room()
{
    std::cout << action_ << std::endl;
    return move_to_;
}

std::shared_ptr<item> interact::get_action()
{
    std::cout << action_ << std::endl;
    return interact_with_;
}

std::string item::get_name()
{
    return item_name_;
}

std::shared_ptr<room> room::enter_room(std::string next_room)
{
    return move_list_[next_room].get_room();
}

std::shared_ptr<item> room::do_action(std::string interaction)
{
    return interact_list_[interaction].get_action();
}

std::shared_ptr<item> item::create(std::string name)
{
    return std::shared_ptr<item> (new item(name));
}

std::shared_ptr<action> action::create(enum ACTION code, std::string phrase, std::string entity)
{
    switch (code)
    {
        case MOVE:
            return std::shared_ptr<action>(new move(phrase, entity));
            break;
        case INTERACT:
            return std::shared_ptr<action>(new interact(phrase, entity));
            break;
        // default:
        //     assert(false);
    }
}