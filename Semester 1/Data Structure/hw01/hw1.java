import java.util.*;

class Expression {

	public static String toString(Stack<String> s) {
		String ans = "";
		String tmp = "";
		Stack<String> temp = s;
		while(temp.empty() == false) {
			String t = temp.pop() + " ";
			tmp = ans;
			ans = t;
			ans += tmp;
		}
		return ans;
	}

	public static boolean isNumber(String s) {
        try {
            Double.parseDouble(s);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static double Cal(String s) {
		String[] arr = s.split("  ");
		Stack<Double> stack = new Stack<>();
		for(int i=0; i<arr.length; i++) {
			if(isNumber(arr[i])) {
				stack.push(Double.parseDouble(arr[i]));
			}else {
				double num1 = 0, num2 = 0;
				num2 = stack.pop();
				num1 = stack.pop();
				switch(arr[i]) {
					case "*":
						stack.push(num1*num2);
						break;
					case "/":
						stack.push(num1/num2);
						break;
					case "-":
						stack.push(num1-num2);
						break;
					case "+":
						stack.push(num1+num2);
						break;
				}
			}
		}
		return stack.pop();
	}

	static double Eval(Vector<String> infix) throws Exception {
		Stack<String> stack = new Stack<>();
		String postfix = "";
		for(int i=0; i<infix.size(); i++){
			String s = infix.elementAt(i);
			System.out.println("Token : " + s);
			if(isNumber(s)) {
				postfix += s + "  ";
			} else {
				switch(s) {
					case "(":
						stack.push(s);
						break;
					case "*":
					case "/":
						while(true) {
							if(stack.isEmpty()) {
								stack.push(s);
								break;
							}else if(stack.peek().equals("(")) {
								stack.push(s);
								break;
							}else if(stack.peek().equals("*") || stack.peek().equals("/")) {
								postfix += stack.pop() + "  ";
								stack.push(s);
								break;
							}else {
								stack.push(s);
								break;
							}
						}
						break;
					case "+": case "-":
						while(true) {
							if(stack.isEmpty()) {
								stack.push(s);
								break;
							}else if(stack.peek().equals("(")) {
								stack.push(s);
								break;
							}else {
								postfix += stack.pop() + "  ";
							}
						}
						break;
					case ")":
						while(true) {
							if(stack.peek().equals("(")) {
								stack.pop();
								break;
							}else if(stack.isEmpty()) {
								break;
							}else {
								postfix += stack.pop() + "  ";
							}
						}
						break;
				}
			}
			System.out.println("Stack : " + toString(stack));
		}

		while(true) {
			if(stack.empty()){
				break;
			}else {
				postfix += stack.pop() + "  ";
			}
		}
		postfix = postfix.trim();
		System.out.println("Postfix expression : [" + postfix + "]");


		return Cal(postfix);
	}
}



