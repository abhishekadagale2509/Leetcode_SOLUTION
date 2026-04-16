import java.util.Stack;

class MinStack {
    private Stack<Integer> st;
    private Stack<Integer> min;

    public MinStack() {
        st = new Stack<>();
        min = new Stack<>();
    }
    
    public void push(int val) {
        if (st.size() == 0 || val <= min.peek()) {
            min.push(val);
        }
        st.push(val);
    }
    
    public void pop() {
        int ele1 = st.pop();
        
        if (ele1 == min.peek()) {
            min.pop();
        }
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return min.peek();
    }
}






/*class MinStack {
    private Stack<Integer>st;
    private Stack<Integer>min;

    public MinStack() {
        st=new Stack<>();
        min=new Stack<>();
    }
    
    public void push(int val)
     {
        if(st.size()==0||min.peek()>val){
            min.push(val);
        }
        st.push(val);
    }
    
    public void pop() {
        int ele1=st.pop();
        int ele2=min.peek();
        if(ele1==ele2)
        {
            min.pop();

        }
        
    }
    
    public int top() {
        return st.peek();
        
    }
    
    public int getMin() {
        return min.peek();
        
    }
}*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */












/*import java.util.*;

class MinStack {
    Stack<Integer> stack;
    Stack<Integer> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        stack.push(val);
        
        // If minStack is empty or val is smaller, push val
        if (minStack.isEmpty() || val <= minStack.peek()) {
            minStack.push(val);
        } else {
            // Push current minimum again
            minStack.push(minStack.peek());
        }
    }
    
    public void pop() {
        stack.pop();
        minStack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}*/
