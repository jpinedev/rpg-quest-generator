#ifndef QUEST_H
#define QUEST_H

#include <string>

namespace Quest {

  struct Item {
    std::string name;
  };

  class Quest {
    public:
      virtual std::string toString() = 0;
    protected:
      std::string _template;
  };

  class Collect : public Quest {
    public:
      Collect(const std::string & _template, const Item & _item, const int & _count);
      std::string toString() override;

    private:
      Item _item;
      int _count;
  };

}

#endif