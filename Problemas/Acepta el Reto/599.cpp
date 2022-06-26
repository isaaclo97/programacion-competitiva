
import java.util.*;
import java.lang.*;
import java.io.*;

/**
 *
 * @author Isaac
 */
public class Main
{
	static int solve(int size, int n, int[] cintas, int[] value, int[][][] memo, int size1, int id, int size2){
	    if(size1>size || size2>size) return -0x3f3f3f; //si pasa del tamaño
	    if(n==id) return 0; //ultima cinta
	    int best = memo[size1][size2][id];
	    if(best!=-1) return best;
	    int v1 = solve(size,n,cintas,value,memo,size1+cintas[id],id+1,size2)+value[id];
	    int v2 = solve(size,n,cintas,value,memo,size1,id+1,size2+cintas[id])+value[id];
	    int v3 = solve(size,n,cintas,value,memo,size1,id+1,size2);
	    return memo[size1][size2][id] = Math.max(v1,Math.max(v2,v3));
	}

	public static void main (String[] args)
	{
        Scanner sc= new Scanner(System.in);
        while(sc.hasNext()){
            int n=sc.nextInt();
            if(n==0) break;
            int size=sc.nextInt();
            int cintas[] = new int[n];
			int value[] = new int[n];
			int memo[][][] = new int[size+1][size+1][n];
	        for(int i=0; i<n;i++) { cintas[i]=sc.nextInt(); value[i]=sc.nextInt(); }
	        for(int i=0; i<size+1;i++)
	            for(int j=0; j<size+1;j++)
	                for(int k=0; k<n;k++) memo[i][j][k]=-1;
            System.out.println(Math.max(0,solve(size,n,cintas,value,memo,0,0,0)));
        }
    }
}
