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