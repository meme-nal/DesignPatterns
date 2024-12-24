#include <iostream>
#include <vector>

class Entity {
private:
  std::vector<int> _data;

private:
  Entity() {}

public:
  Entity(const Entity&) = delete;
  Entity(const Entity&&) = delete;
  Entity& operator=(const Entity&) = delete;
  Entity& operator=(const Entity&&) = delete;

public:
  static Entity& getInstance() {
    static Entity e;
    return e;
  } 

  void add(int i) { _data.push_back(i); }
  int get(int i) const { return _data[i]; }
  int size() const { return _data.size(); }

};

int main() {
  Entity& ent = Entity::getInstance();

  ent.add(7);
  ent.add(8);

  std::cout << ent.size() << '\n';

  return 0;
}