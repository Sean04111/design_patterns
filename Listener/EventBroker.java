package Listener;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class EventBroker{
    private static Map<String,ArrayList<EventWatcher>> listeners;

    public void AddListener(EventWatcher toAdd){
            if (listeners.get(toAdd.getTopic())==null){
                listeners.put(toAdd.getTopic(),new ArrayList<>());
            }else{
                listeners.get(toAdd.getTopic()).add(toAdd);
            }
    }

    public void NotifyCertainTopic(String Topic){
        listeners.get(Topic).forEach(eventWatcher -> {
            eventWatcher.WakeUp();
            listeners.get(Topic).remove(eventWatcher);
        });
    }

    public void NotifyAddTopics(){
        listeners.forEach((topic,beWatched)-> {
           beWatched.forEach(eventWatcher -> {
               eventWatcher.WakeUp();
               beWatched.remove(eventWatcher);
           });
        });
    }
}
