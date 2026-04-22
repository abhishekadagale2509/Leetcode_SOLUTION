import java.util.Stack;

class MyQueue {
private Stack<Integer>main;
private Stack<Integer>helper;

public MyQueue()
{
    main=new Stack<>();
    helper=new Stack<>();

}
public void push(int x)
{
    while(main.size()>0)
    {
        helper.push(main.pop());


    }
    main.push(x);
    while(helper.size()>0)
    {
        main.push(helper.pop());


    }

}
public int pop()
{
    return main.pop();

}
public int peek()
{
    return main.peek();

}
public boolean empty()
{
    return main.size()==0;
}
}



/*import java.util.Stack;

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
}*/
