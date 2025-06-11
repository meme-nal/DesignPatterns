#include <iostream>
#include <memory>


class MoveStrategy {
public:
  virtual void move() = 0;
  virtual ~MoveStrategy() = default;
};


class WalkStrategy : public MoveStrategy {
public:
  void move() override {
    std::cout << "Walk\n";
  }
};


class DriveStrategy : public MoveStrategy {
public:
  void move() override {
    std::cout << "Drive\n";
  }
};


class ScooterStrategy : public MoveStrategy {
public:
  void move() override {
    std::cout << "Scooter\n";
  }
};


class Human {
private:
  std::unique_ptr<MoveStrategy> _strategy;

public:
  void setStrategy(std::unique_ptr<MoveStrategy> strategy) {
    _strategy = std::move(strategy);
  }

  void move() const {
    if (_strategy) {
      _strategy->move();
    }
  }
};