package Factory;

public class FactoryB implements Factory{
    private  String FactoryName;
    FactoryB(String name){
        this.FactoryName = name;
    }
    private class ProductB {
        private String ProductName;
        private String Factory;
        ProductB(String name,String factory){
            this.ProductName = name;
            this.Factory = factory;
        }

    }
    public ProductB Produce(){
        return new ProductB("productB", this.FactoryName);
    }
}
