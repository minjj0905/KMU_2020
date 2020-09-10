import java.util.*;


class QuickSort {
    int[] arr; // array
	int arrSize;  // number of elements in arr

	QuickSort() { 
		arr = new int[1024];  
		arrSize = 0;
	}


	void Show(int s, int e) { 
		// Show all the element in the arr
		if(s > e)
			return ;
		String str = new String();
		str = "arr : ";

		// print all the nodes in the arr
		for(int i = 0; i < arrSize; i++) {
			if(i == s)
				str += "[";
			else
				str += " ";
			str += arr[i];
			if(i == e)
				str += "]";
			else
				str += " ";
		}
		System.out.println( str);
	}

	void  Init(int[] es, int n) {	
		// fill the arr array by the input
		arrSize = n;
		for(int i = 0; i < n; i++)
			arr[i] = es[i];
	}


	void  Sort() {
		// sort arr[0:arrSize-1] into nonincreasing order
		// This is an invoking method to the Partition() and QSort() 
		QSort(0, arrSize - 1);	// quick sort from 0 to n-1
	}



	void  QSort(int s, int e) {	
		// sort arr[s:e] into nonincreasing order
		System.out.println("Sort in [" + s + "," + e + "]");

		Show(s, e);

		if(s >= e){
			return;
		}
		
		int pv;

		int start = s;
		int i = e+1;
		int middle = (s + e)/2;
		
		int tmp;
		
		if (((arr[s] >= arr[e]) && (arr[s] <= arr[middle])) || ((arr[s] >= arr[middle]) && (arr[s] <= arr[e]))) {
			pv = arr[s];
		}
		else if (((arr[middle] >= arr[s]) && (arr[middle] <= arr[e])) || ((arr[middle] >= arr[e]) && (arr[middle] <= arr[s]))) {
			pv = arr[middle];
			tmp = arr[middle];
			arr[middle] = arr[s];
			arr[s] = tmp;
		}
		else {
			pv = arr[e];
			tmp = arr[e];
			arr[e] = arr[s];
			arr[s] = tmp;
		}



		while(i > start) {
			start++;
			i--;

			while(pv < arr[start]) {
				start++;
			}
			while(pv > arr[i]) {
				i--;
			}

			if (i > start) {
				tmp = arr[start];
				arr[start] = arr[i];
				arr[i] = tmp;
			}
		}


		tmp = arr[s];
		arr[s] = arr[i];
		arr[i] = tmp;


		QSort(s, i-1);
		QSort(i+1, e);

	}

}


