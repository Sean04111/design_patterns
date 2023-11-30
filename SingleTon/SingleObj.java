package SingleTon;

public class SingleObj {
    private static final SingleObj SingleInstance = new SingleObj();

    private SingleObj(){}

    public static SingleObj GetSingleInstance(){
        return SingleInstance;
    }
}
