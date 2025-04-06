package Bridge;

public class sony implements TVSet{
    private String Name;
    public sony(String name){
        this.Name = name;
    }
    public String getName(){
        return this.Name;
    }
    @Override
    public void on(){
        System.out.println(this.getName()+" on");
    }
    @Override
    public void off(){
        System.out.println(this.getName()+" off");
    }

    @Override
    public void ChannelChange(){
        System.out.println(this.getName()+" channel changed");
    }

}
