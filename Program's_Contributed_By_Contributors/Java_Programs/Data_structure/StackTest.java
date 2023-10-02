import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import org.junit.Test;
import org.junit.jupiter.api.Assertions;

public class StackTest{
    Stack stackTest =new Stack(10);

   @Test
    public void testIsEmpty(){
        Assertions.assertTrue(stackTest.isEmpty());
     }
    
     @Test
     public void testIsEmptyFalse(){
        stackTest.push(10); 
         Assertions.assertFalse(stackTest.isEmpty());
      }
   
    @Test
    public void testPush() 
    {
    ByteArrayOutputStream out= new ByteArrayOutputStream();
    System.setOut(new PrintStream(out));
              stackTest.push(5);
              stackTest.peek();
              Assertions.assertEquals(5,stackTest.peek());
              stackTest.push(4);
              Assertions.assertEquals(4,stackTest.peek());
              stackTest.push(3);
              Assertions.assertEquals(3,stackTest.peek());
              stackTest.push(2);
              Assertions.assertEquals(2,stackTest.peek());
              stackTest.push(1);
              Assertions.assertEquals(1,stackTest.peek());
    }

    @Test
    public void testPeek() 
    {
    ByteArrayOutputStream out= new ByteArrayOutputStream();
    System.setOut(new PrintStream(out));
              stackTest.push(5);
              stackTest.push(4);
              stackTest.push(3);
              stackTest.push(2);
              stackTest.push(1);
              Assertions.assertEquals(1,stackTest.peek());
              stackTest.pop();
              Assertions.assertEquals(2,stackTest.peek());
              stackTest.pop();
              Assertions.assertEquals(3,stackTest.peek());
              stackTest.pop();
              Assertions.assertEquals(4,stackTest.peek());
    }

    @Test
    public void testPop() 
    {
    stackTest.push(5);
    stackTest.push(4);
    stackTest.push(3);
    stackTest.push(2);
    stackTest.push(1);
    Assertions.assertEquals(1,stackTest.peek());
    stackTest.pop();
    Assertions.assertEquals(2,stackTest.peek());
    stackTest.pop();
    Assertions.assertEquals(3,stackTest.peek());
    stackTest.pop();
    Assertions.assertEquals(4,stackTest.peek());
    
}

@Test
public void testDisplay() 
{
ByteArrayOutputStream out= new ByteArrayOutputStream();
System.setOut(new PrintStream(out));

          stackTest.push(5);
          stackTest.push(4);
          stackTest.push(3);
          stackTest.push(2);
          stackTest.push(1);
          stackTest.display();
          Assertions.assertEquals("1 2 3 4 5".replaceAll(" ",""),out.toString().replaceAll(" ",""));
    }
}