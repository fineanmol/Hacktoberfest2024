
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

/**
 *
 * @author Santiago Tumbaco
 */
public class GraphLA<V, E> {

    private LinkedList<Vertex<V, E>> vertices;
    private boolean directed;
    private LinkedList<LinkedList<V>> componentesConexas;

    public GraphLA(boolean directed) {
        this.vertices = new LinkedList<>();
        this.directed = directed;
        componentesConexas = new LinkedList();
    }

    public boolean estaVacio() {
        return vertices.isEmpty();
    }

    public boolean isInTheSameComponent(E dato1, E dato2) {
        //buscar vertice encuentra el vertice que contiene este dato1
        //para no recorrer toda las componentes conexas
        //solo encontramos a la que pertenece dato1 al encontrar su vertice en el grafo
        //esto funciona tanto para grafos dirijidos como no dirigidos ya que si dato1 y dato2 forman parte de una misma
        //componente conexa significa que existe un camina de dato1 a dato2 y de dato2 a dato1
        Vertex<E, V> vertex = this.buscarVertice(dato1);
        if (vertex == null) {
            return false;
        }
        //creamos una cola para agregar todos los vertices que forman parte de
        //la componente conexa donde esta vertex
        Queue<Vertex<E, V>> nodosConexos = new LinkedList();
        nodosConexos.add(vertex);
        while (!nodosConexos.isEmpty()) {
            Vertex<E, V> v = nodosConexos.remove();
            LinkedList<Edge<V, E>> edges = v.getEgdes();
            //recorremos en todos los vertices de cada elemento de la cola
            for (Edge<V, E> edge : edges) {
                Vertex<E, V> v1 = edge.getOrigen();
                Vertex<E, V> v2 = edge.getDestino();
                //les definimos que ya han sido visitadas
                v1.setVisited(true);
                v2.setVisited(true);
                //comparamos si los vertices que recorremos son igual al dato2 que
                //es el unico que nos falta de comparar si esta en la micma componente conexa
                if (v2.getData().equals(dato2) || v1.getData().equals(dato2)) {
                    return true;
                } //si v2 no a sido visitado lo agregamos a la cola
                else if (!v2.isVisited()) {
                    nodosConexos.add(v2);
                }
            }
        }

        return false;
    }

//    public boolean isInTheSameComponent(E dato1, E dato2) {
////buscar vertice encuentra el vertice que contiene este dato1
////para no recorrer toda las componentes conexas
////solo encontramos a la que pertenece dato1 al encontrar su vertice en el grafo
//        Vertex<E, V> vertex = this.buscarVertice(dato1);
////este for de intentos es los 2 casos que aseguran que si el vertice de dato1 y vertice de dato2
////estan en la misma componente conexa los encontremos de 2 formas
////1. ir del vertice de dato1 al vertice de dato2
////2. ir del vertice de dato2 al vertice de dato1
////realizamos esto para que el metodo pueda aplicarse tanto para grafos dirigidos como no dirigidos, queremos encontrar primero a dato2
//        E datoEncontrar = dato2;
//        for (int intentos = 1; intentos <= 2; intentos++) {
//            if (vertex == null) {
//                return false;}
//            //creamos una cola para agregar todos los vertices que forman parte de
//            //la componente conexa donde esta vertex
//            Queue<Vertex<E, V>> nodosConexos = new LinkedList();
//            nodosConexos.add(vertex);
//            while (!nodosConexos.isEmpty()) {
//                Vertex<E, V> v = nodosConexos.remove();
//                LinkedList<Edge<V, E>> edges = v.getEgdes();
//                //recorremos en todos los vertices de cada elemento de la cola
//                for (Edge<V, E> edge : edges) {
//                    Vertex<E, V> v1 = edge.getOrigen();
//                    Vertex<E, V> v2 = edge.getDestino();
//                //les definimos que ya han sido visitadas
//                    v1.setVisited(true);
//                    v2.setVisited(true);
//                //comparamos si los vertices que recorremos son igual al dato2 que
//                //es el unico que nos falta de comparar si esta en la micma componente conexa
//                    if (v2.getData().equals(datoEncontrar) || v1.getData().equals(datoEncontrar)) {
//                        return true;} 
//                //si v2 no a sido visitado lo agregamos a la cola
//                    else if (!v2.isVisited()) {
//                        nodosConexos.add(v2);}}}
////si no se puede encontrar una ruta del vertice del dato1 al vertice del dato2 cuando son dirigidas
////se intentara de ir del vertice de dato2 al vertice del dato1
//            vertex = this.buscarVertice(dato2);
////resetearVertices() hace que todos los vertices visitados le cambie su valor a no visitados para poder volver a recorrer
////pero ahora del vertice de dato2 al vertice de dato1
//            this.ResetearVertices();
////queremos ahora encontrar a dato1
//            datoEncontrar = dato1;}
//        return false;}
//    public GraphLA<String,String> getCartesianProduct(GraphLA<String,String> G1,GraphLA<String,String> G2){
//        GraphLA<String,String> producto=new GraphLA(false);
//        //Hacer las combinaciones de vertices de G1 con G2
//        for(Vertex<String,String> g1:G1.vertices){
//            for(Vertex<String,String> g2: G2.vertices){
//                producto.addVertex(g1.getData()+g2.getData());
//            }
//        }
//        //Unir los vertices de H
//        for(Vertex<String,String> UV:producto.vertices){
//            for(Vertex<String,String>WZ :producto.vertices){
//                if(!UV.equals(WZ)){
//                    Character u=UV.getData().charAt(0);
//                    Character v=UV.getData().charAt(1);
//                    Character w=WZ.getData().charAt(0);
//                    Character z=WZ.getData().charAt(0);
//                    Edge<String,String> edgeVZ=G2.BuscarEdge(v,z);
//                    Edge<String,String> edgeUW=G2.BuscarEdge(u,w);
//                    if((G1.vertices.contains(u) && G2.vertices.contains(w) 
//                        && edgeVZ!=null) || (G1.vertices.contains(v) && G2.vertices.contains(z)
//                            && edgeUW!=null)){
//                        producto.connect(UV.getData(), WZ.getData(), "", 0);
//                    }
//                }
//            }
//        }
//        return producto;
//    }

//    public static Map< String, Map< String, List<Student>>> getRegistros(Graph<Student, Map<String, String>> grafo) {
//        Map< String, Map< String, List<Student>>> mapa = new HashMap();
//        LinkedList<Vertex<Student, Map<String, String>>> vertices = grafo.getVertices();
//        for (Vertex<Student, Map<String, String>> vertex : vertices) {
//            LinkedList<Edge< Map<String, String>, Student>> edges = vertex.getEgdes();
//            Set<String> materias = mapa.keySet();
//            Student student = vertex.getContent();
//            for (Edge< Map<String, String>, Student> edge : edges) {
//
//                Map<String, String> paralelo_materia = edge.getData();
//                Set<String> claves=paralelo_materia.keySet();
//                Iterator<String> it=claves.iterator();
//                while (it.hasNext()) {
//                String materia=it.next();
//                    if (materias.contains(materia)) {
//                        //si la materia esta contenida buscamos el paralelo
//                        String paralelo = paralelo_materia.get(materia);
//                        Map< String, List<Student>> paralelo_est = mapa.get(materia);
//                        Set<String> paralelos = paralelo_est.keySet();
//                        if (paralelos.contains(paralelo)) {
//                            //si el parelelo esta contenido buscamos los estudiantes
//                            List<Student> students = paralelo_est.get(paralelo);
//                            if (!students.contains(student)) {
//                                //si el estudiante no esta contenido lo agregamos
//                                students.add(student);
//                            }
//
//                        } else {
//                            //si el paralelo no esta contenido lo agregamos y creamos la lista
//                            LinkedList<String> students= new LinkedList();
//                            students.add(student);
//                            paralelo_est.put(paralelo, students);
//                        }
//                    } else {
//                        //si esque la materia no esta en el mapa la agregamos y ponemos como clave
//                        //el mapa con el paralelo y la lista con este primer estudiante
//                        Map<String,List<Student>> paralelo_st= new HashMap();
//                        LinkedList<String> students= new LinkedList();
//                        students.add(student);
//                        paralelo_st.put(paralelo_materia.get(materia), students);
//                        mapa.put(materia, paralelo_st);
//                    }
//                }
//            }
//        }
//        return mapa;
//    }
//    public static GraphLA generarGafoSintactico(String texto) {
//        texto = texto.replace(",", "");
//        texto = texto.replace(".", "");
//        texto = texto.replace(":", "");
//        texto = texto.replace(";", "");
//        texto = texto.toLowerCase();
//        String[] lista = texto.split(" ");
//        GraphLA grafo = new GraphLA(true);
//        for (int i = 0; i < lista.length - 1; i++) {
//            //Metodo que retorn el vertice si existe en el grafo
//            Vertex<String, Integer> vertice = grafo.buscarVertice(lista[i]);
//            Vertex<String, Integer> destino = grafo.buscarVertice(lista[i + 1]);
//            if (vertice != null) {
//                if (destino != null) {
//                    //Metodo que retorna el edge entre 2 vertices
//                    Edge<Integer, String> edge = grafo.buscarEdge(vertice, destino);
//                    if (edge != null) {
//                        edge.setPeso(edge.getPeso() + 1);
//                    } else {
//                        grafo.addVertex(vertice);
//                        grafo.addVertex(destino);
//                        grafo.connect(vertice, destino, null, 1);
//                    }
//                } else {
//                    destino = new Vertex(lista[i + 1]);
//                    grafo.addVertex(destino);
//                    grafo.connect(vertice, destino, null, 1);
//                }
//            } else {
//                if (destino != null) {
//                    vertice = new Vertex(lista[i]);
//                    grafo.addVertex(vertice);
//                    grafo.connect(vertice, destino, null, 1);
//                } else {
//                    vertice = new Vertex(lista[i]);
//                    destino = new Vertex(lista[i + 1]);
//                    grafo.addVertex(vertice);
//                    grafo.addVertex(destino);
//                    grafo.connect(vertice, destino, null, 1);
//                }
//            }
//        }
//        return grafo;
//    }
    public LinkedList<LinkedList<V>> ComponentesFuertementeConexas() {
        if (!directed) {
            System.out.println("Este metodo no es aplicable a grafosno dirijidos");
        } else {
            int index = 1;
            Stack<Vertex<V, E>> vertexs = new Stack();
            for (Vertex<V, E> vertex : vertices) {
                if (vertex.getIndex() == 0) {
                    conexionFuerte(vertex, index, vertexs);
                }
            }
        }
        return componentesConexas;
    }

    private void conexionFuerte(Vertex<V, E> vertex, int index, Stack<Vertex<V, E>> pila) {
        vertex.setIndex(index);
        vertex.setValorAsociado(index);
        index++;
        pila.push(vertex);
        LinkedList<Edge<E, V>> egdes = vertex.getEgdes();
        for (Edge<E, V> edge : egdes) {
            Vertex<V, E> ady = edge.getDestino();
            if (ady.getIndex() == 0) {
                conexionFuerte(ady, index, pila);
                vertex.setValorAsociado(Math.min(vertex.getValorAsociado(), ady.getValorAsociado()));
            } else if (pila.contains(ady)) {
                vertex.setValorAsociado(Math.min(vertex.getValorAsociado(), ady.getIndex()));
            }
        }
        if (vertex.getIndex() == vertex.getValorAsociado()) {
            Vertex<V, E> asociado = null;
            LinkedList<V> componente = new LinkedList();
            while (!vertex.equals(asociado) && !pila.isEmpty()) {
                asociado = pila.pop();
                componente.add(asociado.getData());
            }
            componentesConexas.add(componente);

        }
    }

    public boolean Dijkstra(V data) {
        //ResetearVertices();
        Vertex<V, E> vertex = buscarVertice(data);
        if (vertex == null) {
            return false;
        }
        Vertex<V, E> antecesor = vertex.getAntecesor();
        if (antecesor == null) {
            vertex.setDAcumulativa(0);
            System.out.println("entro: " + vertex.getData());
        }

        //recorrer sus aristas y tartar de cambiarle su valor acumulativo y su antecesor
        LinkedList<Edge<E, V>> egdes = vertex.getEgdes();
        for (Edge<E, V> edge : egdes) {
            Vertex<V, E> destino = edge.getDestino();
            double acumulativo = ValorEdge(vertex, destino) + vertex.getDAcumulativa();
            if (acumulativo < destino.getDAcumulativa()) {
                //Cambiarle el valor acumulativo a su sucesor
                destino.setDAcumulativa(acumulativo);
                destino.setAntecesor(vertex);
                //System.out.println("Vertex: " + vertex.getData() + " es mejor para " + destino.getData());
            }
            //aplicar dijkstra recursivamente
            this.Dijkstra(destino.getData());
        }
        return true;

    }
//
//    public Stack<Vertex<V, E>> CaminoCorto(V destino) {
//        Vertex<V, E> vertex = buscarVertice(destino);
//        Stack<Vertex<V, E>> camino = new Stack();
//        camino.push(vertex);
//        System.out.println("Camino: " + vertex.getData());
//        if (vertex == null) {
//            System.out.println("Este vertice no esta incluido en el grafo");
//        } else {
//            Vertex<V, E> antecesor = vertex.getAntecesor();
//            if (antecesor != null) {
//                camino=this.CaminoCorto(antecesor.getData());
//            }
//        }
//        return camino;
//    }
//    public void Imprimir(V destino){
//        Stack<Vertex<V, E>> camino=CaminoCorto(destino);
//        while(!camino.isEmpty()){
//            Vertex<V,E> vertex=camino.pop();
//            System.out.println("Dato: "+vertex.getData()+" valor: "+vertex.getDAcumulativa());
//        }
//    }

    public void ResetearVertices() {
        for (Vertex<V, E> vertex : vertices) {
            vertex.setDAcumulativa(Double.POSITIVE_INFINITY);
            vertex.setAntecesor(null);

        }
    }

    public double CaminoMasCorto(V origen, V destino) {
        ResetearVertices();
        this.Dijkstra(origen);
        Vertex<V, E> v = buscarVertice(origen);
        Vertex<V, E> v2 = buscarVertice(destino);
        if (v == null || v2 == null) {
            return Double.POSITIVE_INFINITY;
        }
        return v2.getDAcumulativa();
    }

    public int ValorEdge(Vertex<V, E> antecesor, Vertex<V, E> sucesor) {
        LinkedList<Edge<E, V>> egdes = antecesor.getEgdes();
        for (Edge<E, V> edge : egdes) {
            if (edge.getOrigen().equals(antecesor) && edge.getDestino().equals(sucesor)) {
                return edge.getPeso();
            }
        }
        return 0;
    }

    public boolean addVertex(V data) {
        Vertex<V, E> v = new Vertex<>(data);
        return (data == null || vertices.contains(v)) ? false : vertices.add(v);
    }

    public boolean connect(V origen, V destino, E data, int peso) {
        if (origen == null || destino == null) {
            return false;
        }

        Vertex<V, E> vo = buscarVertice(origen);
        Vertex<V, E> vd = buscarVertice(destino);

        if (vo == null || vd == null) {
            return false;
        }

        Edge<E, V> e = new Edge<>(vo, vd, data, peso);

        if (vo.getEgdes().contains(e)) {
            return false;
        }

        vo.getEgdes().add(e);
        if (!directed) {
            Edge<E, V> e1 = new Edge<>(vd, vo, data, peso);
            vd.getEgdes().add(e1);
        }
        return true;
    }

    private Vertex<V, E> buscarVertice(V data) {
        for (Vertex<V, E> v : vertices) {
            if (v.getData().equals(data)) {
                return v;
            }
        }
        return null;
    }

    public int getOutDegree(V data) {
        if (data == null) {
            return -1;
        }

        Vertex<V, E> v = buscarVertice(data);
        return (v == null) ? -1 : v.getEgdes().size();
    }

    public int getInDegree(V data) {
        Vertex<V, E> vertex = buscarVertice(data);
        if (vertex == null) {
            return -1;
        }

        int grado = 0;

        for (Vertex<V, E> v : vertices) {
            for (Edge<E, V> e : v.getEgdes()) {
                if (e.getDestino().equals(vertex)) {
                    grado++;
                }
            }

        }
        return grado;
    }

    @Override
    public String toString() {
        StringBuilder v = new StringBuilder();
        v.append(" v={");

        StringBuilder a = new StringBuilder();
        a.append(" a={");

        for (Vertex<V, E> vertex : vertices) {
            v.append(vertex.getData());
            v.append(", ");
            for (Edge<E, V> e : vertex.getEgdes()) {
                a.append(e.toString());
                a.append(", ");
            }
        }
        if (!vertices.isEmpty()) {
            v.delete(v.length() - 2, v.length());
        }
        if (a.length() > 4) {
            a.delete(a.length() - 2, a.length());
        }

        v.append("}");
        a.append("}");
        return v.toString() + "\n" + a.toString();
    }

    public boolean removerVertice(V data) {
        if (data == null) {
            return false;
        }

        Vertex<V, E> v = buscarVertice(data);
        if (v == null) {
            return false;
        }

        for (Vertex<V, E> vertex : vertices) {
            Iterator<Edge<E, V>> l = vertex.getEgdes().iterator();
            while (l.hasNext()) {
                Edge<E, V> e = l.next();
                if (e.getDestino().equals(v) || e.getOrigen().equals(v)) {
                    l.remove();
                }
            }
        }

        v.setData(null);
        v.setEgdes(null);
        vertices.remove(v);
        return true;

    }

    public boolean removerArco(V origen, V destino) {
        if (origen == null || destino == null) {
            return false;
        }

        Vertex<V, E> vo = buscarVertice(origen);
        Vertex<V, E> vd = buscarVertice(destino);

        if (vo == null || vd == null) {
            return false;
        }

        LinkedList<Edge<E, V>> edges = vo.getEgdes();

        Iterator<Edge<E, V>> l = edges.iterator();

        while (l.hasNext()) {
            Edge<E, V> e = l.next();

            if (e.getDestino().equals(vd)) {
                l.remove();
                return true;
            }
        }

        return false;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof GraphLA)) {
            return false;
        }

        GraphLA<V, E> other = (GraphLA<V, E>) o;

        if (this.vertices.size() != other.vertices.size()) {
            return false;
        }

        Set<V> s1 = new HashSet<>();
        s1.addAll((Collection<V>) vertices);

        s1.removeAll((Collection<V>) other.vertices);
        if (!s1.isEmpty()) {
            return false;
        }

        for (Vertex<V, E> v : vertices) {
            Vertex<V, E> vOther = other.buscarVertice(v.getData());

            Set<Edge<E, V>> s2 = new HashSet<>();
            s2.addAll((Collection<Edge<E, V>>) v.getEgdes());

            s2.removeAll((Collection<Edge<E, V>>) vOther.getEgdes());
            if (!s2.isEmpty()) {
                return false;
            }
        }

        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 53 * hash + Objects.hashCode(this.vertices);
        hash = 53 * hash + (this.directed ? 1 : 0);
        return hash;
    }

}
