package builder;

public class Wrapper implements  Packing{
    private String Content;
    Wrapper(String content){
        this.Content = content;
    }

    @Override
    public String Pack(){
        return "Wrapper";
    }
}
