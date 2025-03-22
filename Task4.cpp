#include string
#include iostream
#include utility
#include vector
#include memory
#include algorithm
#include limits   Include this header for stdnumeric_limits

class Item {
private
    stdstring name;
    int quantity;
    float price;

public
    Item(
            stdstring name,
            int quantity,
            float price
    ) 
            name{stdmove(name)},
            quantity{quantity},
            price{price} {
    }

    stdstring get_name() const {
        return name;
    }

    int get_quantity() const {
        return quantity;
    }

    void set_quantity(int new_quantity) {
        quantity = new_quantity;
    }

    float get_price() const {
        return price;
    }

    bool is_match(const stdstring &other) const {
        return name == other;
    }
};

class Inventory {
private
    stdvectorstdunique_ptrItem items;
    float total_money;

    static void display_data(const Item &item) {
        stdcout  nItem name   item.get_name();
        stdcout  nQuantity   item.get_quantity();
        stdcout  nPrice   item.get_price();
    }

public
    Inventory()  total_money{0} {
    }

     Free resources properly in destructor
    ~Inventory() = default;   Vector of unique_ptr handles cleanup automatically

    void add_item() {
        stdstring name;
        int quantity;
        float price;

        stdcin.ignore(stdnumeric_limitsstdstreamsizemax(), 'n');
        stdcout  nEnter item name ;
        stdgetline(stdcin, name);
        stdcout  Enter quantity ;
        stdcin  quantity;
        stdcout  Enter price ;
        stdcin  price;

         Validate input
        if (quantity = 0  price = 0) {
            stdcout  nQuantity and price must be positive values.;
            return;
        }

         Check if item already exists
        auto it = stdfind_if(items.begin(), items.end(),
                              [&name](const stdunique_ptrItem& item) {
                                  return item-is_match(name);
                              });

        if (it != items.end()) {
             Update existing item quantity
            int new_quantity = (it)-get_quantity() + quantity;
            (it)-set_quantity(new_quantity);
            stdcout  nItem quantity updated.;
        } else {
             Add new item
            items.push_back(stdmake_uniqueItem(name, quantity, price));
            stdcout  nItem added successfully.;
        }
    }

    void sell_item() {
        stdstring item_to_check;
        stdcin.ignore(stdnumeric_limitsstdstreamsizemax(), 'n');
        stdcout  nEnter item name ;
        stdgetline(stdcin, item_to_check);

        auto it = stdfind_if(items.begin(), items.end(),
                              [&item_to_check](const stdunique_ptrItem& item) {
                                  return item-is_match(item_to_check);
                              });

        if (it != items.end()) {
            remove_item(it);
        } else {
            stdcout  nThis item is not in your Inventory;
        }
    }

    void remove_item(stdvectorstdunique_ptrItemiterator& item_it) {
        int input_quantity;
        Item item = item_it-get();
        stdcout  nEnter number of items to sell ;
        stdcin  input_quantity;

         Validate input
        if (input_quantity = 0) {
            stdcout  nQuantity to sell must be a positive value.;
            return;
        }

        int quantity = item-get_quantity();
        if (input_quantity = quantity) {
            float price = item-get_price();
            float money_earned = price  input_quantity;
            
            if (input_quantity == quantity) {
                 Remove the item completely if all are sold
                stdcout  nAll items sold. Removing from inventory.;
                items.erase(item_it);
            } else {
                 Update quantity if some remain
                item-set_quantity(quantity - input_quantity);
            }
            
            stdcout  nItems sold;
            stdcout  nMoney received   money_earned;
            total_money += money_earned;
        } else {
            stdcout  nCannot sell more items than you have.;
        }
    }

    void list_items() const {
        if (items.empty()) {
            stdcout  nInventory empty.;
            return;
        }

        for (const auto& item  items) {
            display_data(item);
            stdcout  n;
        }
        
         Show total money earned
        stdcout  nTotal money earned   total_money;
    }
    
    float get_total_money() const {
        return total_money;
    }
};

 no need to modify anything here
int main() {
    int choice;
    Inventory inventory_system;
    stdcout  Welcome to the inventory!;

    while (1) {
        stdcout  nnMENUn
                   1. Add new itemn
                   2. Sell itemn
                   3. List itemsn
                   4. Exitnn
                   Enter your choice ;
        stdcin  choice;

        switch (choice) {
            case 1
                inventory_system.add_item();
                break;

            case 2
                inventory_system.sell_item();
                break;

            case 3
                inventory_system.list_items();
                break;

            case 4
                stdcout  nTotal money earned $  inventory_system.get_total_money()  stdendl;
                stdcout  Exiting program. Thank you!  stdendl;
                exit(0);

            default
                stdcout  nInvalid choice entered;
                stdcin.clear();
                stdcin.ignore(stdnumeric_limitsstdstreamsizemax(), 'n');
                break;
        }
    }
}