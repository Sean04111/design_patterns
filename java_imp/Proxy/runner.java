package Proxy;

public class runner {
    public static void main(String[] args) {
        Proxy proxy = new Proxy(new RealSubject());
        proxy.Operation();
    }
}
