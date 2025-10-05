#include "inventory.h"

#include <string>

struct Item {
  public:
    std::string name;
    float unitWeight;
};

class Compartment {
  public:
    Item item;
    int quantity;
    int lowThreshold;
};

class Inventory {
  private:
    Compartment compartments[NUM_COMPARTMENTS] {};

    int findCompartment(std::string itemName) {
      for (int i = 0; i < sizeof(compartments); i++) {
        if (compartments[i].item.name.compare(itemName) == 0) {
          return i;
        }
      }

      return -1;
    }

    int findEmpty() {
      for (int i = 0; i < sizeof(compartments); i++) {
        if (compartments[i].quantity == 0) {
          return i;
        }
      }

      return -1;
    }
  
  public:
    Compartment getCompartment(int index) {
      return compartments[index];
    }
  
    int fill(Item item) {
      int index = findCompartment(item.name);

      if (index == -1) {
        // Not found, try to find empty compartment
        return findEmpty();      
      } else {
        // Found, add to existing
        return index;
      }
    }

    int take(Item item, int quantity) {
      int index = findCompartment(item.name);

      if (index == -1) {
        // Item not found
        return -1;
      } else {
        // Found, take from existing
        int available = compartments[index].quantity;

        if (available < quantity) {
          return -2;
        } else {
          return index;
        }
      }
    }
};