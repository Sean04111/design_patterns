package Listener;

public class beWatched {
    private final int watchedId;

    public String Topic;
    public beWatched(int id,String Topic ){
        this.watchedId = id;
        this.Topic = Topic;
    }

    public int getWatchedId(){
        return this.watchedId;
    }

    public String getTopic(){
        return this.Topic;
    }
    public void Act(){
        System.out.println(this.getWatchedId()+"is acting...");
    }
}
