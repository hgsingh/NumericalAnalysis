import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by harsukh on 2/29/16.
 */

public class StringRand {
    //random password generator
  //  private String[] array;
//    private Hashtable<Integer, String> hashtable;
//
//    public StringRand(int size)
//    {
//        hashtable = new Hashtable(size);
//    }
    //random array generation
    Random random = new Random();

    public int[] array_gen(int[] array_to_gen)
    {
        if(array_to_gen != null) {
            for (int i = 0; i < array_to_gen.length; ++i) {
                array_to_gen[i] = random.nextInt();
            }
            return array_to_gen;
        }
        return null;
    }


    /*
    *!!!!!!!!!!!!!!!!!!!!!
    * !!!!!!!!!!!!!!!!!!!!!
    *MERGE SORT STARTS HERE
    * !!!!!!!!!!!!!!!!!!!!!!!!
    * !!!!!!!!!!!!!!!!!!!!!!!!
     */
    public void merge_sort(int[] array_to_sort)
    {
        if(array_to_sort == null)
            return;
        if(array_to_sort.length == 1)
            return;
        merge_sorter(array_to_sort, 0, array_to_sort.length);
    }

    public void merge_sorter(int[] array_to_sort, int begin, int end)
    {
        if(end - begin < 2) //case for 0 and 1
        {
            return;
        }
        int middle = (begin + end)/2;
        merge_sorter(array_to_sort, begin, middle); //breaking down the array
        merge_sorter(array_to_sort, middle, end);
        int[] work_array = new int[end + 1]; //creation of the working array
        merge(array_to_sort, begin, end, middle, work_array);
        copy_array( work_array, array_to_sort, begin, end);
    }

    public void merge(int[] array_to_sort, int begin, int end, int middle, int[] work_array)
    {
        int i = begin;
        int j = middle;
        for(int k = begin; k<end; ++k)
        {
            if(i < middle && (array_to_sort[i] < array_to_sort[j]))
            {
                work_array[k] = array_to_sort[i];
                ++i;
            }
            else
            {
                work_array[k] = array_to_sort[j];
                ++j;
            }
        }
    }

 /*
    *!!!!!!!!!!!!!!!!!!!!!
    * !!!!!!!!!!!!!!!!!!!!!
    *MERGE SORT ENDS HERE
    * !!!!!!!!!!!!!!!!!!!!!!!!
    * !!!!!!!!!!!!!!!!!!!!!!!!
     */
    public void copy_array(int[] array_to_copy, int[] array_copy_to, int begin, int end)
    {
        for(int i= begin; i<end; ++i )
        {
            array_copy_to[i] = array_to_copy[i];
        }
    }

    public int[] dumb_ass_sort(int[] array_to_sort)
    {
        if(array_to_sort != null) {
            int length = array_to_sort.length;
            for (int i = 0; i < length; ++i) {
                for (int j = i; j < length; ++j)
                {
                    if(array_to_sort[i] > array_to_sort[j])
                    {
                        int[] list = in_order_swap(array_to_sort[i], array_to_sort[j]);
                        array_to_sort[i] = list[0];
                        array_to_sort[j] = list[1];
                    }
                }
            }
            return array_to_sort;
        }
        return null;
    }

    public int[] in_order_swap(int a, int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        int[] list= {a,b};
        return list;
    }

    //main for regex testing
//  public static void main( String args[] ){
//      String REGEX = "(&#[0-9a-z]*;)|(\n)";
//      String INPUT = "How &#8216;Red Sox vs. \n Yankees&#8217;explains Connecticut";
//      Pattern pattern = Pattern.compile(REGEX);
//      Matcher matcher = pattern.matcher(INPUT);
//      String new_string = matcher.replaceAll(" ");
//      System.out.println(new_string);
//      System.out.println("Current REGEX is: "+REGEX);
//      System.out.println("Current INPUT is: "+INPUT);
//      System.out.println("lookingAt(): "+matcher.lookingAt());
//      System.out.println("matches(): "+matcher.matches());
//  }

    public static void main(String args[])
    {
        int[] array_to_sort = new int[500];
        StringRand solution = new StringRand();
        solution.array_gen(array_to_sort);
        for(int i =0; i<array_to_sort.length; ++i)
        {
            System.out.print(array_to_sort[i] + ", ");
        }
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        int[] list_a = solution.dumb_ass_sort(array_to_sort);
        for(int i =0; i<array_to_sort.length; ++i)
        {
            System.out.print(list_a[i] +", ");
        }
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!--------------Mergesort starts here!----------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        System.out.println("!----------------------------------------------!");
        int[] test_merge = new int[500];
        solution.copy_array(array_to_sort, test_merge, 0, test_merge.length);
        solution.merge_sort(test_merge);
        for(int i =0; i<test_merge.length; ++i)
        {
            System.out.print(test_merge[i] + ", ");
        }
    }
}
