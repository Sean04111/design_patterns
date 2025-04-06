package Proxy;

public class Proxy extends Subject{
    private final RealSubject realSubject;
    public void PreOperation(){
        System.out.println("PreOperation");
    }
    public void AfterOperation(){
        System.out.println("AfterOperation");
    }
    @Override
    public void Operation(){
        PreOperation();
        realSubject.Operation();
        AfterOperation();
    }

    public Proxy(RealSubject realSubject){
        this.realSubject = realSubject;
    }
}
