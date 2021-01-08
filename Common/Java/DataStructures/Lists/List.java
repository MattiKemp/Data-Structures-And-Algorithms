/**
 * This is a simple implementation of a dynamic list data-structure.
 * Dynamic lists allow for a list of pratically any size (less than 32 bit Integer limit) 
 * while maintaing O(1) (amortized) add and remove, and O(n) space complexity.
 * It overcomes the limitations of arrays by dyanmically changing the size of the array
 * the data is being stored in by doubling the size when more room is need or halving
 * the size when room isn't needed.
 * Ex: Down below our array is initalized with a size of 8, this default size is arbitrary, 
 * when more than 8 elements are added a new array is created that is twice the size of the
 * current one. The original array data is copied over and the new array is set as the main
 * array. This means at any momement only O(2*n) memory is used to represent the list.
 * The opposite occurs when removing, let's say that our array is of size 16, but only stores
 * 9 elements and one is removed, a new array is created of half size (8) and the original
 * array data is copied over, this new array is then set as the main array.
 *
 * The worst case for the add and remove methods are O(n), when doubling and halving, but
 * this hypothetically only occurs 32 times at most (if we are only adding or subtracting), so
 * it is said that these methods are O(1) amortized. 
 */
public class List{
    private Object[] arr;
    private int spot;
    public List(){
        arr = new Object[8];
        spot = 0;
    }
    public int getSize(){
        return arr.length;
    }
    public void add(Object obj){
        if(spot == arr.length){
            Object[] temp = new Object[arr.length*2];
            for(int i = 0; i < arr.length; i++)
                temp[i] = arr[i];
            temp[spot] = obj;
            arr = temp;
        }
        else{
            arr[spot] = obj;
        }
        spot++;
    }
    /**
     * Technically this is more of a 'pop' function rather than a 'remove' function
     * as we are removing the element with the highest index, not any element
     */
    public void remove(){
        spot--;
        if(spot != arr.length/2){
            arr[spot] = null;
        }
        else{
            Object[] temp = new Object[arr.length/2];
            for(int i = 0; i < arr.length/2; i++)
                temp[i] = arr[i];
            arr = temp;
        }
    }
    public void set(int index, Object obj){
        if(index >= 0 && index < spot)
            arr[index] = obj;
    }
    public void print(){
        System.out.print("[");
        for(int i = 0; i < spot; i++){
            if(arr[i]!=null)
                System.out.print(arr[i]+",");
            else
                System.out.print("null,");
        }
        System.out.print("]");
        System.out.println();
    }
    public static void main(String[] args){
        List test = new List();
        test.print();
        System.out.println("Size: " + test.getSize());
        //Testing add method
        System.out.println("Testing add method");
        test.add(6);
        test.print();
        System.out.println("Size: " + test.getSize());
        for(int i = 0; i < 8; i++)
            test.add(i);
        test.print();
        System.out.println("Size: " + test.getSize());
        //Testing remove method
        System.out.println("Testing remove method");
        test.remove();
        test.print();
        System.out.println("Size: " + test.getSize());
        //Testing set method
        System.out.println("Testing set method");
        test.set(0,2);
        test.print();
        test.set(-1,2);
        test.print();
        test.set(8,2);
        test.print();
    }
}

