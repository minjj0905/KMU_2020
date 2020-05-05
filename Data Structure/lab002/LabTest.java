import java.util.*;

/**
 * Lab 002 
 * @version 1.0
 * @author Sanghwan Lee
 * @id 20181234
 */

class LabTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true) {
			System.err.println("Enter n r : ");
			int n = in.nextInt();
			int r = in.nextInt();
			if(n == 0) 
				break;

			System.out.println("Combination(" +  
				n + ", " + r + ") : " +
				Combi(n, r));
		}
	}
	static int Combi(int n, int r) {
		if (n==r || r==0) {
			return 1;
		} else {
			return Combi(n-1, r) + Combi(n-1, r-1);
		}

	}
}

