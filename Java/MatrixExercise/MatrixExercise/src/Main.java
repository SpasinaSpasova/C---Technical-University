import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws java.io.IOException {
        java.io.File file = new java.io.File("array.txt");
         if (file.exists()) {
             System.out.println("File already exists");
             System.exit(1);
             }
    {

        java.io.PrintWriter output = new java.io.PrintWriter(file);

        int[][][] arr = {
                {{98, 17, 54},
                { 14, 21, 1},
                {15,77,20}},
                {{ 5, 14, 21},
                {11, 15, 77},
                {18, 24, 81}},
                {{ 0, 11, 15},
                {30, 18, 24},
                {66, 70, 99}}
        };



        for (int[][] item:arr){
            for (int[] item1:item){
                for (int item2:item1){
                    output.print(" " + item2);
                }
            }
        }

        output.close();
    }
}}