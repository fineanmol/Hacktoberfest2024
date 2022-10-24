import java.util.Random;
import java.applet.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyAdapter;

/* 
<applet code="Brick.class" width="300" height="300"> 
</applet> 
*/  

public class Snake extends Applet implements KeyListener
{
    Random rand=new Random();
    static int snake[][]=new int[100][4];
    static int x=2,y=0,l=300,t=300,foodx=450,foody=450,speed=400,prox=0;
    boolean SideNav=true,TopNav=true,Restart=true,Pause=false,Suicide=false;
    public void init()
    {
        for(int k=0;k<10;k++)
        {
            snake[k][0]=l;  snake[k][1]=t;  snake[k][2]=30;  snake[k][3]=30;
            l+=29;  
        }
        addKeyListener(this);
    }
    public void keyPressed(KeyEvent kE)
    {
        int key=kE.getKeyCode();
        if(key==KeyEvent.VK_SPACE)  { Restart=true; Pause=false; }
        if(key==KeyEvent.VK_ENTER) Pause=!Pause;
        if(key==KeyEvent.VK_LEFT)
        {   x=-1;   y=0;    TopNav=false;  
        }
        else if(key==KeyEvent.VK_RIGHT && SideNav==false)
        {   x=1;    y=0;    TopNav=false;  
        }
        else if(key==KeyEvent.VK_UP)
        {   y=-1;   x=0;    SideNav=false;  
        }
        else if(key==KeyEvent.VK_DOWN && TopNav==false)
        {   y=1;    x=0;    SideNav=false;  
        }
        else if(key==KeyEvent.VK_INSERT)
        {      speed-=10;
        }
        else if(key==KeyEvent.VK_DELETE)
        {      speed+=10;
        }
        else {}
        repaint();
    }
    public void keyReleased(KeyEvent k) {}
    public void keyTyped(KeyEvent k)    {}
    void python()
    {   int a,b,i=9;
        while(i>0)
        {  
            snake[i][0]=snake[i-1][0];    snake[i][1]=snake[i-1][1];
            i--; 
        }
    }
    public void paint(Graphics g)
    {   int k=0;
        g.setColor(Color.CYAN);
        g.drawRect(200,10,700,30);
        g.fillRect(203,12,prox,16);
        try
        {
            g.setColor(Color.BLACK);
            g.fillOval(foodx,foody,30,30);
            if(foodx==snake[0][0] && foody==snake[0][1])
            {   prox+=35;    
                do{ foody=rand.nextInt(600); }while(foody%30!=0 || foody<=50);
                do{ foodx=rand.nextInt(1250); }while(foodx%30!=0 || foodx<=70);
            }
        g.drawRect(30,40,1300,680);
        if(Restart==true)
        for(k=0;k<10;k++)
        {   
            if(k==0)    g.setColor(Color.RED);  else g.setColor(Color.GREEN);   
            g.fillRect(snake[k][0],snake[k][1],30,30);    
            g.setColor(Color.BLACK);    
            g.drawLine(snake[k][0],snake[k][1],snake[k][0],snake[k][1]+30);
            g.drawLine(snake[k][0],snake[k][1],snake[k][0]+30,snake[k][1]);
            g.drawLine(snake[k][0],snake[k][1]+30,snake[k][0]+30,snake[k][1]+30);
            if(k==9)    g.drawLine(snake[k][0]+30,snake[k][1],snake[k][0]+30,snake[k][1]+30);
        }
        tag : 
        {   
            if(Pause==true)  break tag;
            if(prox>=700)   { g.setFont(new Font("Comic Sans MS",Font.BOLD,100)); g.drawString("YOU WIN !",150,250); Restart=false; x=2;  y=0;  foodx=450; foody=450; speed=200; Suicide=false; prox=0; break tag;}
            if(snake[0][0]<=30 || snake[0][0]>=1300 || snake[0][1]>=680 || snake[0][1]<=10 || Suicide==true) 
            { g.setFont(new Font("Comic Sans MS",Font.BOLD,100)); g.drawString("Snake Died ...THE END",150,250);   Restart=false; x=2;  y=0;  foodx=450; foody=450; speed=200; Suicide=false;  break tag; }      
                Thread.sleep(speed);   python();
                if(x==-1 || x==2)       {   snake[0][0]-=30; SideNav=true;  }            //for(k=0;k<10;k++) 
                else if(x==1)   {   snake[0][0]+=30; SideNav=false; }          
                else if(y==-1)  {   snake[0][1]-=30; TopNav=true;   }            
                else if(y==1)   {   snake[0][1]+=30; TopNav=false;  }            
                else {}
                for(int p=1;p<10;p++)  
                    if(snake[0][0]==snake[p][0] && snake[0][0]==snake[p][0] && snake[0][1]==snake[p][1] && snake[0][1]==snake[p][1])  Suicide=true;  
                repaint(); 
        }
        if(Restart==false)
        {   l=t=300;
            for(k=0;k<10;k++)
            {
                snake[k][0]=l;  snake[k][1]=t;  snake[k][2]=30;  snake[k][3]=30;
                l+=30;  
            }
        }
        }catch(Exception e){}
    }
}