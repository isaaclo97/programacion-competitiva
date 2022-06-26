import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class die {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder(1000);
        String[] lines = new String[3];
        lines[0] = br.readLine();
        lines[1] = br.readLine();
        lines[2] = br.readLine();
        if (checkpos(lines, ":::", ":o:", ":::")){
            sb.append(1);
        }
        else if (checkpos(lines, "o::", ":::", "::o")){
            sb.append(2);
        }
        else if (checkpos(lines, "::o", ":::", "o::")){
            sb.append(2);
        }
        else if (checkpos(lines, "o::", ":o:", "::o")){
            sb.append(3);
        }
        else if (checkpos(lines, "::o", ":o:", "o::")){
            sb.append(3);
        }
        else if(checkpos(lines, "o:o", ":::", "o:o")){
            sb.append(4);
        }
        else if (checkpos(lines, "o:o", ":o:", "o:o")){
            sb.append(5);
        }
        else if (checkpos(lines,"ooo",":::","ooo")){
            sb.append(6);
        }
        else if (checkpos(lines,"o:o","o:o","o:o")){
            sb.append(6);
        } else {
            sb.append("unknown");
        }
        System.out.println(sb.toString());
    }
    
    public static boolean checkpos(String[] lines, String l1, String l2, String l3){
        boolean ret = true;
        ret = ret && lines[0].equals(l1);
        ret = ret && lines[1].equals(l2);
        ret = ret && lines[2].equals(l3);
        return ret;
    }
    
}
