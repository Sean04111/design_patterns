package builder;

public abstract class Burger implements Item{
    @Override
    public Packing Pack(){
        return new Wrapper("Burger");
    }


}
