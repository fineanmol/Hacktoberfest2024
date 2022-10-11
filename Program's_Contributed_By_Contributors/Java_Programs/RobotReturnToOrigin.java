// https://leetcode.com/problems/robot-return-to-origin/
package com.sharan;

public class RobotReturnToOrigin {
    public static void main(String[] args) {
    }
    static boolean judgeCircle(String moves) {
        int origin = 0;
        int stepsX = 0;
        int stepsY = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves.charAt(i) == 'U' ){
                stepsY += 1;
            }
            else if(moves.charAt(i) == 'R'){
                stepsX += 1;
            }
            else if(moves.charAt(i) == 'D'){
                stepsY -= 1;
            }
            else {
                stepsX -= 1;
            }
        }

        return (origin == stepsX) && (origin == stepsY);
    }
}
