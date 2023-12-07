package Listener;

import java.nio.file.Watchable;
import java.util.ArrayList;

public class runner {

    public static ArrayList<beWatched> tobeWatched = new ArrayList<>();

    public static ArrayList<EventWatcher> Watchers = new ArrayList<>();

    public static ArrayList<beWatched> beWatcheds  = new ArrayList<>();

    public static void main(String[] args) {
        for (int i = 0; i<=10;i++){
            tobeWatched.add(new beWatched(i,"topicA"));
        }
    }
}
