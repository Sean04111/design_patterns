package builder;

public class Bottle implements Packing{
    private  String Content;
    Bottle(String content){
        this.Content = content;
    }
    @Override
    public String Pack(){
        return "Bottle";
    }

}
