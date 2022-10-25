public class SensorDemo {



    public static void main(String[] args){

        ISensor humiditySensor = new HumiditySensor("Humidity Sensor 224");

        IMotionTracker humidityTracker = new SensorLocation("Colombo");

        ISensor rainFallSensor = new RainFallSensor("RainFall Sensor 667");

        IMotionTracker rainFallTracker = new SensorLocation("Kandy");



         ISensor rainFallSensorNew = new RainFallSensor("RainFall Sensor 890");

         IMotionTracker rainFallTrackerNew = new SensorLocation("Badulla");



        ISensor sensorArray[] = new ISensor[]{humiditySensor, rainFallSensor,rainFallSensorNew};

        IMotionTracker[] trackerArray = new IMotionTracker[]{humidityTracker, rainFallTracker,rainFallTrackerNew};

        RemoteController rm1 = new RemoteController(0, sensorArray, trackerArray);

        rm1.startService();

        rm1.locationService();

        rm1.stopService();

        RemoteController rm2=new RemoteController(1, sensorArray, trackerArray);

        rm2.startService();

        rm2.locationService();

        rm2.stopService();

    }

}





interface ISensor{

    void on();

    void off();

}



interface IMotionTracker{

    void displayLocation();

}



class HumiditySensor implements ISensor{



    String name;



    HumiditySensor(String name){

        this.name = name;

    }



    public void on() {

        System.out.println(name+" switch on");

    }



    public void off() {

        System.out.println(name+" switch off");

    }

}







class SensorLocation implements IMotionTracker{



    String locName;



    SensorLocation(String locName){

        this.locName = locName;

    }



    public void displayLocation() {

        System.out.println("Sensor Location = "+locName);

    }

}



class RainFallSensor implements ISensor{



    String name;



    RainFallSensor(String name){

        this.name = name;

    }



    public void on() {

        System.out.println(name+" switch on");

    }



    public void off() {

        System.out.println(name+" switch off");

    }

}

class RemoteController{

    int value;

    ISensor[] sArray;

    IMotionTracker[] tArray;



    RemoteController(int value, ISensor[] sArray, IMotionTracker[] trackerArray){

        this.value =value;

        this.sArray = sArray;

        this.tArray = trackerArray;

    }



    void startService(){

        System.out.println("--Starting all sensors. Sensor Switch value : "+value+" --");

        switch (value){

            case 0: for (ISensor iSensor: sArray) {

                iSensor.off();

            }break;

            case 1:for (ISensor iSensor: sArray) {

                iSensor.on();

            }break;

        }

        System.out.println("--Task completed--\n");

    }



    void stopService(){

        System.out.println("--Stopping all sensors--");

        for (ISensor iSensor: sArray) {

            iSensor.off();

        }

        System.out.println("--Task completed--\n");

    }



    void locationService(){

        System.out.println("--Getting sensor locations--");

        for (IMotionTracker iMotionTracker: tArray) {

            iMotionTracker.displayLocation();

        }

        System.out.println("--Display locations completed--\n");

    }

}

