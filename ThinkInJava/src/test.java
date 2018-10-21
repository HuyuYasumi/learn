import java.util.*;

public class test {
    public static void main(String[] args) {
        HashMap<String, Integer> staff = new HashMap<>();
        staff.put("144", 144);
        staff.put("567", 567);
        staff.put("157", 157);
        staff.put("456", 456);

        System.out.println(staff);

        staff.remove("567");

        staff.put("456", 456-2);

        System.out.println(staff.get("157"));

        staff.forEach((k, v) ->
            System.out.println("key = " + k + ", value = " + v));

        ArrayList<Integer> list = new ArrayList<>();
        list.add(0);
        list.add(0);
        list.add(0);
        list.get(2);
        for (int i : list) {
            System.out.print(i + " ");
        }
    }
}