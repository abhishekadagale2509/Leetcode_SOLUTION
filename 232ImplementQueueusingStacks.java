import java.util.Stack;

class MyQueue {
    Stack<Integer> inStack;
    Stack<Integer> outStack;

    public MyQueue() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    // Push element to back
    public void push(int x) {
        inStack.push(x);
    }

    // Remove element from front
    public int pop() {
        shiftStacks();
        return outStack.pop();
    }

    // Get front element
    public int peek() {
        shiftStacks();
        return outStack.peek();
    }

    // Check if empty
    public boolean empty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    // Helper function
    private void shiftStacks() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
    }
}
