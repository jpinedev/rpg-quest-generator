#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "quest.hpp"

using namespace std;

int main() {
  cout << "RPG Quest Generator (v0.0.1)" << endl;

  Quest::Item item;
  item.name = "Potato";
  Quest::Collect collectPotatoes = Quest::Collect("Collect {item.count} {item.name}(s).", item, 5);
  Quest::Quest* collectPotatoesQuest = &collectPotatoes;

  cout << collectPotatoesQuest->toString() << endl;
  return 0;
}