package Prototype;

public class ProtoType {
    private String field;
    public ProtoType(String field){
        this.field = field;
    }
    public String GetField(){
        return this.field;
    }

    // Clone
    // Offers a method which can return a copy of this Object
    public ProtoType Clone(){
        return new ProtoType(this.GetField());
    }
}
