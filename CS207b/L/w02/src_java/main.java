package CS207b.L.w02.src_java;

import java.util.ArrayList;
import java.util.Arrays;

public class main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>(Arrays.asList(5, 2, 4, 3, 1));

        SortedList sl = new SortedList(list);
        sl.selectionSort();
        System.out.println(sl.getList());

        sl.bubbleSort();
        System.out.println(sl.getList());
    }
}
