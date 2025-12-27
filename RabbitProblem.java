class RabbitProblem{
    public static String canStopRabbits(String s) {
        int n = s.length();
        if (s.contains("000")) {
            return "NO";
        }
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') { 
                boolean leftOpen =(i > 0 && s.charAt(i - 1) == '0');
                boolean rightOpen=(i < n - 1 && s.charAt(i + 1) == '0');
                if (leftOpen && rightOpen) 
                    return "NO";
            }
        }
        return "YES";
    }
    public static void main(String args[]){
    System.out.println("Test Case 1  " + canStopRabbits("0"));
    System.out.println("Test Case 2  " + canStopRabbits("10"));
    System.out.println("Test Case 3  " + canStopRabbits("01"));
    System.out.println("Test Case 4  " + canStopRabbits("00"));
    System.out.println("Test Case 5  " + canStopRabbits("000"));
    System.out.println("Test Case 6  " + canStopRabbits("001"));
    System.out.println("Test Case 7  " + canStopRabbits("100"));
    System.out.println("Test Case 8  " + canStopRabbits("010"));
    System.out.println("Test Case 9  " + canStopRabbits("0001"));
    System.out.println("Test Case 10 " + canStopRabbits("1000"));
    System.out.println("Test Case 11 " + canStopRabbits("0100"));
    System.out.println("Test Case 12 " + canStopRabbits("0010"));
    System.out.println("Test Case 13 " + canStopRabbits("0110"));
    System.out.println("Test Case 14 " + canStopRabbits("10101"));
    System.out.println("Test Case 15 " + canStopRabbits("00100"));
    }
}