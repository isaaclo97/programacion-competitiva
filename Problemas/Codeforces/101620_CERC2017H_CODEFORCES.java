import java.util.*;

public class Main {

    public static final StringBuilder sb = new StringBuilder(10000);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = new Node(0);
        int lines = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < lines; i++) {
            String line = sc.nextLine();
            String[] temp = line.split(" ");
            int fileSize = Integer.parseInt(temp[1]);
            String[] folders = temp[0].split("/");
            root.add(folders, 1, fileSize);
        }
        int limit = sc.nextInt();
        root.calculateSize();
        root.recursivePrint("", limit);
        System.out.print(sb.toString());
    }

    static class Node {
        long size;
        long accumulatedSize = -1;
        boolean hasFolder = false;

        public Node(long size) {
            this.size = size;
        }

        Map<String, Node> children = new HashMap<>();

        public void add(String[] array, int position, int size){
            if(array.length - 1 == position){
                this.children.put(array[position], new Node(size));
            } else {
                if(!this.children.containsKey(array[position])){
                    this.children.put(array[position], new Node(0));
                }
                this.hasFolder = true;
                this.children.get(array[position]).add(array, position+1, size);
            }
        }

        public long calculateSize(){
            if(this.accumulatedSize == -1){
                this.accumulatedSize = this.children.size() == 0 ? this.size: this.children.entrySet().stream().map(Map.Entry::getValue).mapToLong(Node::calculateSize).reduce(0, (a,b) -> a+b);
            }
            return this.accumulatedSize;
        }

        public void recursivePrint(String path, int limit){
            if(this.children.size() == 0) return;
            boolean expandIt = hasFolder && this.children.entrySet().stream().map(Map.Entry::getValue).anyMatch(e -> !e.children.isEmpty() && e.accumulatedSize >= limit);
            if(expandIt){
                sb.append("- ");
            }
            else if(hasFolder) {
                sb.append("+ ");
            }
            else {
                sb.append("  ");
            }
            sb.append(path).append('/').append(' ').append(accumulatedSize).append('\n');

            if(expandIt){
                this.children.entrySet().stream().sorted(Comparator.comparing(Map.Entry::getKey)).forEach((e) -> e.getValue().recursivePrint(path + '/' + e.getKey(), limit));
            }
        }
    }
}