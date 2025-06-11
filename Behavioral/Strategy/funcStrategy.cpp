#include <functional>


class Human {
private:
  std::function<void()> _strategy;

public:
  void setStrategy(std::function<void()> strategy) { // get lambda for example
    _strategy = std::move(strategy);
  }

  void move() const {
    if (_strategy) {
      _strategy();
    }
  }
};