package Factory;

public class FactoryA implements Factory{
   private  String FactoryName;
   FactoryA(String name){
       this.FactoryName = name;
   }
   private class ProductA {
       private String ProductName;
       private String Factory;
       ProductA(String name,String factory){
           this.ProductName = name;
           this.Factory = factory;
       }

   }
   public Factory.FactoryA.ProductA Produce(){
       return new ProductA("productA", this.FactoryName);
   }
}
