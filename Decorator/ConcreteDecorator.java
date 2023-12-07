package Decorator;

public class ConcreteDecorator extends Decorator{
    public ConcreteDecorator(){}

    @Override
    public void Operation(){
        super.Operation();
        this.Decorate();
    }

    @Override

    public void Decorate(){
        System.out.println("ConcreteDecorator Decoration");
    }



}
