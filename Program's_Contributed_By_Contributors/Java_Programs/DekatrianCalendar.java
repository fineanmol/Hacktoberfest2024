import java.util.Calendar;

public class DekatrianCalendar {

    private Calendar calendar = Calendar.getInstance();
    private int currentYear = calendar.get(Calendar.YEAR);
    private int currentMonth = calendar.get(Calendar.MONTH) + 1;
    private int currentDayOfMonth = calendar.get(Calendar.DAY_OF_MONTH);

    public int currentDekaDayOfMonth = Integer.parseInt(currentDekaDate().split("-")[0]);
    public int currentDekaMonth = Integer.parseInt(currentDekaDate().split("-")[1]);
    public int currentDekaYear = Integer.parseInt(currentDekaDate().split("-")[2]);

    public boolean checkDekatrian(String date){

        int day = Integer.parseInt(date.split("-")[0]);
        int month = Integer.parseInt(date.split("-")[1]);
        int year = Integer.parseInt(date.split("-")[2]);

        if(isLeapYear(year)){
            if(month == 0 && day > 2){
                return false;
            }
        }
        else{
            if(month == 0 && day > 1){
                return false;
            }
        }

        if(month > 13 || day > 28){
            return false;
        }
        else if(month < 0 && day < 1){
            return false;
        }

        return true;
    }

    public String dekaToGreg(String date){

        int day = Integer.parseInt(date.split("-")[0]);
        int month = Integer.parseInt(date.split("-")[1]);
        int year = Integer.parseInt(date.split("-")[2]);

        if(!checkDekatrian(date)){
            throw new InvalidDateDekaException("Data inválida");
        }

        int yearDay = 0;

        //Leap Year
        if(isLeapYear(year)){

            yearDay++;

            //Sinchronian Day
            if(month == 0 && day == 2){
                return ("02-01-" + year);
            }
        }

        //Achronian Day
        if(month == 0 && day == 1){
            return ("01-01-" + year);
        }

        yearDay += (month * 28) - 28;
        yearDay = yearDay + day;

        Calendar gDate = Calendar.getInstance();
        gDate.set(Calendar.DAY_OF_YEAR, yearDay + 1);
        int gDay = gDate.get(Calendar.DAY_OF_MONTH);
        int gMonth = gDate.get(Calendar.MONTH) + 1;

        return gDay + "-" + gMonth + "-" + year;
    }

    public String gregToDeka(int day, int month, int year){

        Calendar cDate = Calendar.getInstance();
        cDate.set(year, month-1, day);

        int yearDay = cDate.get(Calendar.DAY_OF_YEAR) - 1;

        //Leap Year
        if(isLeapYear(year)){

            yearDay--;

            //Sinchronian Day
            if(month == 1 && day == 2){
                return ("02-00-" + year);
            }
        }

        //Achronian Day
        if(month == 1 && day == 1){
            return ("01-00-" + year);
        }

        int dMonth = yearDay/28;
        int dDay = yearDay - (dMonth*28);
        dMonth++;

        if(dDay == 0){
            dDay = 28;
            dMonth--;
        }

        return dDay + "-" + dMonth + "-" + year;
    }

    public String currentDekaDate(){

        return gregToDeka(currentDayOfMonth, currentMonth, currentYear);
    }

    private String gregToDekaLong(int d, int m, int y){

        String cDate = gregToDeka(d,m,y);

        return getDekaDateLong(cDate);

    }

    public String getDekaDateLong(String date) {

        if(!checkDekatrian(date)){
            throw new InvalidDateDekaException("Data inválida");
        }

        int day = Integer.parseInt(date.split("-")[0]);
        int month = Integer.parseInt(date.split("-")[1]);
        int year = Integer.parseInt(date.split("-")[2]);

        if(isAchrorian(date)){
            return "Achronian-" + year;
        } else if(isSinchronian(date)) {
            return "Sinchronian-" + year;
        } else {
            return day + "-" + getMonthName(month) + "-" + year;
        }

    }

    public String currentDekaDateLong(){

        return gregToDekaLong(currentDayOfMonth, currentMonth, currentYear);
    }

    private String getMonthName(int month){

        switch (month){
            case 1:
                return "Auroran";
            case 2:
                return "Borean";
            case 3:
                return "Coronian";
            case 4:
                return "Driadan";
            case 5:
                return "Electran";
            case 6:
                return "Faian";
            case 7:
                return "Gaian";
            case 8:
                return "Hermetian";
            case 9:
                return "Irisian";
            case 10:
                return "Kaosian";
            case 11:
                return "Lunan";
            case 12:
                return "Maian";
            case 13:
                return "Nixian";
            default:
                throw new InvalidDateDekaException("A data é inválida.");
        }
    }

    public int getDaysInMonth(String date){

        int month = Integer.parseInt(date.split("-")[1]);
        int year = Integer.parseInt(date.split("-")[2]);

        if(month == 0){
            if(isLeapYear(year)){
                return 2;
            }
            else{
                return 1;
            }
        }
        else{
            return 28;
        }
    }

    public int getDayOfWeek(String date){

        String[] gregDate = dekaToGreg(date).split("-");

        int day = Integer.parseInt(gregDate[0]);
        int month = Integer.parseInt(gregDate[1]);
        int year = Integer.parseInt(gregDate[2]);

        Calendar calendar = Calendar.getInstance();
        calendar.set(year,month,day);

        int i = calendar.get(Calendar.DAY_OF_WEEK);

        int[] daysOfWeek = {3,4,5,6,0,1,2};

        return daysOfWeek[i];
    }

    public boolean isAchrorian(String date){
        int day = Integer.parseInt(date.split("-")[0]);
        int month = Integer.parseInt(date.split("-")[1]);

        if(month == 0) {
            if (day == 1) {
                return true;
            }
        }

        return false;

    }

    public boolean isSinchronian(String date){
        int day = Integer.parseInt(date.split("-")[0]);
        int month = Integer.parseInt(date.split("-")[1]);
        int year = Integer.parseInt(date.split("-")[2]);

        if (month==0){
            if(isLeapYear(year)){
                if (day == 2)
                    return true;
            }

        }


        return false;
    }

    public static boolean isLeapYear(int year) {
        Calendar cal = Calendar.getInstance();
        cal.set(Calendar.YEAR, year);
        return cal.getActualMaximum(Calendar.DAY_OF_YEAR) > 365;
    }

}