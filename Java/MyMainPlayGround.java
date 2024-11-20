import java.util.*;

public class MyMainPlayGround {
    public static void main(String[] args) {
        int[] arr = {2,6,1,7,2,8,3,0,1};
        MergeSort.mergeSort(arr, 0, arr.length-1);
        System.out.println(BinarySearch.recBinarySearch(arr, 7, 0, arr.length-1));
    }
}

class BST{
    class Node{
        int data; Node left, right;
        Node(int val){
            data = val;
            left = right = null;
        }
    }
    Node root;
    BST(){
        root = null;
    }
    public void insert(int element){
        root = insertRec(root, element);
    }
    public Node insertRec(Node root, int element){
        if(root==null){
            root = new Node(element);
            return root;
        }
        if(element<root.data){
            root.left = insertRec(root.left, element);
        }else if(element>root.data){
            root.right = insertRec(root.right, element);
        }
        return root;
    }
    public int findMinRec(Node root){
        int minValue = root.data;
        while(root.left!=null){
            minValue = root.left.data;
            root = root.left;
        }
        return minValue;
    }
    public void delete(int element){
        root = deleteRec(root, element);
    }
    public Node deleteRec(Node root, int element){
        if(root==null){
            return null;
        }
        if(element<root.data){
            root.left = deleteRec(root.left, element);
        }else if(element>root.data){
            root.right = deleteRec(root.right, element);
        }else{
            if(root.left==null) return root.right;
            if(root.right==null) return root.left;

            root.data = findMinRec(root.right);
            root.right = deleteRec(root.right, root.data);
        }
        return root;
    }
    public void inorder(){
        inorderRec(root);
    }
    public void inorderRec(Node root){
        if(root==null) return;
        inorderRec(root.left);
        System.out.print(root.data+" ");
        inorderRec(root.right);
    }
    public int height(){
        return heightRec(root);
    }
    public int heightRec(Node root){
        if(root==null) return -1;
        int lh = heightRec(root.left);
        int rh = heightRec(root.right);
        return Math.max(lh, rh)+1;
    }
    public int findMaxRec(Node root){
        int val = root.data;
        while(root.right!=null){
            val = root.right.data;
            root = root.right;
        }
        return val;
    }
}

class BinarySearch{
    public static int binarySearch(int[] arr, int element){
        int n = arr.length;
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid]==element) return mid;
            else if(arr[mid]<element) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
    public static int recBinarySearch(int[] arr, int element, int left, int right){
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(arr[mid]==element) return mid;
        else if(arr[mid]<element) return recBinarySearch(arr, element, mid+1, right);
        else return recBinarySearch(arr, element, left, mid-1);
    }
}

class LinearSearch{
    public static int linearSearch(int[] arr, int element){
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if(arr[i]==element) return i;
        }
        return -1;
    }
    public static int recLinearSearch(int[] arr, int element, int i){
        if(i==arr.length) return -1;
        if(arr[i]==element) return i;
        else return recLinearSearch(arr, element, i+1);
    }
}

class InsertionSort{
    public static void insertionSort(int[] arr){
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}

class SelectionSort{
    public static void selectionSort(int[] arr){
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++) {
                if(arr[j]<arr[minIdx]){
                    minIdx = j;
                }
            }
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

class HeapSort{
    public static void heapSort(int[] arr){
        int n = arr.length;
        for(int i=n/2-1; i>=0; i--){
            heapify(arr, n, i);
        }
        for(int i=n-1; i>0; i--){
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr, i, 0);
        }
    }
    public static void heapify(int[] arr, int n, int i){
        int largest = i;
        int left = 2*i+1, right = 2*i+2;
        if(left<n && arr[left]>arr[largest]) largest = left;
        if(right<n && arr[right]>arr[largest]) largest = right;
        if(largest!=i){
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr, n, largest);
        }
    }
}

class QuickSort{
    public static void quickSort(int[] arr, int low, int high){
        if(low<high){
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }
    public static int partition(int[] arr, int low, int high){
        int pivot = arr[low];
        int left = low+1, right = high;
        while(left<=right){
            while(left<=right && arr[left]<=pivot) left++;
            while(left<=right && arr[right]>pivot) right--;
            if(left<right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[right];
        arr[right] = temp;
        return right;
    }
}

class MergeSort{
    public static void mergeSort(int[] arr, int low, int high){
        if(low<high){
            int mid = (low+high)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }
    public static void merge(int[] arr, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int[] leftArr = new int[n1], rightArr = new int[n2];
        for(int i=0; i<n1; i++) leftArr[i] = arr[low+i];
        for(int i=0; i<n2; i++) rightArr[i] = arr[mid+1+i];
        int i=0, j=0, k=low;
        while(i<n1 && j<n2){
            if(leftArr[i]<rightArr[j]){
                arr[k++] = leftArr[i++];
            }else arr[k++] = rightArr[j++];
        }
        while(i<n1) arr[k++] = leftArr[i++];
        while(j<n2) arr[k++] = rightArr[j++];
    }
}

//class BST{
//    class Node{
//        int data;
//        Node left, right;
//        Node(int data){
//            this.data = data;
//            left = right = null;
//        }
//    }
//    Node root;
//    BST(){
//        root = null;
//    }
//    public void insert(int value){
//        root = insertRec(root, value);
//    }
//    public Node insertRec(Node root, int value){
//        if(root==null){
//            root = new Node(value);
//            return root;
//        }
//        if(value<root.data){
//            root.left = insertRec(root.left, value);
//        }else root.left = insertRec(root.right, value);
//        return root;
//    }
//    public int findMinRec(Node root){
//        int mini = root.data;
//        while(root.left!=null){
//            mini = root.left.data;
//            root = root.left;
//        }
//        return mini;
//    }
//    public void delete(int value){
//        root = deleteRec(root, value);
//    }
//    public Node deleteRec(Node root, int value){
//        if(root==null){
//            return null;
//        }
//        if(value<root.data){
//            root.left = deleteRec(root.left, value);
//        }else if(value>root.data){
//            root.right = deleteRec(root.right, value);
//        }else{
//            if(root.left==null) return root.right;
//            else if(root.right==null) return root.left;
//            root.data = findMinRec(root.right);
//            root.right = deleteRec(root.right, root.data);
//        }
//        return root;
//    }
//    public int height(){
//        return heightRec(root);
//    }
//    public int heightRec(Node root){
//        if(root==null) return -1;
//        int lh = heightRec(root.left);
//        int rh = heightRec(root.right);
//        return Math.max(lh, rh)+1;
//    }
//    public void inorder(){
//        inorderRec(root);
//    }
//    public void inorderRec(Node root){
//        if(root==null) return;
//        inorderRec(root.left);
//        System.out.println(root.data);
//        inorderRec(root.right);
//    }
//}

class SinglyLL{
    class Node{
        int data; Node next;
        Node(int val){
            data = val;
            next = null;
        }
    }
    Node head;
    SinglyLL(){
        head = null;
    }
    public void insert(int value){
        Node newNode = new Node(value);
        if(head==null){
            head = newNode;
            return;
        }
        Node curr = head;
        while(curr.next!=null) curr = curr.next;
        curr.next = newNode;
    }
    public void delete(int value){
        if(head==null) return;
        if(head.data==value){
            head = head.next;
            return;
        }
        Node curr = head, prev = null;
        while(curr.next!=null && curr.data!=value){
            prev = curr;
            curr = curr.next;
        }
        if(curr.data==value) prev.next = curr.next;
    }
    public void display(){
        Node curr = head;
        while(curr!=null){
            System.out.print(curr.data+" ");
            curr = curr.next;
        }
        System.out.println();
    }
}

class PostfixEvaluation{
    public static int postfixEvaluation(String s){
        Stack<Integer> stk = new Stack<>();
        for(char ch: s.toCharArray()){
            if(Character.isDigit(ch)){
                stk.push(ch-'0');
            }else{
                int b = stk.pop();
                int a = stk.pop();
                if(ch=='+') stk.push(a+b);
                else if(ch=='-') stk.push(a-b);
                else if(ch=='*') stk.push(a*b);
                else stk.push(a/b);
            }
        }
        return stk.pop();
    }
}

class InfixToPostfix{
    public static int precedence(char ch){
        switch (ch){
            case '+': case '-' : return 1;
            case '*': case '/' : return 2;
            case '^': return 3;
            default: return 0;
        }
    }
    public static String infixToPostfix(String s){
        StringBuilder ans = new StringBuilder();
        Stack<Character> stk = new Stack<>();
        for(char ch: s.toCharArray()){
            if(Character.isLetterOrDigit(ch)){
                ans.append(ch);
            }else if(ch=='('){
                stk.push(ch);
            }else if(ch==')'){
                while(!stk.isEmpty() && stk.peek()!='('){
                    ans.append(stk.pop());
                }
                stk.pop();
            }else{
                while(!stk.isEmpty() && precedence(ch)<=precedence(stk.peek())){
                    ans.append(stk.pop());
                }
                stk.push(ch);
            }
        }
        while(!stk.isEmpty()) ans.append(stk.pop());
        return ans.toString();
    }
}

class QueueWithLL{
    class Node{
        int data; Node next;
        Node(int val){
            data = val; next = null;
        }
    }
}

class StackWithLL{
    class Node{
        int data; Node next;
        Node(int val){
            data = val;
            next = null;
        }
    }
    Node head; int count;
    StackWithLL(){
        head = null; count = 0;
    }
    public void push(int val){
        Node newNode = new Node(val);
        count++;
        newNode.next = head;
        head = newNode;
    }
    public int pop(){
        if(isEmpty()){
            System.out.println("Stack is Empty");
            return -1;
        }
        count--;
        int temp = head.data;
        head = head.next;
        return temp;
    }
    public int peek(){
        return head.data;
    }
    public boolean isEmpty(){
        return head==null;
    }
    public void display(){
        Node curr = head;
        while(curr!=null){
            System.out.print(curr.data+" ");
            curr = curr.next;
        }
        System.out.println();
    }
}

class QueueWithArray{
    int front, rear, n, count;
    int[] queueArr;
    QueueWithArray(int size){
        n = size; count = 0;
        queueArr = new int[n];
        front = 0; rear = -1;
    }
    public void enqueue(int value){
        if(isFull()){
            System.out.println("Queue is full.");
            return;
        }
        count++;
        rear = (rear+1)%n;
        queueArr[rear] = value;
    }
    public int dequeue(){
        if(isEmpty()){
            System.out.println("Queue is empty.");
            return -1;
        }
        count--;
        int temp = queueArr[front];
        front = (front+1)%n;
        return temp;
    }
    public void display(){
        for(int i=0; i<count; i++){
            System.out.print(queueArr[(front+i)%n]+" ");
        }
        System.out.println();
    }
    public boolean isFull(){
        return count==n;
    }
    public boolean isEmpty(){
        return count==0;
    }
}

class StackWithArray{
    int n;
    int[] stkArr;
    int top;
    StackWithArray(int size){
        n = size;
        stkArr = new int[n];
        top = -1;
    }
    public void push(int element){
        if(isFull()){
            System.out.println("Stack is Full");
            return;
        }
        top++;
        stkArr[top] = element;
    }
    public int pop(){
        if(isEmpty()){
            System.out.println("Stack is Empty");
            return -1;
        }
        return stkArr[top--];
    }
    public boolean isFull(){
        return top==n-1;
    }
    public boolean isEmpty(){
        return top==-1;
    }
    public void display(){
        for(int i=top; i>=0; i--) System.out.print(stkArr[i]+" ");
        System.out.println();
    }
}