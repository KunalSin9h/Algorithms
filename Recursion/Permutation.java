import java.util.ArrayList;

public class Permutation {

    public static void print(ArrayList<Integer> A){
        for(int e: A)System.out.print(e);
        System.out.println();
    }

    static ArrayList<Integer> B = new ArrayList<Integer>();
    static ArrayList<Boolean> Used = new ArrayList<Boolean>(4);

    public static void Perm(ArrayList<Integer> A){
        if(B.size() == 4){
            print(B);
        }
        else{
            for(int i = 0; i < 4; ++i){

            }
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<Integer>();
        A.add(1);
        A.add(2);
        A.add(3);
        A.add(4);

        System.out.println(Used.size()); 

    }
}
