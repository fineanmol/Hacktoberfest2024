
import java.util.LinkedList;
import java.util.Objects;

/**
 *
 * @author Santiago Tumbaco
 */
public class Vertex <V, E> {
    private V data;
    private LinkedList<Edge<E, V>> egdes;
    private boolean visited;
    private double DAcumulativa;
    private Vertex<V, E> antecesor;
    private int index;
    private int valorAsociado;
    
    public Vertex(V data){
        this.data = data;
        egdes = new LinkedList<>();
        visited = false;
        antecesor = null;
        DAcumulativa=Double.POSITIVE_INFINITY;
        index=0;
        valorAsociado=0;
    }

    public Vertex<V, E> getAntecesor() {
        return antecesor;
    }

    public void setAntecesor(Vertex<V, E> antecesor) {
        this.antecesor = antecesor;
    }

    public V getData() {
        return data;
    }
    
    public boolean isVisited(){
        return visited;
    }

    public void setData(V data) {
        this.data = data;
    }

    public void setVisited(boolean visited){
        this.visited = visited;
    }
    
    public LinkedList<Edge<E, V>> getEgdes() {
        return egdes;
    }

    public void setEgdes(LinkedList<Edge<E, V>> egdes) {
        this.egdes = egdes;
    }

    public double getDAcumulativa() {
        return DAcumulativa;
    }

    public void setDAcumulativa(double DAcumulativa) {
        this.DAcumulativa = DAcumulativa;
    }
    

    @Override
    public int hashCode() {
        int hash = 7;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Vertex<V,E> other = (Vertex<V,E>) obj;
        if (!Objects.equals(this.data, other.data)) {
            return false;
        }
        return true;
    }   
    
    @Override
    public String toString(){
        return data.toString();
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public int getValorAsociado() {
        return valorAsociado;
    }

    public void setValorAsociado(int valorAsociado) {
        this.valorAsociado = valorAsociado;
    }
    
}
