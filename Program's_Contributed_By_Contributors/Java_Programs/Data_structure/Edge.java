
import java.util.Objects;

/**
 *
 * @author Santiago Tumbaco
 */
public class Edge<E, V> {
    
    private Vertex<V, E> origen;
    private Vertex<V, E> destino;
    private E data;
    private int peso;
    
    public Edge(Vertex<V, E> origen, Vertex<V, E> destino, E data, int peso){
        this.origen = origen;
        this.destino = destino;
        this.data = data;
        this.peso = peso;
    }

    public Vertex<V, E> getOrigen() {
        return origen;
    }

    public void setOrigen(Vertex<V, E> origen) {
        this.origen = origen;
    }

    public Vertex<V, E> getDestino() {
        return destino;
    }

    public void setDestino(Vertex<V, E> destino) {
        this.destino = destino;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    @Override
    public boolean equals(Object o) {
        if(!(o instanceof Edge))
            return false;
        
        Edge<E, V> edge = (Edge<E, V>) o;
        
        if(edge.getOrigen().getData().equals(origen.getData()) && 
           edge.getDestino().getData().equals(destino.getData()))
            return true;
        
        return false;            
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 73 * hash + Objects.hashCode(this.origen);
        hash = 73 * hash + Objects.hashCode(this.destino);
        hash = 73 * hash + Objects.hashCode(this.data);
        hash = 73 * hash + this.peso;
        return hash;
    }
    
    @Override
    public String toString(){
        return String.format("(%s, %s, %s, %d)",origen, destino, data, peso);
    }   
}
