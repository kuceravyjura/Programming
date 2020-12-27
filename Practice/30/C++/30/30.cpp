# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <string>
using namespace std;
struct Coin {
    int count;
};

struct Rune {
    enum class Element { FIRE, WATER, EARTH, AIR } element;
    int level;
};

string to_string(Rune::Element& element);

struct Weapon {
    int damage;
    int critical;
    int durability;
};

struct Armor {
    int guard;
    int durability;
};

struct Item;
Item generateItem();

struct Item{
    enum class ItemType { COIN, RUNE, WEAPON, ARMOR } type;
    union Value { Coin coin; Rune rune; Weapon weapon; Armor armor; } value;

    Item& operator++(){
        *this = generateItem();
        return *this;
    }
};

Item GetCoin(int count);

Item GetRune(Rune::Element element, int level);
Item GetFireRune(int level);
Item GetWaterRune(int level);
Item GetEarthRune(int level);
Item GetAirRune(int level);

Item GetWeapon(int damage, int critical, int durability);
Item GetArmor(int guard, int durability);

template<class T, class S>
struct Pair{
    T first;
    S second;
};

vector<Pair<Item, double>> chances{
    {GetCoin(1000),             50.0},
    {GetFireRune(1),            6.0},
    {GetWaterRune(1),           13.0},
    {GetEarthRune(1),           7.0},
    {GetAirRune(1),             14.0},
    {GetFireRune(5),            0.6},
    {GetWaterRune(5),           1.3},
    {GetEarthRune(5),           0.7},
    {GetAirRune(5),             1.4},
    {GetFireRune(5),            0.06},
    {GetWaterRune(5),           0.13},
    {GetEarthRune(5),           0.07},
    {GetAirRune(5),             0.14},
    {GetWeapon(100, 0, 100),    1.4},
    {GetWeapon(75, 50, 100),    1.4},
    {GetArmor(50, 100),         2.8},
};

const int accuracy = 100;  
double count_total_chance() {
    double sum = 0;
    for (auto& pair : chances) {
        sum += pair.second;
    }
    sum *= accuracy;
    return sum;
}

const double total_chance = count_total_chance();

using LootBox = vector<Item>;

LootBox generateLootBox();

LootBox& operator<<(LootBox& lootbox, Item& item);

ostream& operator<<(ostream& out, Item& item);

ostream& operator<<(ostream& out, LootBox& lootbox);

LootBox& operator<<(LootBox& lootbox, Item item) {
    lootbox.push_back(item);
    return lootbox;
}

Item generateItem() {
    double chance = double(rand() % int(total_chance)) / 100;
    double z = 0;

    for (auto& elem : chances) {
        if (z <= chance && chance < z + elem.second) {
            return elem.first;
        }
        z += elem.second;
    }
    return chances[0].first;
}

LootBox generateLootBox() {
    LootBox box;
    srand(time(0));

    for (int i = 0; i < 3; ++i) {
        box << generateItem();
    }
    return box;
}

ostream& operator<<(ostream& out, Item& item) {
    Item::ItemType& type = item.type;

    if (type == Item::ItemType::COIN) {
        out << item.value.coin.count << " gold";
    }
    else if (type == Item::ItemType::RUNE) {
        Rune& rune = item.value.rune;
        out << "Rune of " << to_string(rune.element) << " level " << rune.level;
    }
    else if (type == Item::ItemType::WEAPON) {
        Weapon& weapon = item.value.weapon;
        out << "Weapon {damage: " << weapon.damage << ", critical: " << weapon.critical << ", durability: " << weapon.durability << "}";
    }
    else if (type == Item::ItemType::ARMOR) {
        Armor& armor = item.value.armor;
        out << "Armor {guard: " << armor.guard << ", durability: " << armor.durability<< "}";
    }
    out << flush;
    return out;
}

ostream& operator<<(ostream& out, LootBox& lootbox) {
    for (auto& elem : lootbox) {
        out << elem << "\n" << flush;
    }
    return out;
}

string to_string(Rune::Element& element) {
    string result;

    switch (element) {
    case Rune::Element::FIRE:
        result = "fire";
        break;
    case Rune::Element::WATER:
        result = "water";
        break;
    case Rune::Element::EARTH:
        result = "earth";
        break;
    case Rune::Element::AIR:
        result = "air";
        break;
    }
    return result;
}

Item GetCoin(int count) {
    return {
        Item {
            Item::ItemType::COIN,
            Item::Value {.coin = Coin{count}}
        }
    };
}
Item GetRune(Rune::Element element, int level) {
    return {
        Item {
            Item::ItemType::RUNE,
            Item::Value {
                .rune = Rune {
                    element,
                    level
                }
            }
        }
    };
}
Item GetFireRune(int level) {
    return GetRune(Rune::Element::FIRE, level);
}
Item GetWaterRune(int level) {
    return GetRune(Rune::Element::WATER, level);
}
Item GetEarthRune(int level) {
    return GetRune(Rune::Element::EARTH, level);
}
Item GetAirRune(int level) {
    return GetRune(Rune::Element::AIR, level);
}
Item GetWeapon(int damage, int critical, int durability) {
    return {
        Item {
            Item::ItemType::WEAPON,
            Item::Value{.weapon = Weapon{damage, critical, durability}}
        }
    };
}
Item GetArmor(int guard, int durability) {
    return {
        Item {
            Item::ItemType::ARMOR,
            Item::Value{.armor = Armor{guard, durability}}
        }
    };
}
int main() {
    string x; int check = 0;
    while (check == 0) {
        cout << "Открыть лутбокс? Yes/No" << endl;
        cin >> x;
        if (x == "Y" || x == "y" || x == "Yes" || x == "yes" || x == "yEs" || x == "yES" || x == "YeS" || x == "YES" || x == "yeS") {
            auto box = generateLootBox();
            cout << box << endl;
        }
        else if (x == "N" || x == "n" || x == "No" || x == "no" || x == "NO" || x == "nO") {
            check++;
        }
    }
};