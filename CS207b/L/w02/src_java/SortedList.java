package CS207b.L.w02.src_java;

import java.util.ArrayList;

public class SortedList {
    private ArrayList<Integer> list;

    public SortedList(ArrayList<Integer> list) {
        this.list = new ArrayList<Integer>(list);
    }

    public ArrayList<Integer> getList() {
        return list;
    }

    public void selectionSort() {
        int n = list.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (list.get(j) < list.get(min_idx))
                    min_idx = j;
            int temp = list.get(min_idx);
            list.set(min_idx, list.get(i));
            list.set(i, temp);
        }
    }

    public void bubbleSort() {
        int n = list.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++)
                if (list.get(j) > list.get(j + 1)) {
                    int temp = list.get(j);
                    list.set(j, list.get(j + 1));
                    list.set(j + 1, temp);
                }
    }

    public void countingSort(int exp) {
        System.out.println("Counting Sort");
    }

    public void radixSort() {
        System.out.println("Radix Sort");
    }

    public void interchangeSort() {
        System.out.println("Interchange Sort");
    }
}
