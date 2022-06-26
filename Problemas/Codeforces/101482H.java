import java.util.*;
import java.util.stream.Collectors;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    private static Set<Integer> visitados = new HashSet<>();
    private static int next = 1;

    public static void main(String[] args) {
        int n = sc.nextInt();

        Node[] nodes = new Node[n+1];

        for (int i = 1; i < nodes.length; i++) {
            nodes[i] = new Node();
        }

        while(sc.hasNextInt()){
            int parent = sc.nextInt();
            int child = sc.nextInt();

            nodes[parent].children.add(child);
            nodes[child].children.add(parent);
        }

        assignFreq(nodes, 1, next++, next++);

        for (int i = 1; i < nodes.length; i++) {
//            if(nodes[i].freqA == -1 || nodes[i].freqB == -1){
//               while (true);
//            }
            System.out.println(nodes[i].freqA + " " + nodes[i].freqB);
        }
    }

    /**
     *
     * @param nodes
     * @param mFreq mandatory frecuency
     * @param vFreq voluntary frecuency
     */
    public static void assignFreq(Node[] nodes, int i, int mFreq, int vFreq){

        visitados.add(i);

        Node n = nodes[i];
        n.freqA = mFreq;
        List<Integer> children = n.children.stream().filter(e -> !visitados.contains(e)).collect(Collectors.toList());
        if(children.isEmpty()){
            n.freqB = vFreq;
        } else {
            n.freqB = next++;
            for (int i1 = 0; i1 < (children.size() + 1)/2; i1++) {
                int child = children.get(i1);
                assignFreq(nodes, child, n.freqB, n.freqA);
            }
            for (int i1 = (children.size() + 1)/2; i1 < children.size(); i1++) {
                int child = children.get(i1);
                assignFreq(nodes, child, n.freqA, n.freqB);
            }
        }
    }

    public static class Node {
        ArrayList<Integer> children = new ArrayList<>();
        int freqA = -1;
        int freqB = -1;
    }
}