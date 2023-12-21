package Bridge;

public class runner {
    public static void main(String[] args) {
        TVSet tv1 = new sony("SONY_PX109");
        controller c1 = new TCLController(tv1,"TCL_CO901");
        c1.on();
        c1.off();
        c1.ChannelChange();
    }
}
