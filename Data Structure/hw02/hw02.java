import java.util.*;

// Name :
// Student ID :

@SuppressWarnings("unchecked")
class BST <T extends KeyValue> {

	class TreeNode <U extends KeyValue> {
		U data;	// storage for data : in HW 3, T will be Item
		TreeNode<U> leftChild;	// link to the left Child
		TreeNode<U> rightChild;	// link to the right Child

		// constructors come here
		TreeNode() {
			leftChild = rightChild = null;
		}
		TreeNode(U d) {
			// data is given
			data = d;
			// the leftChild and rightChild field are null
			leftChild = rightChild = null;
		}
	};

	TreeNode <T> root;// the reference to the root node

	BST() { 
		// BST constructor. 
		root = null;
	}

    void Show() {

		System.out.print( "Pre  Order : ");
		PreOrder(root);
		System.out.println("");
		System.out.print("In   Order : ");
		InOrder(root);
		System.out.println("");
		System.out.print("Post Order : ");
		PostOrder(root);
		System.out.println("");
		System.out.print("Count      : ");
		System.out.print( Count(root));
		System.out.println("");
		System.out.print("Height      : ");
		System.out.println( Height(root));
		System.out.println("");
	}


	// IMPLEMENT THE FOLLOWING FUNCTIONS

	boolean  Insert(T item)  {
		// first search the key
		if(root == null) {
			root = new TreeNode<T>(item);
			return true;
		}
		TreeNode<T> ptr, parent;
		
		parent = root;
		ptr = new TreeNode<T>(item);
		int k = item.GetKey();

		if(parent.data.GetKey() == k) {
			ptr.leftChild = parent.leftChild;
			ptr.rightChild = parent.rightChild;
			root = ptr;
			return false;
		}

		while(parent != null) {
			if(parent.data.GetKey() > k) {
				if(parent.leftChild == null) {
					parent.leftChild = ptr;
					return true;
				}
				else if(parent.leftChild.data.GetKey() == k) {
					ptr.leftChild = parent.leftChild.leftChild;
					ptr.rightChild = parent.leftChild.rightChild;
					parent.leftChild = ptr;
					return false;
				}
				parent = parent.leftChild;
			 }
			 else if(parent.data.GetKey() < k) {
				 if(parent.rightChild == null) {
					 parent.rightChild = ptr;
					 return true;
				 }
				 else if(parent.rightChild.data.GetKey() == k) {
					 ptr.leftChild = parent.rightChild.leftChild;
					 ptr.rightChild = parent.rightChild.rightChild;
					 parent.rightChild = ptr;
					 return false;
				 }
				 parent = parent.rightChild;
			 }
		}
		return true;
	}

	T Get(T item)  {
		// use the key field of item and find the node
		// do not use val field of item
		TreeNode<T> ptr;
		ptr = root;
		int k = item.GetKey();
		while(ptr != null){
			if(ptr.data.GetKey() == k) {
				break;
			}
			else if(ptr.data.GetKey() > k) {
				if(ptr.leftChild == null) {
					return null;
				}
				ptr = ptr.leftChild;
			}
			else {
				if(ptr.rightChild == null) {
					return null;
				}
				ptr = ptr.rightChild;
			}
		}
		return ptr.data;
	} 


	boolean Delete(T item)  {
		if(root == null)
			return false;	// non existing key
		
		TreeNode<T> ptr, parent, child;
		parent = root;
		ptr = root;
		child = null;
		int k = item.GetKey();

		while(parent != null) {
			if(parent.data.GetKey() > k) {
				if(parent.leftChild == null) return false;
				else if(parent.leftChild.data.GetKey() == k) {
					ptr = parent.leftChild;
					break;
				}
				parent = parent.leftChild;
			}
			else if(parent.data.GetKey() < k) {
				if(parent.rightChild == null) return false;
				else if(parent.rightChild.data.GetKey() == k) {
					ptr = parent.rightChild;
					break;
				}
				parent = parent.rightChild;
			}
			else {
				ptr = parent;
				break;
			}
		}

		if((ptr.leftChild == null) && (ptr.rightChild == null)) {
			if(parent.leftChild == ptr) parent.leftChild = null;
			else if(parent.rightChild == ptr) parent.rightChild = null;
			else root=null;
		}
		else if((ptr.leftChild == null) || (ptr.rightChild == null)) {
			if(ptr.leftChild != null) child = ptr.leftChild;
			else if(ptr.rightChild != null) child = ptr.rightChild;
			
			if(ptr != root) {
				if(parent.leftChild == ptr) parent.leftChild = child;
				else if(parent.rightChild == ptr) parent.rightChild = child;
			}
			else {
				root = child;
			}
		}
		else {
			TreeNode<T> p, r, temp;

			p = ptr;
			temp = p.rightChild;
			while(temp.leftChild != null) {
				p = temp;
				temp = temp.leftChild;
			}

			r = temp.rightChild;
			temp.leftChild = ptr.leftChild;
			temp.rightChild = ptr.rightChild;
			p.leftChild = r;

			if(parent.leftChild == ptr) parent.leftChild = temp;
			else if(parent.rightChild == ptr) parent.rightChild = temp;
			else root = temp;
		}
		return true;
	}

	void  PreOrder(TreeNode<T> t)  {
		if(t != null) {
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");
			if(t.leftChild != null) PreOrder(t.leftChild);
			if(t.rightChild != null) PreOrder(t.rightChild);
		}
	}

	void  InOrder(TreeNode<T> t)  {
		if(t != null) {
			if(t.leftChild != null) InOrder(t.leftChild);
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");
			if(t.rightChild != null) InOrder(t.rightChild);
		}
	}

	void  PostOrder(TreeNode<T> t)  {
		if(t != null) {
			if(t.leftChild != null) PostOrder(t.leftChild);
			if(t.rightChild != null) PostOrder(t.rightChild);
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");
		}
	}

	int  Count(TreeNode<T> t)  {
		int cnt = 0;

		if(t == null) {
			return cnt;
		}
		cnt++;
		
		if(t.leftChild != null) cnt += Count(t.leftChild);
		if(t.rightChild != null) cnt += Count(t.rightChild);
		
		return cnt;
	}

	int  Height(TreeNode<T> t)  {
		int cnt = 0;

		if(t == null) {
			return cnt;
		}
		cnt++;

		if(t.leftChild == null && t.rightChild == null) return cnt;
		else if(t.leftChild != null && t.rightChild != null) {
			cnt += Math.max(Height(t.leftChild), Height(t.rightChild));
		}
		else {
			if(t.leftChild != null) {
				cnt += Height(t.leftChild);
			}
			else {
				cnt += Height(t.rightChild);
			}
		}
		return cnt;
	}
}


