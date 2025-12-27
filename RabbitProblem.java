/*
Problem: Rabbit Jump Prevention

We are given a line of pots represented by a binary string.
'1' means the pot has a flower.
'0' means the pot is empty and a rabbit is placed there.

Each rabbit can face either left or right.
A rabbit will jump if the pot in the facing direction is open.

A rabbit is STOPPED if:

it faces a boundary, or

it faces a flower.

Goal:
Check whether it is possible to assign directions to all rabbits
such that no rabbit jumps.

Key Rule:
If any rabbit has BOTH left and right adjacent pots open ('0'),
then that rabbit must jump and the arrangement is INVALID.

Return:
"YES" → arrangement is valid (no rabbit jumps)
"NO" → arrangement is invalid (at least one rabbit jumps)

Example:
"000" → NO (middle rabbit has both sides open)
"00100" → YES (each rabbit has at least one blocked side)
*/
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