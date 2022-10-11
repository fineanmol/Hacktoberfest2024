import java.util.Scanner;
class Database
{
 private int readers;
 public Database()
 {
 this.readers = 0;
 }
 public void read(int number)
 {
 synchronized(this)
 {
 this.readers++;
 System.out.println("Reader " + number + " starts reading.");
 }
 final int DELAY= 5000;
 try
 {
 Thread.sleep((int) (Math.random()* DELAY));
 }
 catch (InterruptedException e) {}
 synchronized(this)
 {
 System.out.println("Reader "+ number + " stops reading.");
 this.readers--;
 if (this.readers == 0)
 {
 this.notifyAll();
 }
 }
}
public synchronized void write(int number)
{
 while (this.readers != 0)
 {
 try
 {
 this.wait();
 }
 catch (InterruptedException e) {}
}
System.out.println("Writer" + number + " starts writing.");
final int DELAY = 5000;
try
{
 Thread.sleep((int) (Math.random() * DELAY));
}
catch (InterruptedException e) {}
System.out.println("Writer " + number + " stops writing.");
this.notifyAll();
}
}
class Reader extends Thread
{
 private static int readers = 0;
 private int number;
 private Database database;
public Reader (Database database)
{
 this.database = database;
 this.number = Reader.readers++;
}
public void run()
{
 while (true)
 {
 final int DELAY= 5000;
 try
 {
 Thread.sleep ((int) (Math.random() * DELAY));
 }
 catch (InterruptedException e) {}
 this.database.read(this.number);
 }
}
}
class Writer extends Thread
{
 private static int writers= 0;
 private int number;
 private Database database;
public Writer(Database database)
{
 this.database = database;
 this.number = Writer.writers++;
}
public void run()
{
 while (true)
 {
 final int DELAY= 5000;
 try
 {
 Thread.sleep((int) (Math.random() * DELAY));
 }
 catch (InterruptedException e) {}
 this.database.write(this.number);
 }
}
}
public class CompetingThreads1050 {
 public static void main(String[] args) {
 Scanner sc= new Scanner (System.in);
 int arr[] = new int [2];
 System.out.println("Enter number of Readers");
 arr[0]=sc.nextInt ();
 System.out.println("Enter number of Writers");
 arr[1]=sc.nextInt ();
 if (arr.length < 2)
 {
 System.out.println("Usage: java Simulator <number of readers> <num
ber of writers>");
 }
 else
 {
 final int READERS = arr[0];
 final int WRITERS = arr[1];
 Database database = new Database();
 for (int i = 0; i < READERS; i++)
 {
 new Reader(database).start();
 }
 for (int i= 0; i < WRITERS; i++)
 {
 new Writer(database).start();
 }
 }
 sc.close();
 }
}
