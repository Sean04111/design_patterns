 //
 // Created by Sean on 4/9/25.
 //

 #ifndef WALL_HPP
 #define WALL_HPP
 #include <memory>
 #include <stdexcept>

 struct Point2D {
     int x,y;
 };

 class Wall {
 protected:
     Point2D start, end;
     int elevation, height;
     Wall(Point2D start, Point2D end, int elevation, int height):
    start(start),
    end(end),
    elevation(elevation),
    height(height){}
 private:
     /*
      * 使用嵌套工厂模式
      */
     class BasicWallFactory {
     private:
         BasicWallFactory() = default;
     public:
         std::shared_ptr<Wall> create(const Point2D start, const Point2D end,
             const int elevation, const int height) {
             Wall* wall = new Wall(start, end, elevation, height);
         }
     };
 public:
     static BasicWallFactory factory;

     Point2D get_start() const {return start;}
     Point2D get_end() const {return end;}
 };

 enum class Material {
     brick,
     aerated_concrete,
     drywall
 };

 class SolidWall : public Wall {
     int width;
     Material material;
 protected:
     SolidWall(const Point2D start,const  Point2D end, const int elevation, const int height,const int width,const Material material):
     Wall(start, end, elevation, height),
     width(width),
     material(material) {};


     friend class WallFactory;
 public:
     /*
      * 以下两个静态方法被成为工厂方法；
      * 通过隐藏构造函数，然后通过工厂函数来提供只能指定类型的对象
      */
     static std::shared_ptr<SolidWall> create_main(Point2D start, Point2D end, const int elevation, const int height) {
         if (height < 0) return {};
         return std::make_shared<SolidWall>(start, end, elevation, height, 375, Material::aerated_concrete);
     }
     static std::unique_ptr<SolidWall> create_partition(Point2D start, Point2D end,
         int elevation, int height) {
         return std::make_unique<SolidWall>(start, end, elevation, height, 120, Material::brick);
     }

     bool intersects(const Wall& other) const{
         auto l1x1 = start.x;
         auto l1y1 = start.y;
         auto l1x2 = end.x;
         auto l1y2 = end.y;

         auto l2x1 = other.get_start().x;
         auto l2y1 = other.get_start().y;
         auto l2x2 = other.get_end().x;
         auto l2y2 = other.get_end().y;

         //快速排斥实验
         if ((l1x1 > l1x2? l1x1 : l1x2) < (l2x1 < l2x2? l2x1 : l2x2) ||
             (l1y1 > l1y2? l1y1 : l1y2) < (l2y1 < l2y2? l2y1 : l2y2) ||
             (l2x1 > l2x2? l2x1 : l2x2) < (l1x1 < l1x2? l1x1 : l1x2) ||
             (l2y1 > l2y2? l2y1 : l2y2) < (l1y1 < l1y2? l1y1 : l1y2))
         {
             return false;
         }
         //跨立实验
         if ((((l1x1 - l2x1)*(l2y2 - l2y1) - (l1y1 - l2y1)*(l2x2 - l2x1))*
             ((l1x2 - l2x1)*(l2y2 - l2y1) - (l1y2 - l2y1)*(l2x2 - l2x1))) > 0 ||
             (((l2x1 - l1x1)*(l1y2 - l1y1) - (l2y1 - l1y1)*(l1x2 - l1x1))*
             ((l2x2 - l1x1)*(l1y2 - l1y1) - (l2y2 - l1y1)*(l1x2 - l1x1))) > 0)
         {
             return false;
         }

         return true;
     };
 };

 class WallFactory {
     static std::vector<std::weak_ptr<Wall>> walls;

     enum class WallType {
         basic,
         main,
         partition,
     };
 public:
     static std::shared_ptr<SolidWall> create_main(Point2D start, Point2D end, const int elevation, const int height) {
         if (height < 0) return {};
         return std::make_shared<SolidWall>(start, end, elevation, height, 375, Material::aerated_concrete);
     }
     static std::shared_ptr<SolidWall> create_partition(Point2D start, Point2D end,const int elevation, const int height) {
         const auto this_wall = new SolidWall(start, end, elevation, height, 120, Material::brick);

         for (const auto wall : walls) {
             /*
              * 使用 weak_ptr.loc() 方法来获取一个 shared_ptr;
              */
             if (auto p = wall.lock()) {
                 if (this_wall->intersects(*p)) {
                     delete this_wall;
                     return {};
                 }
             }
         }

         std::shared_ptr<SolidWall> ptr{this_wall};
         walls.push_back(ptr);
         return ptr;
     }
     static std::shared_ptr<Wall> create_wall(WallType type, Point2D start, Point2D end, const int elevation, const int height) {
         switch (type) {
             case WallType::main:
                 return std::make_shared<SolidWall>(start, end, elevation, height, 375, Material::aerated_concrete);
             case WallType::partition:
                 return std::make_shared<SolidWall>(start, end, elevation, height, 120, Material::brick);
             case WallType::basic:
                 return std::make_shared<Wall>(start,end, elevation, height);
                 // return std::shared_ptr<Wall>{new Wall(start, end, elevation, height)};
         }
         return {};
     }

     /*
      * 将普通的构造函数迁移到工厂模式的步骤：
      * 1. 将构造函数声明为受保护的；
      * 2. 将工厂声明为对象的友元；(违背了开闭原则)
      * 3. 在工厂方法内部创建对象，然后以 shared_ptr 的形式返回
      */
 };

 /*
  * 另一种方法是使用嵌套的工厂，也就是在对象内部定义工厂；
  */


 #endif //WALL_HPP
