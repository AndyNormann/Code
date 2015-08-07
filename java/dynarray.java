public class dynarray<T>{
    private Object[] array;
    private int size;

    dynarray(int size){
        array = new Object[size];
        size = 0;
    }
    dynarray(){
        array = new Object[20];
        size = 0;
    }

    void add(T element, int pos){
        array[pos] = element; 
    }
    void add(T element){
        if (size == array.length) {
            int[] new_array = new int[size*2];
            System.arraycopy(array, 0, new_array, 0, array.length);
        }
        array[size++] = element; 
    }
    T get(int pos){
        return (T)array[pos];
    }
    int size(){
        return size;
    }
}
