package builder;

public abstract class ColdDrink implements Item{

    @Override
    public Packing Pack(){
        return new Bottle("ColdDrink");
    }

}
