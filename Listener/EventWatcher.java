package Listener;

public class EventWatcher {
    private beWatched ListenTo;
    private int WatcherId;

    public EventWatcher(beWatched beWatched,int id){
        this.ListenTo = beWatched;
        this.WatcherId = id;
    }

    public int getWatcherId(){
        return this.WatcherId;
    }

    public String getTopic(){
        return this.ListenTo.Topic;
    }
    public void WakeUp(){
        System.out.println(this.getWatcherId()+"Wake up");
    }
}
