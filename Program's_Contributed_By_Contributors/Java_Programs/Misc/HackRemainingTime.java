
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class HackRemainingTime {

    final static String deadlineTime = "2021-10-31 23:59:59";
    final static SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        process();
    }

    private static void process(){
        Long timeRemaining = getTimeRemaining();
        if(timeRemaining!=null && timeRemaining > 0){
            System.out.println("Come on! Hacktoberfest 2021 is ended in "+getReadableTime(timeRemaining));
            System.out.println("\n\n\nReset Time.... (y/n)");
            String in = sc.nextLine();
            if(in.equals("y")){
                cleaLine();
                process();
            }
        }else{
            System.out.println("You're late :(, see ya next year :D");
        }
    }

    private static String getReadableTime(Long timeRemaining){
        int dayMillis = 1000 /* 1s */ * 60 /* 1m */ * 60 /* 1h */ * 24 /* 1d */;
        int resultDay = (int)(timeRemaining/dayMillis);

        Long mod1 = timeRemaining %dayMillis;

        int hourMillis = 1000/* 1s */ * 60 /* 1m */ * 60 /* 1h */;
        int resultHour = (int) (mod1/hourMillis);

        Long mod2 = timeRemaining %hourMillis;

        int minMillis = 1000 /* 1s */ * 60 /* 1m */ ;
        int resultMin = (int) (mod2/minMillis);

        Long mod3 = mod2%minMillis;

        int secMillis = 1000 /* 1s */  ;
        int resultSec= (int) (mod3/secMillis);

        return resultDay+" day(s) "+resultHour+" hour(s) "+resultMin+" minute(s) "+resultSec+" second(s) ";
    }

    private static Long getTimeRemaining(){
        Long remainingTime = null;
        try {
            Date deadline = sdf.parse(deadlineTime);
            Calendar deadlineCal = Calendar.getInstance();
            deadlineCal.setTime(deadline);
            Calendar now = Calendar.getInstance();

            remainingTime = deadlineCal.getTimeInMillis()- now.getTimeInMillis();
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return remainingTime;
    }

    private static void cleaLine(){
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

}
