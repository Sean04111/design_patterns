package Bridge;

public class TCLController implements controller{

    private TVSet controlling;

    private String Name;

    public TCLController(TVSet tvSet,String name){
        this.controlling = tvSet;
        this.Name = name;
    }

    public TVSet getControlling(){
        return this.controlling;
    }
    public String getName(){
        return this.Name;
    }
    @Override
    public void on(){
        System.out.println(this.getName()+" on");
        this.getControlling().on();
    }

    @Override
    public void off(){
        System.out.println(this.getName()+" off");
        this.getControlling().off();
    }

    @Override
    public void ChannelChange(){
        System.out.println(this.getName()+" Channel changed");
        this.getControlling().ChannelChange();
    }

}
