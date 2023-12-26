package CS207b.L.w02.src_java;

import java.util.ArrayList;
import java.util.Arrays;

public class main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>(Arrays.asList(5, 2, 4, 3, 1));

        SortedList sortedList = new SortedList(list);
        sortedList.selectionSort();
        System.out.println(sortedList.getList());

        sortedList.bubbleSort();
        System.out.println(sortedList.getList());

        System.out.println(sortedList.maxValue());
        sortedList.countingSort(1);
        System.out.println(sortedList.getList());
    }
}
