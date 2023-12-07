package Adapter;

public class Adapter implements Target{
    public Adaptee adaptee;
    @Override
    public void Request(){
        this.adaptee.SpecificRequest();
    }
    public Adapter(Adaptee adaptee){
        this.adaptee=adaptee;
    }
}
