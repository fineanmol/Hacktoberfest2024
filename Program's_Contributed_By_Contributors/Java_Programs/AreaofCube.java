

class Cube 
{
    double edge_length;
    double area;
    double volume;
    
    Cube(double l) 
    {
        edge_length = l;
    }
 
    void CubeArea() 
    {
        area = 6 * edge_length * edge_length;
    }
 
    void CubeVolume() 
    {
        volume = edge_length * edge_length * edge_length;
    }
 
    void display() 
    {
        System.out.println("Lenght of edge of a cube is : " + edge_length);
        System.out.println("Surface Area of the cube is : " + area);
        System.out.println("Volume of the cube is : " + volume);
    }
}
 
public class AreaofCube 
{
    public static void main(String[] argv) 
    {
        Cube c1 = new Cube(5);
 
        c1.CubeArea();
        c1.CubeVolume();
        c1.display();
    }
}