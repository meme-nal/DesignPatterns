#include <iostream>
#include <vector>
#include <memory>


class IObserver {
public:
  virtual void update(float temparature) = 0;
  virtual ~IObserver() = default;
};


class WeatherStation {
private:
  float _temparature;
  std::vector<std::weak_ptr<IObserver>> observers;

public:
  void registerObserver(std::shared_ptr<IObserver> observer) {
    observers.push_back(observer);
  }

  void notifyObservers() {
    for (std::vector<std::weak_ptr<IObserver>>::iterator iter = observers.begin();
        iter != observers.end(); ++iter) {
      if (auto observer = iter->lock()) {
        observer->update(_temparature);
      }
    }
  }

  void setTemperature(float temparature) {
    this->_temparature = temparature;
    notifyObservers();
  }
};


class Display : public IObserver {
public:
  Display() {}

  void update(float temparature) override {
    std::cout << "Temperature: " << temparature << '\n';
  }
};