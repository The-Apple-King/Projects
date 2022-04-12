//Owen Swearingen
//lab 11
public class BraceChecker {

    public static boolean checkBraces(String val) {
        //create stack
        GenericStack<String> stack = new GenericStack<>(3);

        //loops through all characters in the string
        for (int i = 0; i < val.length(); i++) {
            // tests for open parenthesis
            if (val.substring(i, i + 1).equals("(")) {
                stack.push("(");
            } else if (val.substring(i, i + 1).equals("[")) {
                stack.push("[");
            } else if (val.substring(i, i + 1).equals("{")) {
                stack.push("{");
            }

            // tests for closed parenthesis
            if (val.substring(i, i + 1).equals(")")) {
                if (stack.peek() != null && stack.peek().equals("(")) {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (val.substring(i, i + 1).equals("]")) {
                if (stack.peek() != null && stack.peek().equals("[")) {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (val.substring(i, i + 1).equals("}")) {
                if (stack.peek() != null && stack.peek().equals("{")) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        // check to make sure all parenthesis are closed
        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }

}
