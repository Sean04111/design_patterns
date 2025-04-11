 //
 // Created by Sean on 4/9/25.
 //

 #ifndef CAFE_HPP
 #define CAFE_HPP
 #include <iostream>
 #include <map>

 struct HotDrink {
     virtual void prepare(int volume) = 0;
 };

 struct Tea : HotDrink {
     void prepare(int volume) override {
         std::cout << "Tea preparing" << std:: endl;
     }

 };

 struct Coffee : HotDrink {
     void prepare(int volume) override {
         std::cout << "Coffee preparing" << std::endl;
     }
 };

 std::unique_ptr<HotDrink> make_drink(std::string type) {
     std::unique_ptr<HotDrink> drink;
     if (type = "tea") {
         drink = std::make_unique<Tea>();
         drink -> prepare(200);
     }else {
         drink = std::make_unique<Coffee>();
         drink -> prepare(200);
     }
     return drink;
 }

 class HotDrinkFactory {
 public:
     virtual std::unique_ptr<HotDrink> make() const = 0;
 };

 class CoffeeFactory : public HotDrinkFactory {
     std::unique_ptr<HotDrink> make() const override {
         auto coffee = std::make_unique<Coffee>();
         coffee ->prepare(200);
         return coffee;
     }
 };

 class TeaFactory : public HotDrinkFactory {
     std::unique_ptr<HotDrink> make() const override {
         auto tea = std::make_unique<Tea>();
         tea->prepare(200);
         return tea;
     }
 };

 class DrinkFactory {
     std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
 public:
     DrinkFactory() {
         hot_factories["tea"] = std::make_unique<TeaFactory>();
         hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
     }

     std::unqiue_ptr<HotDrink> make_drink(std::string type) {
        auto drink = hot_factories[type] -> make();
         drink -> prepare(200);
         return drink;
     }
 };

 #endif //CAFE_HPP

 /*
  * 使用工厂模式的好处：
  * 1. 可以知道已经创建的特定类型的对象的数量；
  * 2. 可以修改或者完全替换整个对象的创建过程；
  * 3. 如果使用智能指针，那么可以通过观察对象的引用计数来获取对象在其他地方被引用的数量；（weak_ptr）
  */
