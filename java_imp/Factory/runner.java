package Factory;

public class runner {
    public static void main(String[] args) {
        FactoryA fa = new FactoryA("fa");
        FactoryB fb = new FactoryB("fb");
        fa.Produce();
        fb.Produce();
    }
}
