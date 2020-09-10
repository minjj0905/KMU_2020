
import java.util.*;


class NaturalMerge {
	int noe;  // the number of elements
	private int[] inputArray; // input array 
	int[] outputArray; // output array 


	NaturalMerge() { 
		// Graph constructor. 
		noe = 0;
	}

	public String toString() {
		String str = new String();
		str = "Input : ";
		for(int i = 0; i < noe; i++) {
			str += inputArray[i] + " ";
		}
		str += "\nOutput : ";
		for(int i = 0; i < noe; i++) {
			str += outputArray[i] + " ";
		}
		return str;
	}

	void Init(int [] arr, int n) { 
		noe = n;
		inputArray = new int[noe];
		System.arraycopy(arr, 0, inputArray, 0, n);

		outputArray = new int[noe];
	}

	void Merge() { 
		int n = noe;
		System.out.print("noe = " + n);

		int r = 0;
		for (int i = 0; i<n; i++){
			if (inputArray[i] > inputArray[i+1]){
				r = i+1;
				System.out.println(", R = " + r);
				break;
			}
		}
		
		int left = 0;
		int right = r;
		int x = 0;

		while (right < n && left < r){
			if (inputArray[left]>inputArray[right]){
				outputArray[x++] = inputArray[right++];
				System.out.print("R ");
			}
			else {
				outputArray[x++] = inputArray[left++];
				System.out.print("L ");
			}
		}
		for (; left<r; left++){
			outputArray[x++] = inputArray[left];
		}
		for (; right<n; right++){
			outputArray[x++] = inputArray[right];
		}

		System.out.println();
	}
}







