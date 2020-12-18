//
// Created by Genes on 2020/12/17.
//
// 包含min函数的栈

#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> Stack, StackMin;

    MinStack() = default;

    void push(int x) {
        Stack.push(x);
        if (StackMin.empty() || StackMin.top() >= x) {
            StackMin.push(x);
        } else if (StackMin.top() < x) {
            StackMin.push(StackMin.top());
        }
    }

    void pop() {
        StackMin.pop();
        Stack.pop();
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return StackMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */