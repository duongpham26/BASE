package B2.easy.ValidParentheses;

import java.util.Stack;

public class Solution1 {
	public boolean checkDouble(char left, char right) {
		return (left == '{' && right == '}') || (left == '(' && right == ')') || (left == '[' && right == ']');
	}

	public boolean isValid(String s) {
		Stack<Character> stack = new Stack<Character>();

		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == '{' || c == '[' || c == '(') {
				stack.push(c);
			} else if (c == '}' || c == ')' || c == ']') {
				if (stack.isEmpty()) {
					return false;
				}
				char cLeft = stack.pop();
				if (!checkDouble(cLeft, c)) {
					return false;
				}
			} else {
				return false;
			}
		}

		return stack.isEmpty();
	}

	public static void main(String[] args) {
		Solution1 s = new Solution1();
		System.out.println(s.isValid("()[]{}"));
	}
}
