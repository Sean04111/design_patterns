package Decorator;

public abstract class Decorator extends Component {
    @Override
    public void Operation() {
        super.Operation();
    }
    public void Decorate(){
        System.out.println("Decoration");
    }
}
