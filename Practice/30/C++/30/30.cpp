#include <iostream>
#include <vector>

using namespace std;

struct Coin {
    short count;
};

struct Rune {
    enum class Element { FIRE, WATER, EARTH, AIR } element;
    short level;
};

struct Weapon {
    short damage;
    short critical;
    short durability;
};

struct Armor {
    short guard;
    short durability;
};

struct Item {
    enum class ItemType { COIN, RUNE, WEAPON, ARMOR } type;
    union Value {
        Coin coin;
        Rune rune;
        Weapon weapon;
        Armor armor;
    } value;

    static Item GetCoin(short count) {
        return { 
            Item{
                Item::ItemType::COIN, Item::Value{.coin = Coin{count}
                }
            } 
        };
    }
    static Item GetRune(Rune::Element element, short level) {
        return { 
            Item{
                Item::ItemType::RUNE, Item::Value{
                .rune = Rune{element, level}
                }
            } 
        };
    }
    static Item GetWeapon(short damage, short critical, short durability) {
        return { 
            Item{
                Item::ItemType::WEAPON, Item::Value{
                .weapon = Weapon{damage, critical, durability}
                }
            } 
        };
    }
    static Item GetArmor(short guard, short durability) {
        return { 
            Item{
                Item::ItemType::ARMOR, 
                Item::Value{
                .armor = Armor{guard, durability}
                }
            } 
        };
    }

    Item& operator++() {
        return *this;
    }
};

template<class T, class S>
struct Pair {
    T first;
    S second;
};

std::vector<Pair<Item, double>> chances{
    {Item::GetCoin(1000), 50.0},
    {Item::GetRune(Rune::Element::FIRE,  1), 6.0},
    {Item::GetRune(Rune::Element::WATER, 1), 13.0},
    {Item::GetRune(Rune::Element::EARTH, 1), 7.0},
    {Item::GetRune(Rune::Element::AIR,   1), 14.0},
    {Item::GetRune(Rune::Element::FIRE,  5), 0.6},
    {Item::GetRune(Rune::Element::WATER, 5), 1.3},
    {Item::GetRune(Rune::Element::EARTH, 5), 0.7},
    {Item::GetRune(Rune::Element::AIR,   5), 1.4},
    {Item::GetRune(Rune::Element::FIRE,  5), 0.06},
    {Item::GetRune(Rune::Element::WATER, 5), 0.13},
    {Item::GetRune(Rune::Element::EARTH, 5), 0.07},
    {Item::GetRune(Rune::Element::AIR,   5), 0.14},
    {Item::GetWeapon(100, 0, 100), 1.4},
    {Item::GetWeapon(75, 50, 100), 1.4},
    {Item::GetArmor(50, 100), 2.8},
};



using LootBox = std::vector<Item>;

LootBox generateLootBox() {
    LootBox box;
    return box;
}

int main() {
    auto box = generateLootBox();
    std::cout << box << std::endl;
};