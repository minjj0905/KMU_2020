import java.util.*;

import javafx.geometry.Pos;

import java.lang.reflect.*;

/**
 * Generic version of the MinHeap class.
 * @param <T> the type of the value being added
 */

class MinHeap <T extends Comparable> {
	private T[] heapArray;
	private int heapSize;	// number of heap elements

	/**
	 * Create an empty MinHeap of size capacity
	 */
	MinHeap(Class<T> elemType, int capacity) {
		heapArray = (T []) Array.newInstance(elemType, capacity);
		heapSize = 0;
	}


	/**
	 * Insert item into the MinHeap
	 */
	void Insert (T item) { 
		if(heapSize == 0) {
			heapArray[1] = item;
			heapSize++;
		} else {
			heapSize++;
			int cur = heapSize;
			heapArray[cur] = item;
			int parent = heapSize/2;
			while(true) {
				if(heapArray[parent].compareTo(item) > 0) {
					T temp = heapArray[parent];
					heapArray[parent] = item;
					heapArray[cur] = temp;
					if(parent==1) break;
					cur = parent;
					parent /= 2;
				}else{
					break;
				}
			}
		}
	}

	void PostOrder (final int idx) { 
		if(idx*2 <= heapSize) PostOrder(idx*2);
		if(idx*2+1 <= heapSize) PostOrder(idx*2 +1);
		System.out.print(heapArray[idx] + " ");
	}


	public String toString() {
		String a = new String();
        a = "Min Heap : - ";
        for(int i = 1; i <= heapSize; i++) {
            a += heapArray[i] + "  ";
        }
        return a;
    }
}; 




